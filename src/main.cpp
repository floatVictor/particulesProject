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
    
    srand(time(NULL));
    auto ctx = p6::Context{{1920,1080, "My p6 project"}}; // Create a context with a window
    ctx.background({0});
    ctx.framerate_as_high_as_possible();
    auto w = World(p);

    //----------------DRAW----------------//

    ctx.update = [&]() {

        if(w.getState(p)){
            w.loopWorld(ctx, p);
        }
        else std::cout << "end" << std::endl;

        p.FRAMECOUNT++;
    };

    ctx.imgui = [&](){
        ImGui::Begin("Framerate");
        ImGui::Text("%.2f", ctx.delta_time() * 1000.f);
        ImGui::End();
        ImGui::ShowDemoWindow();
    };

    ctx.start(); 
}
