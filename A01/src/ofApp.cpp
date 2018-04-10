#include "ofApp.h"

float move_x;
float move_y;
float speed_x;
float speed_y;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    
    ofSetFrameRate(60);
    ofSetColor(30, 60, 255);
    //ofSetColor(25, 135, 233);
   // ofEnableAlphaBlending();
    
    ofSetCircleResolution(60);
    
    move_x = 200;
    move_y = 300;
    speed_x = 10;
    speed_y = 10;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    move_x += speed_x;
    move_y += speed_y;
    //下に
    if(move_y+150 > ofGetHeight()){
        speed_y *= -1;
        ofSetColor(255, 0, 255);
        
    }
    //上に
    if(move_y-150 < 0){
        speed_y *= -1;
        ofSetColor(255, 255, 0);
    }
    //左に
    if(move_x-150 < 0){
        speed_x *= -1;
        ofSetColor(0, 255, 255);
    }
    //右に
    if(move_x+150 > ofGetWidth()){
        ofSetColor(255, 255,255);
        speed_x *= -1;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofDrawCircle(move_x, move_y, 150);
    
    
    
    /*ofSetColor(30, 140, 230, 100);
    ofSetLineWidth(8);
    ofDrawLine(100, 100, 800, 600);
    
    ofSetColor(30, 130, 50,150);
    ofDrawRectangle(200, 300, 300, 300);
    
    ofSetColor(240, 200, 5, 125);
    ofDrawCircle(700, 200, 100);
    
    ofSetColor(210, 25, 20, 120);
    ofDrawTriangle(600, 600, 700, 400, 900, 700);*/

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
