
#include "ParticleVec2.hpp"

ParticleVec2::ParticleVec2(){
    radius = 5.0;
    friction = 0.01;
    mass = 5;
    pos = ofVec2f(ofGetWidth()/2, 0);
    vel = ofVec2f(0,0);
    
}

void ParticleVec2::update(){
    acc -= vel * friction;
    vel += acc;
    pos += vel;
    acc.set(0, 0);
}

void ParticleVec2::draw(){
    ofDrawCircle(pos.x, pos.y, radius);
    
}

void ParticleVec2::addForce(ofVec2f force){
    acc += force / mass; //a = F/m
    
}
void ParticleVec2::addForce(float forceX, float forceY){
    acc += ofVec2f(forceX,forceY) / mass; //a = F/m
}


