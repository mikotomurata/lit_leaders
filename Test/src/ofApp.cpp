#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    //ofSetBackgroundAuto(false);
    ofBackground(255, 255, 255);
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    //ofRotateY(180);
    radian = -1*(atan2(mouseY-ofGetHeight()/2, mouseX-ofGetWidth()/2));
    
    std::cout<<radian<<std::endl;
    //phase += 0.01;
    //radian = atan2(mouseY-ofGetHeight()/2, mouseX-ofGetWidth()/2);
    dist = ofDist(mouseX, mouseY, ofGetWidth()/2, ofGetHeight()/2);

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    ofSetColor(0, 0, 0);
    //円の描画
    
    if (-3<=radian && radian<=3) {
     
        if (-3<=radian && radian<=0) {
            radian_1 = radian + 3;
            
            for (int i = 0; i<radian_1*19.5; i++) {
               // ofDrawTriangle(0, 0, cos(i*PI/60)*dist, -1*sin(i*PI/60)*dist, cos(i*PI/60+PI/60)*dist, -1*sin(i*PI/60+PI/60)*dist);
                ofDrawTriangle(0, 0, -1*cos(i*PI/60)*dist, sin(i*PI/60)*dist, -1*cos(i*PI/60+PI/60)*dist, sin(i*PI/60+PI/60)*dist);
                for (int i =0; i<40; i++) {
                     ofDrawTriangle(0, 0, cos(i*PI/40)*dist, -1*sin(i*PI/40)*dist, cos(i*PI/40+PI/40)*dist, -1*sin(i*PI/40+PI/40)*dist);
                }
            }
        }
        if (0<=radian && radian<=3) {
            for (int i = 0; i<radian*19.5; i++) {
                
                // ofDrawTriangle(0, 0, -1*cos(i*PI/40)*dist, sin(i*PI/40)*dist, -1*cos(i*PI/40+PI/40)*dist, sin(i*PI/40+PI/40)*dist);
                
                ofDrawTriangle(0, 0, cos(i*PI/60)*dist, -1*sin(i*PI/60)*dist, cos(i*PI/60+PI/60)*dist, -1*sin(i*PI/60+PI/60)*dist);
        }
        
        }
        
   
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
