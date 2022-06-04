#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <p6/p6.h>

#include "Particule.hpp"
#include "ParticuleList.hpp"
#include "PerlinNoise.hpp"
#include "World.hpp"
#include "worldVar.hpp"
#include "mathProbabilitiesLib.hpp"



Parameters p = Parameters{};


int main() {

    //----------------SETUP---------------//
    
    auto ctx = p6::Context{{1920,1080, "My p6 project"}}; // Create a context with a window
    ctx.background({0});
    ctx.framerate_as_high_as_possible();
    auto w = World(p);

    //----------------DRAW----------------//

    ctx.update = [&]() {

        w.loopWorld(ctx, p);
        p.FRAMECOUNT++;
    };

    //----------------UI------------------//

    ctx.imgui = [&](){
        ImGui::Begin("- Infos");
        ImGui::Text("framerate : %.2f", ctx.delta_time() * 1000.f);
        ImGui::End();
        ImGui::ShowDemoWindow();

        ImGui::Begin("- Particule parameters");
        ImGui::SliderFloat(": size",&p.P_SIZE_ADD, 0, 0.01);
        ImGui::SliderFloat(": speed",&p.P_SPEED, 0, 0.01);
        ImGui::SliderFloat(": life (init)",&p.P_LIFE, 1, 3);
        ImGui::End();

        ImGui::Begin("- List parameters");
        ImGui::SliderInt(": Particules number",&p.NBPARTICULE, 1, 100);
        if (ImGui::Button("Create new list (kill current)")) w.kill();
        ImGui::End();

        ImGui::Begin("- Event parameters");
        
        ImGui::Checkbox("   Noise event",  &p.ACTIVE_NOISE_E);
        ImGui::SliderFloat(": ratio_n",&p.NOISE_RATIO, 0.001, 0.1);
        ImGui::SliderFloat(": size_n",&p.NOISE_SIZE, 0.001, 0.1);
        ImGui::SliderFloat(": amplitude_n",&p.NOISE_AMP, 0, 3);

        ImGui::Checkbox("   Angle event",  &p.ACTIVE_ANGLE_E);
        ImGui::SliderFloat(": angle_a",&p.P_TIME_ANGLE_E, 0, 360);
        ImGui::SliderInt(": time_a",&p.P_TIME_TIME_E, 20, 400);
        ImGui::SliderFloat(": luck_a(for each frame)",&p.P_TIME_LUCK_E, 0, 1);

        ImGui::Checkbox("   Size event",  &p.ACTIVE_SIZE_E);
        ImGui::SliderFloat(": amplitude_s",&p.P_SIZE_AMP_E, 0, 0.005);
        ImGui::SliderInt(": time_s",&p.P_SIZE_TIME_E, 20, 400);
        ImGui::SliderFloat(": luck_s (for each frame)",&p.P_SIZE_LUCK_E, 0, 100);

        ImGui::Checkbox("   Markov event",  &p.ACTIVE_MARKOV_E);
        ImGui::SliderFloat("coef 1",&p.P_MARKOV_COEF1_E, -0.05, 0.05);
        ImGui::SliderFloat("coef 2",&p.P_MARKOV_COEF2_E, -0.05, 0.05);
        ImGui::End();
    };

    ctx.start(); 
}
/*struct Parameters {
bool ACTIVE_ANGLE_E = true;
    bool ACTIVE_NOISE_E = true;
    bool ACTIVE_TIME_E = true;
    bool ACTIVE_MARKOV_E = true;
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
    int NBPARTICULE = 40;
    float INITANGLE = float(rand());
    
    //noise values
    float NOISE_RATIO = 0.003;
    float NOISE_SIZE = 0.002;

};*/