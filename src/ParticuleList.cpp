#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iterator>
#include <p6/p6.h>

#include "Particule.hpp"
#include "ParticuleList.hpp"
#include "worldVar.hpp"
#include "mathProbabilitiesLib.hpp"

ParticuleList::ParticuleList(){};

ParticuleList::ParticuleList(const glm::vec2 initPos, const float angle, Parameters p){
    _initPos = initPos;
    _nbParticules = p.NBPARTICULE;

    for (int i = 0; i < _nbParticules; i++){
        _tab.push_back(Particule(initPos, angle, p));
    }
    std::cout << "new list created" << std::endl;
    std::cout << "initPos : " << _initPos[0] << ";" << _initPos[1] << std::endl
              << "nbParticules : " <<  _nbParticules << std::endl
              << "initAngle : "<< angle << std::endl;
}

void ParticuleList::loopList(p6::Context &ctx, Parameters p){
    Particule temp = _tab[0];

    for (Particule &par : _tab){
        if(p.LINE_BOOL) display(ctx, p, temp, par);
        par.update(p);
        par.displayParticule(ctx, p);
        temp = par;
    }
    if(p.LINE_BOOL) display(ctx, p, temp, _tab[0]);
}

void ParticuleList::display(p6::Context &ctx, Parameters p, Particule &p1, Particule &p2) {

    ctx.stroke = p6::Color{1 - p.perlin.noise1D(p.FRAMECOUNT * p.NOISE_SIZE * 0.5),1 - p.perlin.noise1D(p.FRAMECOUNT%53 * 0.01 * p.NOISE_SIZE), 1, p.LINE_OPACITY};
    ctx.stroke_weight = p.LINE_SIZE;

    if(p.FRAMECOUNT % p.LINE_TIME == 0) ctx.line(p1.getPos(), p2.getPos());
}

int ParticuleList::getNbAlive(){
    int temp = 0;
    for (Particule p : _tab){
        if (p.getState()) temp++;
    }
    _nbAlive = temp;
    return _nbAlive;
}

bool ParticuleList::getState(){
    if (getNbAlive() <= 0) {
        _state = false;
        std::cout << "list is dead" << std::endl;
    }
    return _state;
}

glm::vec2 ParticuleList::getInitPos() { return glm::vec2(_initPos[0], _initPos[1]);}

void ParticuleList::printList(){
    std::cout << "nbAlive : " << getNbAlive() << std::endl << std::endl;
}

void ParticuleList::kill() {_state = false;}

Particule *ParticuleList::getParticule(const int index){
    return &_tab[index];
}