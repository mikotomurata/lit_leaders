#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    
    ofSetFrameRate(60);
    ofSetVerticalSync(true);//画面がちらつくのを防ぐ
    ofSetFrameRate(60);
    
    ofEnableAlphaBlending();
    
    boxSize = 15;
    
    for (int i = 0; i < NUM; i++) {
        mBox[i].setPosition(ofRandom(-500, 500), ofRandom(-500, 500), ofRandom(-500, 500));
        mBox[i].set(boxSize);
    }
    BackgroundImage.load("haikei.jpeg");
    
    soundplayer.load("+by--.mp3");
    soundplayer.setLoop(true);
    soundplayer.play();
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    BackgroundImage.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    vec.set(mouseX-p.x, mouseY-p.y);//マウスの速度を保存
    
    cam.begin();
    ofPushMatrix();
    
    //ofSetColor(100, 100, 255);
    
    int alpha = abs(vec.x)+abs(vec.y);
    ofSetColor(ofColor::fromHsb(ofGetFrameNum()%255, 255, 255), 255-alpha);
    
    for (int i =0; i<NUM; i++) {
        //ofRotateY(ofGetFrameNum()/2);
        mBox[i].draw();
    }
    ofPopMatrix();
    ofSetColor(255, 255, 255, (ofGetFrameNum()*6)%120);
    box.setPosition(0, 0, 0);
    box.set(150);
    box.draw();
    
    ofSetColor(255, 255, 255);
    box.drawWireframe();
    
    
    cam.end();
    
    //前のマウスの座標を保存
    p.x = mouseX;
    p.y = mouseY;

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
