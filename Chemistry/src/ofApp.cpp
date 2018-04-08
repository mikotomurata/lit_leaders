#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofTrueTypeFont::setGlobalDpi(72);
    
    verdana.load("verdana.ttf", 20);
    verdana.setLineHeight(24);
    verdana.setLetterSpacing(1.0);
    

    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    
    ofBackground(0, 0, 0);
    ofSetColor(0, 255, 0, 85);
    ofDrawLine(-150, 70, -28.3, -100, 0, 0);
    ofDrawLine(-150, 70, -28.3, -200, 0, 0);
    ofDrawLine(-150, 70, -28.3, -150, 0, -85);
    ofDrawLine(-100, 0, 0, -150, 0, -85);
    ofDrawLine(-200, 0, 0, -150, 0, -85);
    ofDrawLine(-200, 0, 0, -100, 0, 0);
    
    ofSetColor(0, 255, 0);
    ofDrawLine(-150, 35, -28.3, -150, 70, -28.3);
    ofDrawLine(-150, 25, -38.3, -150, 0, -85);
    ofDrawLine(-160, 25, -28.3, -200, 0, 0);
    ofDrawLine(-140, 25, -28.3, -100, 0, 0);
    
    ofSetColor(0, 255, 255);
    ofDrawLine(0, ofGetHeight(), 0, -ofGetHeight());
    
    ofSetColor(0, 255, 255, 50);
    ofPushMatrix();
    ofTranslate(ofPoint(0, 0, 500));
    ofRotateY(90);
    ofDrawRectangle(0, -ofGetHeight(), 0, 2000, ofGetHeight()*2);
    ofPopMatrix();
    
    
    
    ofSetColor(255, 0, 0);
    verdana.drawString("NH2",-100,0 );
    verdana.drawString("CH2OH",-270,0 );
    
    ofPushMatrix();
    ofTranslate(ofPoint(-150, 0, -95));
    verdana.drawString("H",-10,0 );
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofPoint(-150, 70, -28.5));
    verdana.drawString("COOH",-30,10 );
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofPoint(-150, 25, -28.3));
    verdana.drawString("C",-10,0 );
    ofPopMatrix();
    
    //反対側
    ofSetColor(0, 255, 0, 85);
    ofDrawLine(150, 70, -28.3, 100, 0, 0);
    ofDrawLine(150, 70, -28.3, 200, 0, 0);
    ofDrawLine(150, 70, -28.3, 150, 0, -85);
    ofDrawLine(100, 0, 0, 150, 0, -85);
    ofDrawLine(200, 0, 0, 150, 0, -85);
    ofDrawLine(200, 0, 0, 100, 0, 0);
    
    ofSetColor(0, 255, 0);
    ofDrawLine(150, 35, -28.3, 150, 70, -28.3);
    ofDrawLine(150, 25, -38.3, 150, 0, -85);
    ofDrawLine(160, 25, -28.3, 200, 0, 0);
    ofDrawLine(140, 25, -28.3, 100, 0, 0);
    
    ofSetColor(255, 0, 0);
    verdana.drawString("NH2",60,0 );
    verdana.drawString("CH2OH",200,0 );
    
    ofPushMatrix();
    ofTranslate(ofPoint(145, 0, -100));
    verdana.drawString("H",10,0 );
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofPoint(150, 70, -28.5));
    verdana.drawString("COOH",-30,10 );
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofPoint(130, 25, -28.3));
    verdana.drawString("C",10,0 );
    ofPopMatrix();
    
    
    
    

    
    
    
    
    
    
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
