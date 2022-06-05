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
    ctx.maximize_window();
    ctx.background({0});
    ctx.framerate_as_high_as_possible();
    auto w = World(p);

    //----------------DRAW----------------//

    ctx.update = [&]() {
        if(p.RESET){ 
            ctx.background({0});
            p.RESET = false;
        }

        if(p.BACKGROUND) ctx.background({0});

        w.loopWorld(ctx, p);
        p.FRAMECOUNT++;
        
        // p.NOISE_SIZE += p.perlin.noise1D(p.FRAMECOUNT * p.NOISE_RATIO) * 0.001;
        // p.NOISE_RATIO += p.perlin.noise1D(p.FRAMECOUNT * p.NOISE_SIZE) * 0.001;
    };

    //----------------EVENT----------------//

    ctx.key_pressed = [](p6::Key k) {
        if(k.logical == "p") p.UI_DISPLAY = !p.UI_DISPLAY;
        std::cout << k.logical << std::endl;
    };
    //----------------UI------------------//

    ctx.imgui = [&](){
        if(p.UI_DISPLAY) {
            ImGui::Begin("- Infos");
            ImGui::Text("framerate : %.2f", 1.f / ctx.delta_time());
            ImGui::Text("frame count : %d", p.FRAMECOUNT);
            ImGui::End();
            ImGui::ShowDemoWindow();

            ImGui::Begin("- Particule parameters");
            ImGui::SliderFloat(": size (add)",&p.P_SIZE_ADD, -1, 1);
            ImGui::SliderFloat(": speed",&p.P_SPEED, 0, 0.01);
            ImGui::SliderFloat(": life (init)",&p.P_LIFE, 1, 3);
            ImGui::End();

            ImGui::Begin("- Lines parameters");
            ImGui::Checkbox("   Display",  &p.LINE_BOOL);
            ImGui::SliderFloat(": size",&p.LINE_SIZE, 0.0001, 0.01);
            ImGui::SliderFloat(": opacity",&p.LINE_OPACITY, 0, 0.5);
            ImGui::SliderInt(": time",&p.LINE_TIME, 1, 20);
            ImGui::End();

            ImGui::Begin("- Global parameters");
            ImGui::SliderInt(": Particules number",&p.NBPARTICULE, 1, 1000);
            if (ImGui::Button("Create new list (kill current)")) w.kill();
            if (ImGui::Button("Reset Canvas")) {
                p.RESET = true;
                w.kill();
            }
            ImGui::Checkbox("Display background",  &p.BACKGROUND);
            ImGui::End();

            ImGui::Begin("- Event parameters");
            
            ImGui::Checkbox("   Noise event",  &p.ACTIVE_NOISE_E);
            ImGui::SliderFloat(": ratio_n",&p.NOISE_RATIO, 0.001, 0.1);
            ImGui::SliderFloat(": size_n",&p.NOISE_SIZE, 0.001, 0.1);
            ImGui::SliderFloat(": amplitude_n",&p.NOISE_AMP, 0, 5);

            ImGui::Checkbox("   Angle event",  &p.ACTIVE_ANGLE_E);
            ImGui::SliderFloat(": angle_a",&p.P_TIME_ANGLE_E, 0, 360);
            ImGui::SliderInt(": time_a",&p.P_TIME_TIME_E, 20, 400);
            ImGui::SliderFloat(": luck_a(for each frame)",&p.P_TIME_LUCK_E, 0, 1);

            ImGui::Checkbox("   Size event",  &p.ACTIVE_SIZE_E);
            ImGui::SliderFloat(": amplitude_s",&p.P_SIZE_AMP_E, 0, 0.005);
            ImGui::SliderInt(": time_s",&p.P_SIZE_TIME_E, 20, 400);
            ImGui::SliderFloat(": luck_s (for each frame)",&p.P_SIZE_LUCK_E, 0, 100);

            ImGui::Checkbox("   Markov event",  &p.ACTIVE_MARKOV_E);
            ImGui::SliderFloat("coef 1",&p.P_MARKOV_COEF1_E, -0.02, 0.02);
            ImGui::SliderFloat("coef 2",&p.P_MARKOV_COEF2_E, -0.02, 0.02);
            ImGui::End();
        }
    };

    ctx.start(); 
}