#include <iostream>
#include <vector>
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>
#include <p6/p6.h>

#include "Particule.hpp"
#include "ParticuleList.hpp"
#include "World.hpp"
#include "worldVar.hpp"
#include "mathProbabilitiesLib.hpp"

// constructos

World::World(){};

World::World(Parameters p)
{

    _nbParticules = p.LIST_NBPARTICULE;
    _initAngle = p.LIST_INITANGLE;
    _current = ParticuleList(glm::vec2(0, 0), p.LIST_INITANGLE, p);
}

// loop function

void World::loopWorld(p6::Context &ctx, Parameters p)
{

    if (!_current.getState())
    {
        updateVar();
        _current = ParticuleList(_initPos, _initAngle, p);
    }

    _current.loopList(ctx, p);
}

// update functions

void World::updateVar()
{

    _initPos[0] = sampleUniformContinuous(-0.5, 0.5);
    _initPos[1] = sampleUniformContinuous(-0.5, 0.5);
    _initAngle = sampleUniformContinuous(0, 360);
}

void World::kill() { _current.kill(); }

ParticuleList World::getList() { return _current; }
