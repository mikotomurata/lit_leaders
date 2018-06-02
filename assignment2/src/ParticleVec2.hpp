#pragma once

#include "ofMain.h"

class ParticleVec2{
    
public:
    ParticleVec2();
    void update();
    void draw();
    
    //物体に力を与える（ベクトル版とX,Y版」）
    void addForce(ofVec2f force);
    void addForce(float forceX, float forceY);
    
    ofVec2f pos1, pos2;
    ofVec2f vel1, vel2;
    ofVec2f acc1, acc2;
    float radius, friction, mass1, mass2;
    int a, b, c;
};

