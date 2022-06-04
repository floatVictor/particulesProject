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
    float P_SIZE = 0.001;
    float P_SPEED = 0.0015;
    float P_LIFEINCREMENT = sampleUniformContinuous(0.0001, 0.001); //vitesse de viellissement

        //-------event values [P_EVENTNAME_PARAMETER_E]
    float P_TIME_ANGLE_E = 30; //angle de la mutation périodique
    int P_TIME_TIME_E = 300;   //temps de la période
    float P_TIME_LUCK_E = 0.01; // X% chance to trig event (every frame)

    float P_SIZE_AMP_E = 0.002; //modulation sur la taille
    int P_SIZE_TIME_E = 120;
    float P_SIZE_LUCK_E= 80; // X% chance to trig event (every frame)

    //global values
    int FRAMECOUNT = 0;
    
    siv::PerlinNoise::seed_type seed = sampleUniformContinuous(0, 10000);;
    siv::PerlinNoise perlin{ seed };

    //list values
    int NBLIST = 200;
    int NBPARTICULE = 40;
    float INITANGLE = float(rand());


    //noise values
    float INITNOISERATIO = 0.003;
    float INITNOISESIZE = 0.002;

    
    float HEIGHTRATIO = 0.00001;
    float INITSMOOTHRATIO = 0.00003;

};

#endif