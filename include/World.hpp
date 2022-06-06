#pragma once

#include <iostream>
#include <vector>
#include <p6/p6.h>

#include "ParticuleList.hpp"
#include "worldVar.hpp"

#ifndef __WORLD__HPP
#define __WORLD__HPP

class World
{

private:
    // basic attributes
    int _nbParticules;
    float _initAngle;
    glm::vec2 _initPos = glm::vec2(sampleUniformContinuous(-0.5, 0.5), sampleUniformContinuous(-0.5, 0.5));
    ParticuleList _current;
    bool _state = true;

public:
    // constructors
    World();
    World(Parameters p);

    // loop function
    void loopWorld(p6::Context &ctx, Parameters p);

    // update functions
    void createList();

    void updateVar();

    void kill();

    // get function
    ParticuleList getList();
};

#endif