#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <p6/p6.h>

#include "Particule.hpp"
#include "ParticuleList.hpp"
#include "World.hpp"
#include "worldVar.hpp"
#include "mathProbabilitiesLib.hpp"

World::World(Parameters p) {

    _initPos = _current.getInitPos();
    _nbParticule = p.NBPARTICULE;
    _initAngle = p.INITANGLE;
    _current = ParticuleList(glm::vec2(0,0), p.NBPARTICULE, p.INITANGLE, p);
}
        
void World::loopWorld(p6::Context &ctx,  Parameters p) {

    if(!_current.getState()){
        updateVar();
        _current = ParticuleList(_initPos, _nbParticule, _initAngle, p);
        _listIterator ++;
    }

    _current.loopList(ctx, p);
}

void World::updateVar() {

    _initPos[0] = sampleUniformContinuous(-0.5, 0.5);
    _initPos[1] = sampleUniformContinuous(-0.5, 0.5);
    _initAngle = sampleUniformContinuous(0, 360);
}

bool World::getState(Parameters p) { return _listIterator < p.NBLIST;}
