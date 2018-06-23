#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    
    ofBackground(0);
    
    ofSetFrameRate(60);

}

//--------------------------------------------------------------
void ofApp::update(){
    a ++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    ofSetColor(0, 30);
    ofDrawRectangle(-1*ofGetWidth()/2, -1*ofGetHeight()/2, ofGetWidth(), ofGetHeight());
//    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    
    
    ofSetColor(255);
//    for(int i = 0;i < 20; i++){
//        ofDrawCircle(cos(PI/30*i)*100, sin(PI/30*i)*100, 2);
//    }
//    ofDrawCircle(cos(PI/30*ofGetFrameNum())*100, sin(PI/30*ofGetFrameNum())*100, 5);
    ofRotateZ(180);
    ofRotateY(180);
//    ofDrawCircle(50*8*sin(PI/30*ofGetFrameNum())*sin(PI/30*ofGetFrameNum())*sin(PI/30*ofGetFrameNum()), 50*6.5*cos(PI/30*ofGetFrameNum())-50*2.5*cos(2*(PI/30*ofGetFrameNum()))-50*cos(3*(PI/30*ofGetFrameNum()))-25*cos(4*(PI/30*ofGetFrameNum())), 5);
    //ハート
    ofDrawCircle(25*8*sin(PI/30*ofGetFrameNum()+PI)*sin(PI/30*ofGetFrameNum()+PI)*sin(PI/30*ofGetFrameNum()+PI), 25*6.5*cos(PI/30*ofGetFrameNum()+PI)-25*2.5*cos(2*(PI/30*ofGetFrameNum()+PI))-25*cos(3*(PI/30*ofGetFrameNum()+PI))-12.5*cos(4*(PI/30*ofGetFrameNum()+PI)), 5);
//    ofDrawCircle(50*cos(PI/30*ofGetFrameNum()), a, 5);

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
