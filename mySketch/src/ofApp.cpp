#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(21,37,84);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    
    boxSize = 15;
    for(int i=0; i<NUM; i++){
        mBox[i].setPosition(ofRandom(-1000,1000), ofRandom(-1000,1000), ofRandom(-1000,1000));
        mBox[i].set(boxSize);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    ofSetColor(255, 230, 150, (ofGetFrameNum()*6)%120);
    for(int i=0; i<NUM; i++){
       
        ofSetColor(255, 230, 150, (ofGetFrameNum()*6)%120);
        mBox[i].drawWireframe();

        
        mBox[i].draw();
        
            }
    
    
    /*ofSetColor(255, 255, 255, (ofGetFrameNum()*6)%120);
    box.setPosition(0, 0, 0);
    box.set(150);
    box.draw();
     */
    
    
    
    cam.end();
    
    

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
