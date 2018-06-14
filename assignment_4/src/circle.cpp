//
//  circle.cpp
//  assignment_4
//
//  Created by Mikoto Murata on 2018/06/14.
//

#include "circle.hpp"

//--------------------------------------------------------------
void circle::setup(){
    ofSetBackgroundAuto(false);
//    ofBackground(0);
    
    
    a = -2000;
    b = 0;
    
    
}
//--------------------------------------------------------------
void circle::update(){
    
    a += 2;
    b ++;
    
}
//--------------------------------------------------------------
void circle::draw(){
    ofSetColor(0, 30);
    
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    cam.begin();
    
    
    ofSetColor(255);

    for (int i = 0; i < 30; i++) {
        sphere[i].setPosition(50*cos(2*PI/30*i)+b,50*sin(2*PI/30*i), a);
        sphere[i].setRadius(5);
        sphere[i].draw();
    }
    
    
    cam.end();
}
//--------------------------------------------------------------
void circle::keyPressed(int key){
    
}

//--------------------------------------------------------------
void circle::keyReleased(int key){
    
}

//--------------------------------------------------------------
void circle::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void circle::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void circle::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void circle::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void circle::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void circle::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void circle::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void circle::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void circle::dragEvent(ofDragInfo dragInfo){
    
}

