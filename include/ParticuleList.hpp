#pragma once

#include <iostream>
#include <vector>
#include <p6/p6.h>

#include "Particule.hpp"

#ifndef __PARTICULELIST__HPP
#define __PARTICULELIST__HPP

class ParticuleList
{

private:
    // basic attributes
    glm::vec2 _initPos;
    int _nbParticules;
    std::vector<Particule> _tab;

    // lifeTime attributes
    int _nbAlive;
    bool _state = true;

public:
    // constructors
    ParticuleList();
    ParticuleList(const glm::vec2 initPos, const float angle, Parameters p);

    // basic functions
    void loopList(p6::Context &ctx, Parameters p);

    void display(p6::Context &ctx, Parameters p, Particule &p1, Particule &p2);

    // get functions
    int getNbAlive();

    bool getState();

    glm::vec2 getInitPos();

    Particule *getParticule(const int index);

    // utility functions
    void printList();

    void kill();
};

#endif