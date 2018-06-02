
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
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f acc;
    float radius, friction, mass;
};
