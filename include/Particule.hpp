#pragma once

#include <iostream>
#include <vector>
#include <p6/p6.h>

#include "worldVar.hpp"

#ifndef __PARTICULE__HPP
#define __PARTICULE__HPP

class Particule {

    private :

        glm::vec2 _pos;
        float _size = 0.001;
        float _angle; //0-360
        p6::Color _color;
        bool _state = true;
        float _life;
        float _lifeIterator = sampleUniformContinuous(0.0005, 0.001); //vitesse de viellissement

        bool _noiseEventGo = false;
        bool _sizeEventGo = false;
    
    public :

        Particule();
        Particule(const glm::vec2 &pos, const float angle, Parameters p);

        //Basic functions
        
        void update(Parameters p);

        void displayParticule(p6::Context &ctx, Parameters p);

        void printParticule();

        bool getState();

        //event functions
        void timedEvent(Parameters p);

        void noiseEvent(Parameters p);

        void sizeEvent(Parameters p);

        void markovEvent(float amp, float amp2);
};

#endif