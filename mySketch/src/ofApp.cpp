#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(21,37,84);
//    ofSetFrameRate(60);
//    ofSetVerticalSync(true);
//    ofEnableAlphaBlending();
//
//    boxSize = 15;
//    for(int i=0; i<NUM; i++){
//        mBox[i].setPosition(ofRandom(-1000,1000), ofRandom(-1000,1000), ofRandom(-1000,1000));
//        mBox[i].set(boxSize);
//    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
  
    
    
//
//    ofSetColor(255, 230, 150, (ofGetFrameNum()*6)%120);
//    for(int i=0; i<NUM; i++){
//
//        ofSetColor(255, 230, 150, (ofGetFrameNum()*6)%120);
//        mBox[i].drawWireframe();
//
//
//        mBox[i].draw();
//
//            }
//
//
//    /*ofSetColor(255, 255, 255, (ofGetFrameNum()*6)%120);
//    box.setPosition(0, 0, 0);
//    box.set(150);
//    box.draw();
//     */
//    for (int n = 0; n<100; n++) {
//        for (int i = 0; i <100; i++) {
//            ofDrawLine(0, 0, point[i].x, point[i].y);
//        }
//    }
//    for (int i = 0; i < 1000; i++) {
//        <#statements#>
//    }
//    if (clickX>0 && clickY>0) {
////        for (int n = 0; n<100; n++) {
//            for (int i = 0; i <100; i++) {
//                ofDrawLine(0, 0, point[i].x, point[i].y);
//            }
////        }
//    }
   
    
    
    for (int i = 0; i < 100; i++) {
        ofDrawLine(0, 0, clickX, clickY) ;
        
    }
   
//    for (int i = 0; i < 1000; i+= 10) {
//
//        ofDrawCircle(i, i, 10);
//    }
    
    
    
    

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
    clickX = x;
    clickY = y;
    
    

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
