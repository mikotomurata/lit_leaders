#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    particle.addForce(0, 1.0);
    particle.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    particle.draw();
//    ofSetColor(255);
//    if (pos1.y >= ofGetHeight()) {
//        pos1.y = -ofGetHeight()/2;
//        pos1.y = 1;
//        pos1.x =ofRandom(ofGetWidth()/2);
//    }else{
//        for (int i = 0; i < 6; i++) {
//            ofPushStyle();
//            ofNoFill();
//            ofPushMatrix();
//            ofTranslate(pos1.x, pos1.y);
//            ofRotateZ(60*i);
//            ofDrawTriangle(0, 0, 1*a,-1*sqrt(3)*a, -1*a, -1*sqrt(3)*a);
//            ofDrawTriangle(0, -2*sqrt(3)*a, 1*a,-1*sqrt(3)*a, -1*a, -1*sqrt(3)*a);
//            ofPopMatrix();
//            ofPopStyle();
//        }
//    }
//
//
//
//    //太枠
//    if (pos2.y > ofGetHeight()) {
//        pos2.y = 1;
//        pos2.x =ofRandom(ofGetWidth()/2);
//    }else{
//        for (int i = 0; i < 6; i++) {
//            ofPushMatrix();
//            ofTranslate(pos2.x, pos2.y);
//            ofRotateZ(60*i);
//            ofDrawTriangle(0, 0, 1*c,-1*sqrt(3)*c, -1*c, -1*sqrt(3)*c);
//            ofDrawTriangle(0, -2*sqrt(3)*c, 1*c,-1*sqrt(3)*c, -1*c, -1*sqrt(3)*c);
//            ofPopMatrix();
//
//        }
//        for (int i = 0; i < 6; i++) {
//            ofPushMatrix();
//            ofSetColor(0);
//            ofTranslate(pos2.x, pos2.y);
//            ofRotateZ(60*i);
//            ofDrawTriangle(0, 0, 1*b,-1*sqrt(3)*b, -1*b, -1*sqrt(3)*b);
//            ofDrawTriangle(0, -2*sqrt(3)*b, 1*b,-1*sqrt(3)*b, -1*b, -1*sqrt(3)*b);
//            ofPopMatrix();
//        }
//    }
//
//
//
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
