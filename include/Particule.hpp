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
        float _size;
        float _angle; //0-360
        float _speed;
        p6::Color _color;
        bool _state = true;
        float _life = 1;
        float _lifeIterator; //vitesse de viellissement

        float _timedEventAngle; //angle de la mutation périodique
        int _timedEventTime;   //temps de la période
        float _timedEventLuck; // X% chance to trig event (every frame)

        bool _noiseEventGo = false;
        float _noiseRatio; //noise amplitutde
        float _noiseSize;

        bool _sizeEventGo = false;
        float _sizeEventSize; //modulation sur la taille
        int _sizeEventTime;
        float _sizeEventLuck; // X% chance to trig event (every frame)
    
    public :

        Particule();
        Particule(const glm::vec2 &pos, const float angle, Parameters p);

        //Basic functions
        
        void update(Parameters p);

        void displayParticule(p6::Context &ctx, Parameters p);

        void printParticule();

        bool getState();

        //event functions
        void timedEvent();

        void noiseEvent(Parameters p);

        void sizeEvent(Parameters p);

        void markovEvent(float amp, float amp2);
};

#endif
