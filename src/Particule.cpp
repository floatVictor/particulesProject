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

    if(p.FRAMECOUNT % p.P_TIME_TIME_E == 0 || probabilityPercent(p.P_TIME_LUCK_E)) { 
        if(p.ACTIVE_ANGLE_E) timedEvent(p);
        _noiseEventGo = !_noiseEventGo;
    }

    if (_noiseEventGo && p.ACTIVE_NOISE_E) noiseEvent(p);

    if (p.FRAMECOUNT % p.P_SIZE_TIME_E == 0) {
        if (probabilityPercent(p.P_SIZE_LUCK_E)) {
            _sizeEventGo = !_sizeEventGo;
            if(p.ACTIVE_SIZE_E) sizeEvent(p);
        }
    }

    if(p.ACTIVE_MARKOV_E) markovEvent(p.P_MARKOV_COEF1_E, p.P_MARKOV_COEF2_E);

    // _noiseSize += p.perlin.noise1D(p.FRAMECOUNT * _noiseRatio) * 0.001;
    // _noiseRatio += p.perlin.noise1D(p.FRAMECOUNT * _noiseSize) * 0.001;
}

void Particule::displayParticule(p6::Context &ctx, Parameters p) {
    ctx.use_stroke = false;

    ctx.fill = p6::Color{1, 1, 1, float(_life * 0.25)};
    if (probabilityPercent(25)) ctx.fill = p6::Color{0, 0, p.perlin.noise1D(_life * p.NOISE_SIZE), float(_life * 0.18)};

    ctx.circle(p6::Center(_pos[0] + 2 * _size + p.P_SIZE_ADD, _pos[1]), _size + p.P_SIZE_ADD);
    ctx.fill = p6::Color{0, 0, 0, float(_life * 0.18)};

    ctx.use_fill = true;
    ctx.circle(p6::Center(_pos), _size + p.P_SIZE_ADD);
}

void Particule::printParticule() {
    std::cout << "POS : " << _pos[0] << ";" << _pos[1] << std::endl
              << "SIZE : " << _size
              << "| ANGLE : " << _angle << std::endl
              << "LIFE : " << _life << std::endl << std::endl;
}

bool Particule::getState(){return _state;}

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
    if (_sizeEventGo) _size += p.P_SIZE_AMP_E;
    else _size -= p.P_SIZE_AMP_E;
    if(p.perlin.noise3D(_pos[0] * p.NOISE_RATIO, _pos[1] * p.NOISE_RATIO, p.FRAMECOUNT * p.NOISE_SIZE) > 0) {
        if (p.perlin.noise3D(_pos[0] * p.NOISE_RATIO, _pos[1] * p.NOISE_RATIO, p.FRAMECOUNT * p.NOISE_SIZE + 10000) > 0) p.P_SIZE_AMP_E += p.P_SIZE_AMP_E;
        else p.P_SIZE_AMP_E -= p.P_SIZE_AMP_E;
    }
}

void Particule::markovEvent(float amp, float amp2) {

    _pos[0] += amp * (sampleBernoulli(abs(_pos[0]))) - amp/10;
    _pos[1] += amp2 * (sampleBernoulli(abs(_pos[1]))) - amp2/10;
}