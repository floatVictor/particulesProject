#pragma once

#include <iostream>
#include <vector>
#include <p6/p6.h>

#include "worldVar.hpp"

#ifndef __PARTICULE__HPP
#define __PARTICULE__HPP

class Particule
{

private:
    // basic attributes
    glm::vec2 _pos;
    float _size = 0.001;
    float _angle; //[0;360]
    float _speed = 0.0015;

    // color attributes
    p6::Color _color;
    float _opacity;

    // lifeTime attributes
    bool _state = true;
    float _life;
    float _lifeIterator = sampleUniformContinuous(0.0005, 0.001); // how fast _life decrease

    // custom event attributes
    bool _noiseEventGo = false;
    bool _sizeEventGo = false;

    float _sizeEventSize = 0.002;

public:
    // constructors
    Particule();
    Particule(const glm::vec2 &pos, const float angle, Parameters p);

    // Basic functions
    void update(Parameters p);

    void displayParticule(p6::Context &ctx, Parameters p);

    void printParticule();

    // get functions
    bool getState();

    glm::vec2 getPos();

    // event functions
    void timedEvent(Parameters p);

    void noiseEvent(Parameters p);

    void sizeEvent(Parameters p);

    void markovEvent(float amp, float amp2);

    void speedEvent(Parameters p);
};

#endif
