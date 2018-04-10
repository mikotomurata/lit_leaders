#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
   // ofSetColor(255, 175, 247);
    ofSetCircleResolution(60);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
   for(int i = 0;i<ofGetWidth()/5; i++){
        ofSetColor(255, 0, 0);
        ofDrawCircle(i*250,150, 100);
        }
    for(int i = 0;i<ofGetWidth()/5; i++){
        ofSetColor(255, 0, 0);
        ofDrawCircle(i*250,400, 100);
    }
    for(int i = 0;i<ofGetWidth()/5; i++){
        ofSetColor(255, 0, 0);
        ofDrawCircle(i*250,650, 100);
    }for(int i = 0;i<ofGetWidth()/5; i++){
        ofSetColor(255, 255, 255);
        ofDrawCircle(i*250+125,25, 85);
    }
    for(int i = 0;i<ofGetWidth()/5; i++){
        ofSetColor(255, 255, 255);
        ofDrawCircle(i*250+125,275, 85);
    }for(int i = 0;i<ofGetWidth()/5; i++){
        ofSetColor(255, 255, 255);
        ofDrawCircle(i*250+125,525, 85);
    }for(int i = 0;i<ofGetWidth()/5; i++){
        ofSetColor(255, 255, 255);
        ofDrawCircle(i*250+125,775, 85);
    }
    
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
