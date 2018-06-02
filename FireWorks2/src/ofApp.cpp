#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundAuto(false);
    ofBackground(0, 0, 0);
    count = 0;
    start = 0;
    count_2 = 0;
    start_2 = 0;
    
    //light.enable();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    for (int i=start; i<fireworks_.size(); i++) {
        if(count>0){
            if(fireworks_[start]->alpha_1 == 0){
                delete fireworks_[start];
                start++;
            }
        }
    }
    for (int i=start_2; i<fireworks_2_.size(); i++) {
        if(count_2>0){
            if(fireworks_2_[start_2]->alpha_1 == 0){
                delete fireworks_2_[start_2];
                start_2++;
            }
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    for (int i=start; i < fireworks_.size(); i++) {
        if(count>0){
            fireworks_[i]->display();
        }
    }
    for (int i=start_2; i < fireworks_2_.size(); i++) {
        if(count_2>0){
            fireworks_2_[i]->display();
        }
    }
    
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 'a'){
        fireworks_.push_back(new FireWorks(ofVec3f(ofRandom(-ofGetWidth()/2,ofGetWidth()/2),-ofGetHeight()/2,0),(int)ofRandom(8),(int)ofRandom(7)));
        
        fireworks_[count]->setup();
        count++;
    }
    if(key == 's'){
        fireworks_2_.push_back(new FireWorks_2(ofVec3f(ofRandom(-ofGetWidth()/2,ofGetWidth()/2),-ofGetHeight()/2,0),(int)ofRandom(8),(int)ofRandom(7)));
        
        fireworks_2_[count_2]->setup();
        count_2++;
    }
    
    
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
