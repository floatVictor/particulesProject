#pragma once

#include <iostream>
#include <vector>
#include <p6/p6.h>

#include "ParticuleList.hpp"
#include "worldVar.hpp"

#ifndef __WORLD__HPP
#define __WORLD__HPP

class World {

    private :

        int _listIterator = 0;
        int _nbParticule;
        float _initAngle;

        glm::vec2 _initPos;

        ParticuleList _current;
        bool _state = true;

    public : 

        World(Parameters p);
        
        void loopWorld(p6::Context &ctx,  Parameters p);

        void createList();

        void updateVar();

        bool getState(Parameters p);

};

#endif