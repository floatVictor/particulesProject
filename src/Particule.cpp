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
    _noiseRatio = p.INITNOISERATIO;
    _noiseSize = p.INITNOISESIZE;
    if (sampleUniformContinuous(0, 100) > 50) _angle += 180;

    _size = p.P_SIZE;
    _speed = p.P_SPEED;
    _lifeIterator = p.P_LIFEINCREMENT;

    _timedEventAngle = p.P_TIME_ANGLE_E;
    _timedEventTime = p.P_TIME_TIME_E;
    _timedEventLuck = p.P_TIME_LUCK_E;

    _sizeEventSize = p.P_SIZE_AMP_E;
    _sizeEventTime = p.P_SIZE_TIME_E;
}

//Basic functions

void Particule::update(Parameters p) {

    _pos[0] += cos(glm::radians(_angle)) * _speed;
    _pos[1] += sin(glm::radians(_angle)) * _speed;

    _life -= _lifeIterator;
    if(_life < 0) _state = false;

    if(p.FRAMECOUNT % _timedEventTime == 0) { 
        timedEvent();
        _noiseEventGo = !_noiseEventGo;
    }

    else if (probabilityPercent(_timedEventLuck)) { 
        timedEvent();
        _noiseEventGo = !_noiseEventGo;
    }

    if (_noiseEventGo) noiseEvent(p);

    if (p.FRAMECOUNT % _sizeEventTime == 0) {
        if (probabilityPercent(_sizeEventLuck)) {
            _sizeEventGo = !_sizeEventGo;
            sizeEvent(p);
        }
    }

    _noiseSize += p.perlin.noise1D(p.FRAMECOUNT * _noiseRatio) * 0.001;
    _noiseRatio += p.perlin.noise1D(p.FRAMECOUNT * _noiseSize) * 0.001;
}

void Particule::displayParticule(p6::Context &ctx, Parameters p) {
    ctx.use_stroke = false;

    ctx.fill = p6::Color{1, 1, 1, float(_life * 0.25)};
    if (probabilityPercent(25)) ctx.fill = p6::Color{0, 0, p.perlin.noise1D(_life * _noiseSize), float(_life * 0.18)};

    ctx.circle(p6::Center(_pos[0] + 2 * _size, _pos[1]), _size);
    ctx.fill = p6::Color{0, 0, 0, float(_life * 0.18)};

    ctx.use_fill = true;
    ctx.circle(p6::Center(_pos), _size);
}

void Particule::printParticule() {
    std::cout << "POS : " << _pos[0] << ";" << _pos[1] << std::endl
              << "SIZE : " << _size
              << "| SPEED : " << _speed
              << "| ANGLE : " << _angle << std::endl
              << "LIFE : " << _life << std::endl << std::endl;
}

bool Particule::getState(){return _state;}

//Event functions

void Particule::timedEvent() {
    if(rand() % 100 < 76) _angle -= _timedEventAngle;
    _timedEventAngle = 180 - _timedEventAngle;
}

void Particule::noiseEvent(Parameters p) {
    _pos[0] += (p.perlin.noise3D(_pos[0], _pos[1], p.FRAMECOUNT * _noiseSize)) * _noiseRatio;
    _pos[1] += (p.perlin.noise3D(_pos[0], _pos[1], p.FRAMECOUNT * _noiseSize + 10000)) *_noiseRatio;
}

void Particule::sizeEvent(Parameters p) {
    if (_sizeEventGo) _size += _sizeEventSize;
    else _size -= _sizeEventSize;
    if(p.perlin.noise3D(_pos[0], _pos[1], p.FRAMECOUNT) *10> 0.6) {
        if (p.perlin.noise3D(_pos[0], _pos[1], p.FRAMECOUNT) *10 > 0) _sizeEventSize += _sizeEventSize;
        else _sizeEventSize -= _sizeEventSize;
    }
}

void Particule::markovEvent(float amp, float amp2) {

    _pos[0] += amp * (sampleBernoulli(abs(_pos[0]))) - amp/10;
    _pos[1] += amp2 * (sampleBernoulli(abs(_pos[1]))) - amp2/10;
}