#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <p6/p6.h>

#include "PerlinNoise.hpp"
#include "mathProbabilitiesLib.hpp"

#ifndef WORLD_H
#define WORLD_H

struct Parameters {

    //particule values
    float P_SIZE_ADD = 0;
    float P_SPEED = 0.0015;
    float P_LIFE = 1; //vitesse de viellissement

        //-------event values [P_EVENTNAME_PARAMETER_E]
    float P_TIME_ANGLE_E = 120; //angle de la mutation périodique
    int P_TIME_TIME_E = 300;   //temps de la période
    float P_TIME_LUCK_E = 0.01; // X% chance to trig event (every frame)

    float P_SIZE_AMP_E = 0.002; //modulation sur la taille
    int P_SIZE_TIME_E = 120;
    float P_SIZE_LUCK_E= 80; // X% chance to trig event (every frame)

    float P_MARKOV_COEF1_E = 0.003;
    float P_MARKOV_COEF2_E = 0.001;

    bool ACTIVE_ANGLE_E = true;
    bool ACTIVE_NOISE_E = true;
    bool ACTIVE_SIZE_E = true;
    bool ACTIVE_MARKOV_E = false;

    //global values
    int FRAMECOUNT = 0;
    bool RESET = false;
    bool BACKGROUND = false;
    
    siv::PerlinNoise::seed_type seed = sampleUniformContinuous(0, 10000);;
    siv::PerlinNoise perlin{ seed };

    //list values
    int NBPARTICULE = 40;
    float INITANGLE = sampleUniformContinuous(0, 360);

    //noise values
    float NOISE_RATIO = 0.03;
    float NOISE_SIZE = 0.024;
    float NOISE_AMP = 3;

    //display lines
    bool LINE_BOOL = false;
    float LINE_SIZE = 0.001;
    float LINE_OPACITY = 0.1;
    int LINE_TIME = 10;

};

#endif