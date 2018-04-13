#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);

}

//--------------------------------------------------------------
void ofApp::update(){
    radian = atan2(mouseY-ofGetHeight()/2, mouseX-ofGetWidth()/2);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    /*cam.begin();
    
    ofPushMatrix();
    ofRotateX(90);
    ofSetCircleResolution(100);
    ofDrawCircle(0, 0, 200);
    ofPopMatrix();
    
    ofDrawLine(0, 0, <#float x2#>, <#float y2#>)
    

    cam.end();
     */
    float pie_w = 300;  //円グラフの幅
    float pie_h = 300;  //円グラフの高さ
      //通常の円グラフの始点にするため、スタート地点を設定
    int angle0 = 60;  //グラフの角度
    
    
    //中心点のx, 中心点のy, 幅, 高さ, 始点の角度, 終点の角度
    //ofDrawC(ofGetWidth()/2, ofGetHeight()/2, pie_w, pie_h, 0, radian);
    
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
