#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofBackground(0);
//    ofBackground(255);
    ofEnableAlphaBlending();

    

   
    pos1 = ofVec2f(ofRandom(ofGetWidth()),0);
    pos2 = ofVec2f(0, ofRandom(ofGetHeight()));
    pos3 = ofVec2f(ofRandom(ofGetWidth()),ofGetHeight());
    pos4 = ofVec2f(ofGetWidth(), ofRandom(ofGetHeight()));
    pos5 = ofVec2f(ofRandom(ofGetWidth()),0);
    pos6 = ofVec2f(0, ofRandom(ofGetHeight()));
    pos7 = ofVec2f(ofRandom(ofGetWidth()),ofGetHeight());
    pos8 = ofVec2f(ofGetWidth(), ofRandom(ofGetHeight()));
    
    a = 0;
    
    x1 = 6;
    y1 = 6;
    x2 = 6;
    y2 = 6;
    x3 = 6;
    y3 = 6;
    x4 = 6;
    y4 = 6;
    x5 = 4;
    y5 = 4;
    x6 = 4;
    y6 = 4;
    x7 = 4;
    y7 = 4;
    x8 = 4;
    y8 = 4;
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    pos1.x += x1;
    pos1.y += y1;
    pos2.x += x2;
    pos2.y += y2;
    pos3.x += x3;
    pos3.y -= y3;
    pos4.x += x4;
    pos4.y += y4;
    pos5.x += x5;
    pos5.y += y5;
    pos6.x += x6;
    pos6.y += y6;
    pos7.x += x7;
    pos7.y -= y7;
    pos8.x += x8;
    pos8.y += y8;
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 30);

    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    if (pos1.x > ofGetWidth()||pos1.x < 0) {
        x1 *= -1;
         color1 = ofColor::fromHsb(ofRandom(255), 50, 255);
    }
    if (pos2.x > ofGetWidth()||pos2.x < 0) {
         color1 = ofColor::fromHsb(ofRandom(255), 50, 255);
        x2 *= -1;
    }
    if (pos3.x > ofGetWidth()||pos3.x < 0) {
         color1 = ofColor::fromHsb(ofRandom(255), 50, 255);
        x3 *= -1;
    }
    if (pos4.x > ofGetWidth()||pos4.x < 0) {
         color1 = ofColor::fromHsb(ofRandom(255), 50, 255);
        x4 *= -1;
    }
    if (pos5.x > ofGetWidth()||pos5.x < 0) {
        color2 = ofColor::fromHsb(ofRandom(255), 255, 255);
        x5 *= -1;
    }
    if (pos6.x > ofGetWidth()||pos6.x < 0) {
        color2 = ofColor::fromHsb(ofRandom(255), 255, 255);
        x6 *= -1;
    }
    if (pos7.x > ofGetWidth()||pos7.x < 0) {
        color2 = ofColor::fromHsb(ofRandom(255), 255, 255);
        x7 *= -1;
    }
    if (pos8.x > ofGetWidth()||pos8.x < 0) {
        color2 = ofColor::fromHsb(ofRandom(255), 255, 255);
        x8 *= -1;
    }
    if (pos1.y == ofGetHeight()||pos1.y == 0) {
         color1 = ofColor::fromHsb(ofRandom(255), 50, 255);
        y1 *= -1;
    }
    if (pos2.y > ofGetHeight()||pos2.y < 0) {
         color1 = ofColor::fromHsb(ofRandom(255), 50, 255);
        y2 *= -1;
    }
    if (pos3.y == ofGetHeight()||pos3.y == 0) {
         color1 = ofColor::fromHsb(ofRandom(255), 50, 255);
        y3 *= -1;
    }
    if (pos4.y > ofGetHeight()||pos4.y < 0) {
         color1 = ofColor::fromHsb(ofRandom(255), 50, 255);
        y4 *= -1;
    }
    if (pos5.y == ofGetHeight()||pos5.y == 0) {
        color2 = ofColor::fromHsb(ofRandom(255), 255, 255);
        y5*= -1;
    }
    if (pos6.y > ofGetHeight()||pos6.y < 0) {
        color2 = ofColor::fromHsb(ofRandom(255), 255, 255);
        y6 *= -1;
    }
    if (pos7.y == ofGetHeight()||pos7.y == 0) {
        color2 = ofColor::fromHsb(ofRandom(255), 255, 255);
        y7 *= -1;
    }
    if (pos8.y > ofGetHeight()||pos8.y < 0) {
        color2 = ofColor::fromHsb(ofRandom(255), 255, 255);
        y8*= -1;
    }
    glLineWidth(5);
    ofSetColor(color1);
    ofDrawLine(pos1.x, pos1.y, pos2.x, pos2.y);
    ofDrawLine(pos2.x, pos2.y, pos3.x, pos3.y);
    ofDrawLine(pos3.x, pos3.y, pos4.x, pos4.y);
    ofDrawLine(pos4.x, pos4.y, pos1.x, pos1.y);
    glLineWidth(2);
    ofSetColor(color2);
    ofDrawLine(pos5.x, pos5.y, pos6.x, pos6.y);
    ofDrawLine(pos6.x, pos6.y, pos7.x, pos7.y);
    ofDrawLine(pos7.x, pos7.y, pos8.x, pos8.y);
    ofDrawLine(pos8.x, pos8.y, pos5.x, pos5.y);


    
   

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
