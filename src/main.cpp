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



Parameters p = Parameters {};


int main() {

    //----------------SETUP---------------//
    
    auto ctx = p6::Context{{1920,1080, "Particules generator"}}; // Create a context with a window
    ctx.main_canvas_mode(p6::CanvasSizeMode_RelativeToWindow{2.f, 2.f});
    ctx.go_fullscreen();
    ctx.background({0});
    ctx.framerate_as_high_as_possible();
    auto w = World(p);

    //----------------DRAW----------------//

    ctx.update = [&]() {
        if(p.RESET){ 
            ctx.background({0});
            p.RESET = false;
        }

        if(p.SCREENSHOT){ 
            ctx.save_image("../../frameSave/frameSave_.jpeg");
            std::cout << "screenshot" << std::endl;
            p.SCREENSHOT = false;
        }

        if(p.BACKGROUND) ctx.background({0});

        w.loopWorld(ctx, p);
        p.FRAMECOUNT++;
        
        //noise extra event
        if(p.NOISE_BOOL_FX) {
            p.NOISE_SIZE += p.perlin.noise1D(p.FRAMECOUNT * p.NOISE_RATIO) * p.NOISE_AMP_FX;
            if(p.NOISE_SIZE < 0) p.NOISE_SIZE = 0;
            p.NOISE_RATIO += p.perlin.noise1D(p.FRAMECOUNT * p.NOISE_RATIO) * p.NOISE_AMP2_FX;
            if(p.NOISE_RATIO < 0) p.NOISE_RATIO = 0;
        }
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
            ImGui::Text("remaining particules : %d", w.getList().getNbAlive());
            ImGui::End();

            ImGui::Begin("- Particule parameters");
            ImGui::SliderFloat(": size (add)",&p.P_SIZE_ADD, -0.01, 0.01);
            ImGui::SliderFloat(": speed",&p.P_SPEED, 0, 0.01);
            ImGui::SliderFloat(": life (init)",&p.P_LIFE, 0.01, 3);
            ImGui::SliderFloat(": opacity",&p.P_OPACITY, 0.01, 1);
            ImGui::Checkbox("   display circle",  &p.P_SHAPE);

            ImGui::SliderFloat(": color_r",&p.P_COLOR_R, -1, 1);
            ImGui::SliderFloat(": color_g",&p.P_COLOR_G, -1, 1);
            ImGui::SliderFloat(": color_b",&p.P_COLOR_B, -1, 1);
            ImGui::End();

            ImGui::Begin("- Lines parameters");
            ImGui::Checkbox("   Display",  &p.LINE_BOOL);
            ImGui::SliderFloat(": size",&p.LINE_SIZE, 0.0001, 0.01);
            ImGui::SliderFloat(": opacity",&p.LINE_OPACITY, 0.01, 0.5);
            ImGui::SliderInt(": time",&p.LINE_TIME, 1, 20);
            ImGui::End();

            ImGui::Begin("- Global parameters");
            ImGui::SliderInt(": Particules number",&p.LIST_NBPARTICULE, 1, 100);
            if (ImGui::Button("Create new list (kill current)")) w.kill();
            if (ImGui::Button("Reset Canvas")) {
                p.RESET = true;
                w.kill();
            }
            if (ImGui::Button("Screenshot")) {
                p.SCREENSHOT = true;
            }
            ImGui::Checkbox("Display background",  &p.BACKGROUND);
            ImGui::End();

            ImGui::Begin("- Events parameters");
            ImGui::Checkbox("   Noise event",  &p.P_ACTIVE_NOISE_E);
            ImGui::SliderFloat(": ratio_n",&p.NOISE_RATIO, 3, 40);
            ImGui::SliderFloat(": size_n",&p.NOISE_SIZE, 0.001, 0.1);
            ImGui::SliderFloat(": amplitude_n",&p.NOISE_AMP, 0, 5);

            ImGui::Checkbox("   Angle event",  &p.P_ACTIVE_ANGLE_E);
            ImGui::SliderFloat(": angle_a",&p.P_TIME_ANGLE_E, 0, 360);
            ImGui::SliderInt(": time_a",&p.P_TIME_TIME_E, 20, 400);
            ImGui::SliderFloat(": luck_a(for each frame)",&p.P_TIME_LUCK_E, 0, 1);

            ImGui::Checkbox("   Size event",  &p.P_ACTIVE_SIZE_E);
            ImGui::SliderFloat(": amplitude_s",&p.P_SIZE_AMP_E, 0, 0.005);
            ImGui::SliderInt(": time_s",&p.P_SIZE_TIME_E, 20, 400);
            ImGui::SliderFloat(": luck_s (for each frame)",&p.P_SIZE_LUCK_E, 0, 100);
            ImGui::End();

            ImGui::Begin("- Extra events parameters");
            ImGui::Checkbox("   Noise extra event (global)",  &p.NOISE_BOOL_FX);
            ImGui::SliderFloat(": coef 1",&p.NOISE_AMP_FX, 0.0001, 0.01);
            ImGui::SliderFloat(": coef 2",&p.NOISE_AMP2_FX, 0.0001, 0.01);

            ImGui::Checkbox("   Markov extra event",  &p.P_ACTIVE_MARKOV_E);
            ImGui::SliderFloat(": coef 1",&p.P_MARKOV_COEF1_E, -0.02, 0.02);
            ImGui::SliderFloat(": coef 2",&p.P_MARKOV_COEF2_E, -0.02, 0.02);
            ImGui::End();
        }
    };

    ctx.start(); 
}