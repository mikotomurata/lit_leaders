#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofPoint center;
    center.x = (clickX)/2;
    center.y = (clickY)/2;
    
    radius = ofDist(center.x, center.y, clickX, clickY);
    theta +=0.1;
    
    angle = atan2(0-(clickX)/2, 0-(clickY)/2);
    std::cout << angle << std::endl;
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
//    弧の中心
    ofPoint center;
    center.x = (clickX)/2;
    center.y = (clickY)/2;
//   地球の代わり
    ofSetColor(0, 100, 255,120);
    ofDrawSphere(-200, 0,  200);
//    弧を描く
    ofPushMatrix();
    
    ofTranslate(center.x, -1*center.y);
    ofRotate(angle/PI*180 + 90);
    
    
    for (float i = 0; i < PI; i+=0.001) {
        ofSetColor(255);
        ofDrawCircle(cos(i)*radius, sin(i)*radius, 1);
        
    }
    if (theta < PI) {
        
        ofSetColor(255, 120);
        //飛行機の代わり
        ofDrawCircle(cos(theta)*radius, sin(theta)*radius, 50);
        
    }
    
    
    
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
    /*
    if (x > ofGetWidth()/2 ) {
        clickX = x - ofGetWidth();
    }else if (){
        
    }
    if (y > ofGetHeight()/2) {
        clickY = y - ofGetHeight();
    }
    */
     clickX = x - ofGetWidth()/2;
     clickY = y - ofGetHeight()/2;
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
