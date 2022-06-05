#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <p6/p6.h>

#include "Particule.hpp"
#include "PerlinNoise.hpp"
#include "worldVar.hpp"
#include "mathProbabilitiesLib.hpp"

Particule::Particule(){};

Particule::Particule(const glm::vec2 &pos, const float angle, Parameters p) {
    _pos = pos;
    _angle = angle;
    if (sampleUniformContinuous(0, 100) > 50) _angle += 180;

    _life = p.P_LIFE;
}

//Basic functions

void Particule::update(Parameters p) {

    _pos[0] += cos(glm::radians(_angle)) * p.P_SPEED;
    _pos[1] += sin(glm::radians(_angle)) * p.P_SPEED;

    _life -= _lifeIterator;
    if(_life < 0) _state = false;
    
    if (_noiseEventGo && p.ACTIVE_NOISE_E) noiseEvent(p);

    if(p.FRAMECOUNT % p.P_TIME_TIME_E == 0 && p.FRAMECOUNT != 0) { 
        if(p.ACTIVE_ANGLE_E) timedEvent(p);
        _noiseEventGo = !_noiseEventGo;
    }

    if(probabilityPercent(p.P_TIME_LUCK_E) && p.ACTIVE_ANGLE_E) timedEvent(p);

    if (p.FRAMECOUNT % p.P_SIZE_TIME_E == 0) {
        if (probabilityPercent(p.P_SIZE_LUCK_E)) {
            _sizeEventGo = !_sizeEventGo;
            if(p.ACTIVE_SIZE_E) sizeEvent(p);
        }
    }

    if(p.ACTIVE_MARKOV_E) markovEvent(p.P_MARKOV_COEF1_E, p.P_MARKOV_COEF2_E);

    speedEvent(p);
}

void Particule::displayParticule(p6::Context &ctx, Parameters p) {
    ctx.use_stroke = false;
    ctx.use_fill = true;

    _opacity = p.perlin.noise3D(_pos[0] * p.NOISE_SIZE, _pos[1] * p.NOISE_SIZE, p.INITANGLE);

    ctx.fill = p6::Color{0, 0, 0, _opacity * .3};
    ctx.circle(p6::Center(_pos), _size + p.P_SIZE_ADD);

    ctx.fill = p6::Color{0, 0, p.perlin.noise1D(_life * p.NOISE_SIZE), _opacity * .3};
    if (probabilityPercent(35)) ctx.fill = p6::Color{1, 1, 1, _opacity * .5};
    ctx.circle(p6::Center(_pos[0] + 2 * _size + p.P_SIZE_ADD, _pos[1]), _size + p.P_SIZE_ADD);
    

}

void Particule::printParticule() {
    std::cout << "POS : " << _pos[0] << ";" << _pos[1] << std::endl
              << "SIZE : " << _size
              << "| ANGLE : " << _angle << std::endl
              << "LIFE : " << _life << std::endl << std::endl;
}

//get functions
bool Particule::getState(){return _state;}

glm::vec2 Particule::getPos(){return _pos;}

//Event functions

void Particule::timedEvent(Parameters p) {
    if(probabilityPercent(75)) _angle -= p.P_TIME_ANGLE_E;
    p.P_TIME_ANGLE_E = 180 - p.P_TIME_ANGLE_E;
}

void Particule::noiseEvent(Parameters p) {
    _pos[0] += (p.perlin.noise3D(_pos[0] * p.NOISE_RATIO, _pos[1] * p.NOISE_RATIO, p.FRAMECOUNT * p.NOISE_SIZE))  * (p.P_SPEED+ p.NOISE_AMP * 0.01);
    _pos[1] += (p.perlin.noise3D(_pos[0] * p.NOISE_RATIO, _pos[1] * p.NOISE_RATIO, p.FRAMECOUNT * p.NOISE_SIZE + 10000)) * (p.P_SPEED + p.NOISE_AMP * 0.01);
}

void Particule::sizeEvent(Parameters p) {
    if (_sizeEventGo) _size += _sizeEventSize;
    else _size -= _sizeEventSize;
    if(p.perlin.noise3D(_pos[0] * p.NOISE_RATIO, _pos[1] * p.NOISE_RATIO, p.FRAMECOUNT * p.NOISE_SIZE) > 0) {
        if (p.perlin.noise3D(_pos[0] * p.NOISE_RATIO, _pos[1] * p.NOISE_RATIO, p.FRAMECOUNT * p.NOISE_SIZE + 10000) > 0) _sizeEventSize += _sizeEventSize;
        else _sizeEventSize -= _sizeEventSize;
    }
    if(_size < 0.001) _size = 0.001;
}

void Particule::markovEvent(float amp, float amp2) {

    _pos[0] += amp * (sampleBernoulli(abs(_pos[0]))) - amp/10;
    _pos[1] += amp2 * (sampleBernoulli(abs(_pos[1]))) - amp2/10;
}

void Particule::speedEvent(Parameters p){
    _speed =+ p.perlin.noise3D(_pos[0] * p.NOISE_RATIO, _pos[1] * p.NOISE_RATIO, p.INITANGLE);
}