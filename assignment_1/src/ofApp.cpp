#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    ofSetCircleResolution(60);
    radius1 = 0;
    radius2 = 0;
    radius3 = 0;
    x1 = 100;
    y1 = 200;
    x2 = 300;
    y2 = 400;
    x3 = 400;
    y3 = 500;
    
//    radius[0] = 0;
//    radius[1] = 0;
//    radius[2] = 0;
//    center[0].x = 100;
//    center[0].y = 200;
//    center[1].x = 200;
//    center[1].y = 300;
//    center[2].x = 400;
//    center[2].y = 500;
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
//    for (int i = 0; i < 3; i++) {
//        radius[i] += 1;
//    }
    radius1 += 3;
    radius2 += 1.5;
    radius3 += 3;
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    ofSetColor(255);
    ofNoFill();
    if (radius1 > 75){
        color1 = ofColor::fromHsb(ofRandom(255), 255,255);
        x1 = ofRandom(ofGetWidth());
        y1 = ofRandom(ofGetHeight());
        radius1 = 0;
    }
    if (radius2 > 175){
        color2 = ofColor::fromHsb(ofRandom(255), 255,255);
        x2 = ofRandom(ofGetWidth());
        y2 = ofRandom(ofGetHeight());
        radius2 = 0;
    }
    if (radius3 > 300){
        color3 = ofColor::fromHsb(ofRandom(255), 255,255);
        x3 = ofRandom(ofGetWidth());
        y3 = ofRandom(ofGetHeight());
        radius3 = 0;
    }
    
    if (0< radius1 && radius1 < 75) {
        ofSetColor(color1);
        ofDrawCircle(x1, y1, radius1);
    }
    if (radius2 < 175){
        ofSetColor(color2);
        ofDrawCircle(x2, y2, radius2);
    }
    if (radius3 < 400){
        ofSetColor(color3);
        ofDrawCircle(x3, y3, radius3);
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
