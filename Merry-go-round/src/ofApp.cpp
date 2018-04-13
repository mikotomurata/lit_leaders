#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
   // ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    //ofSetBackgroundAuto(false);
    ofBackground(255, 255, 255);

}

//--------------------------------------------------------------
void ofApp::update(){
    radian = -1*(atan2(mouseY-ofGetHeight()/2, mouseX-ofGetWidth()/2));
    std::cout<<radian<<std::endl;
    //phase += 0.01;
    //radian = atan2(mouseY-ofGetHeight()/2, mouseX-ofGetWidth()/2);
    dist = ofDist(mouseX, mouseY, ofGetWidth()/2, ofGetHeight()/2);

}


//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    /*cam.begin();
    
    ofPushMatrix();
    ofRotateX(90);
    ofSetCircleResolution(100);
    ofDrawCircle(0, 0, 200);
    ofPopMatrix();
    
    ofDrawLine(0, 0, <#float x2#>, <#float y2#>)
    

    cam.end();
     */
    
    //半径の設定
    //float radius = dist;
    //原点を画面の中心点に
    
    //円の座標を三角関数を利用して計算
    
    //色を指定
    ofSetColor(0, 0, 0);
    //円の描画
    
    if (0<=radian && radian<=1.5) {
        for (int i = 0; i <= 30; i++) {
            int cd =mouseX;
            int ab = 50;
            ofDrawTriangle(0, 0, cos(i/20*PI/6)*100, -1*sin(i/20*PI/6)*100, cos(i/20+PI/6)*100, -1*sin(i/20+PI/6)*100);
        }
    }
     /*ofDrawTriangle(0, 0, cos(0)*dist, -1*sin(0)*dist, cos(PI/12)*dist, -1*sin(PI/12)*dist);
     ofDrawTriangle(0, 0, cos(PI/12)*dist, -1*sin(PI/12)*dist, cos(PI/6)*dist, -1*sin(PI/6)*dist);
    */
    
   
}
//-------------------------------------------------------------------------------------------------
    
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
