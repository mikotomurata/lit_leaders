#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    reciever.setup(PORT);
    
    //初期化
    remoteMouse.x = 0;
    remoteMouse.y = 0;
    
    mouseButtonState = "";
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    while (reciever.hasWaitingMessages()) {
        
        ofxOscMessage m;
        reciever.getNextMessage(&m);
        
        if (m.getAddress() == "/mouse/position") {
            remoteMouse.x = m.getArgAsInt32(0);
            remoteMouse.y = m.getArgAsInt32(1);
            
        }else if (m.getAddress() == "/mouse/button"){
            mouseButtonState = m.getArgAsString(0);
            
        }
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    //ofSetColor(0);
    //ofDrawCircle(remoteMouse.x, remoteMouse.y, 30);
    if (mouseButtonState == "down") {
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    }else{
        ofSetColor(0);
    }
    ofDrawCircle(remoteMouse.x, remoteMouse.y, 30);
    

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
