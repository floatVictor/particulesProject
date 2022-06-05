#pragma once

#include <iostream>
#include <vector>
#include <p6/p6.h>

#include "Particule.hpp"

#ifndef __PARTICULELIST__HPP
#define __PARTICULELIST__HPP

class ParticuleList {

    private :

        glm::vec2 _initPos;
        int _nbParticules;
        int _nbAlive;
        std::vector<Particule> _tab;
        bool _state = true;
        
    public :

        ParticuleList();
        ParticuleList(const glm::vec2 initPos, const float angle, Parameters p);

        void loopList(p6::Context &ctx,  Parameters p);

        void display(p6::Context &ctx, Parameters p, Particule &p1, Particule &p2);

        int getNbAlive();

        bool getState();

        glm::vec2 getInitPos();

        void printList();

        void kill();

        Particule *getParticule(const int index);
};   

#endif