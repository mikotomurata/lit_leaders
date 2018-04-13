#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofEnableAlphaBlending();
    //ofSetFrameRate(60);
    ofTrueTypeFont::setGlobalDpi(50);
    
    verdana.load("verdana.ttf", 20);
    verdana.setLineHeight(50);
    verdana.setLetterSpacing(1.0);

    ofSetCircleResolution(60);
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    dist = ofDist(mouseX, mouseY, ofGetWidth()/2, ofGetHeight()/2);
    radian = atan2(mouseY-ofGetHeight()/2, mouseX-ofGetWidth()/2);
    
    int i = ofGetFrameNum();
    //std::cout << i << std::endl;
    
    
   

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i<30; i++) {
        ofSetColor(0, 180);
        ofSetLineWidth(1);
        ofDrawLine(i*35, 0, i*35, ofGetHeight());
    }
    for(int i =0; i<25; i++){
        ofSetColor(0, 180);
        ofSetLineWidth(1);
        ofDrawLine(0, i*34, ofGetWidth(), i*34);
    }
    ofSetLineWidth(2);
    
    ofSetColor(0, 100);
        ofDrawLine(mouseX, 0, mouseX, ofGetHeight());
        ofDrawLine(0, mouseY, ofGetWidth(), mouseY);
    
    //真ん中の円
    ofSetColor(ofColor::fromHsb((radian+3)/6*255, 255, 255));
    ofFill();
    
     ofDrawCircle(ofGetWidth()/2,ofGetHeight()/2, dist / 3+d);
    
    ofNoFill();
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, dist+d);
    
    
    //中央からのせん
    
    ofDrawLine(ofGetWidth()/2, ofGetHeight()/2, mouseX, mouseY);
    //ボコボコするやつ
    for (int i =0; i < ofGetFrameNum(); i++) {
        if (c==' ') {
            if (ofGetFrameNum()/2 % 2 == 0) {
                d = 5;
                radius = dist / 3 +d;
                //verdana.drawString(radius, mouseX+20,mouseY+15 );
                
                
            }else if (ofGetFrameNum()/2 % 2 ==1){
                d = -5;
                radius = dist / 3 +d;
            }
        }
    }
    std::cout<< radius <<std::endl;
    ofPoint center;
    float radius = dist;
    //center.set(ofGetWidth()/2,ofGetHeight()/2);
    
    //描画
    /*ofBeginShape();
    for (int i = 0;i < 360;i += (360/6)){
        ofVertex(center.x+cos(ofDegToRad(i))*radius,
                 center.y+sin(ofDegToRad(i))*radius);
    }
    ofEndShape();
    */
    
    ofSetColor(0, 0, 0, 140);
    verdana.drawString("radius:",mouseX+10,mouseY+15 );
    
    verdana.drawString("angle:",mouseX+10,mouseY+27 );
    

    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    c = key;
    /*if (key==' ') {
        if (ofGetFrameNum() % 2 == 0) {
            c = 5;
            
        }else if (ofGetFrameNum() % 2 ==1){
            c = -5;
        }
    }*/
    
        
    
            
     
    

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
