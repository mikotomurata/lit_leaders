#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetFrameRate(60);
    //ofSetFrameRate(60);
    ofTrueTypeFont::setGlobalDpi(50);
    
        
    ofSetCircleResolution(60);
}

//--------------------------------------------------------------
void ofApp::update(){
    dist = ofDist(mouseX, mouseY, ofGetWidth()/2, ofGetHeight()/2);
    radian = -1*atan2(mouseY-ofGetHeight()/2, mouseX-ofGetWidth()/2);
    std::cout << radian << std::endl;
    
    int i = ofGetFrameNum();
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
    
    
    
    
    if (c==' ') {
        ofSetColor(0, 0, 0, 140);
        
        ofDrawBitmapString("radius: " + ofToString(radius), mouseX+10, mouseY+15 );
        ofDrawBitmapString("angle: " + ofToString(radian), mouseX+10, mouseY+27 );
        
        
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        //
        if (-3<=radian && radian<=3) {
            
            if (-3<=radian && radian<=0) {
                radian_1 = radian + 3;
                
                for (int i = 0; i<radian_1*19.5; i++) {
                    ofFill();
                    ofSetColor(0, 0, 0, 140);
                    ofDrawTriangle(0, 0, -1*cos(i*PI/60)*dist, sin(i*PI/60)*dist, -1*cos(i*PI/60+PI/60)*dist, sin(i*PI/60+PI/60)*dist);
                    
                }
                for (int i =0; i<40; i++) {
                    ofSetColor(0, 0, 0, 140);
                    ofDrawTriangle(0, 0, cos(i*PI/40)*dist, -1*sin(i*PI/40)*dist, cos(i*PI/40+PI/40)*dist, -1*sin(i*PI/40+PI/40)*dist);
                }
                
                
            }
            if (0<=radian && radian<=3) {
                for (int i = 0; i<radian*19.5; i++) {
                    
                    ofFill();
                    ofSetColor(0, 0, 0, 140);
                    ofDrawTriangle(0, 0, cos(i*PI/60)*dist, -1*sin(i*PI/60)*dist, cos(i*PI/60+PI/60)*dist, -1*sin(i*PI/60+PI/60)*dist);
                }
                
            }
            
        }
        ofPopMatrix();
        
        for (int i =0; i < ofGetFrameNum(); i++) {
            //ボコボコするやつ
            if (ofGetFrameNum()/2 % 2 == 0) {
                d = 5;
                radius = dist / 3 +d;
                
            }else if (ofGetFrameNum()/2 % 2 ==1){
                d = -5;
                radius = dist / 3 +d;
            }
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    c = key;
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
