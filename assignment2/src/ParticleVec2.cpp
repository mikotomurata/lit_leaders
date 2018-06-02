
#include "ParticleVec2.hpp"

ParticleVec2::ParticleVec2(){
    radius = 5.0;
    friction = 0.01;
    mass1 = 2;
    mass2 = 3;
    pos1 = ofVec2f(ofRandom(ofGetWidth()), -20);
    pos2 = ofVec2f(ofRandom(ofGetWidth()), -20);
    vel1 = ofVec2f(0,0);
    vel2 = ofVec2f(0,0);
    a = 12;
    b = 8;
    c = 10;
}

void ParticleVec2::update(){
    acc1 -= vel1 * friction;
    acc2 -= vel2 * friction;
    vel1 += acc1;
    vel2 += acc2;
    pos1 += vel1;
    pos2 += vel2;
    acc1.set(0, 0);
    acc2.set(0, 0);
}

void ParticleVec2::draw(){
//    ofDrawCircle(pos1.x, pos1.y, radius);
    
    ofSetColor(255);
    if (pos1.y < ofGetHeight()) {
        for (int i = 0; i < 6; i++) {
            ofPushStyle();
            ofNoFill();
            ofPushMatrix();
            ofTranslate(pos1.x, pos1.y);
            ofRotateZ(60*i);
            ofDrawTriangle(0, 0, 1*a,-1*sqrt(3)*a, -1*a, -1*sqrt(3)*a);
            ofDrawTriangle(0, -2*sqrt(3)*a, 1*a,-1*sqrt(3)*a, -1*a, -1*sqrt(3)*a);
            ofPopMatrix();
            ofPopStyle();
        }
    }else{
        pos1 = ofVec2f(ofRandom(ofGetWidth()), -20);
        vel1 = ofVec2f(0,0);
    }
    
    
    //太枠
    if (pos2.y < ofGetHeight()) {
        for (int i = 0; i < 6; i++) {
            ofPushMatrix();
            ofTranslate(pos2.x, pos2.y);
            ofRotateZ(60*i);
            ofDrawTriangle(0, 0, 1*c,-1*sqrt(3)*c, -1*c, -1*sqrt(3)*c);
            ofDrawTriangle(0, -2*sqrt(3)*c, 1*c,-1*sqrt(3)*c, -1*c, -1*sqrt(3)*c);
            ofPopMatrix();
            
        }
        for (int i = 0; i < 6; i++) {
            ofPushMatrix();
            ofSetColor(0);
            ofTranslate(pos2.x, pos2.y);
            ofRotateZ(60*i);
            ofDrawTriangle(0, 0, 1*b,-1*sqrt(3)*b, -1*b, -1*sqrt(3)*b);
            ofDrawTriangle(0, -2*sqrt(3)*b, 1*b,-1*sqrt(3)*b, -1*b, -1*sqrt(3)*b);
            ofPopMatrix();
        }
    }else{
        pos2 = ofVec2f(ofRandom(ofGetWidth()), -20);
        vel2 = ofVec2f(0,0);
    }
    
}
void ParticleVec2::addForce(ofVec2f force){
    acc1 += force / mass1; //a = F/m
    acc2 += force / mass2;
    
}
void ParticleVec2::addForce(float forceX, float forceY){
    acc1 += ofVec2f(forceX,forceY) / mass1; //a = F/m
    acc2 += ofVec2f(forceX,forceY) / mass2;
}
