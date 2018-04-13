#include "ofApp.h"

//4つの色を編集してみよう！

void ofApp::setColor(){
    
    //変数「a」は、0から255までの変化を5秒ごとに繰り返します。
    //変数「b」は、0から255の間を滑らかに10秒で往復します。
    
    colors[0].set(a, 255, 255);
    //colors[0].setHsb(0, 0, 0);
    
    colors[1].set(0, b, 0);
    //colors[1].setHsb(0, 0, 0);
    
    //colors[2].set(0, 0, 0);
    colors[2].setHsb(a, 128, 255);
    
    //colors[3].set(0, 0, 0);
    colors[3].setHsb(0, 0, b);
    
}

//--------------------------------------------------------------
void ofApp::setup(){
    for (int i=0; i<4; i++){
        colors.push_back(ofColor(0,0,0));
    }
    ofSetCircleResolution(100);
    ofSetFrameRate(50);
}

//--------------------------------------------------------------
void ofApp::update(){
    //a = ofMap((time % 5000), 0, 5000, 0, 255);
    b = 100 + 60*sin(ofMap(time, 0, 1000, 0, 2*PI));
    a = 128 + 128*sin(ofMap(time, 0, 10000, 0, 2*PI));
    cout << "a:" << a << ", " << "b:" << b << endl;
    setColor();
    if (!pause) time += 20;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    ofFill();
    
    if (pause){
        ofSetColor(colors[0]);
        ofDrawRectangle(60, 30, 280, 280);
        ofSetColor(colors[1]);
        ofDrawRectangle(460, 30, 280, 280);
        ofSetColor(colors[2]);
        ofDrawRectangle(60, 430, 280, 280);
        ofSetColor(colors[3]);
        ofDrawRectangle(460, 430, 280, 280);
    }else{
        ofSetColor(colors[0]);
        ofDrawCircle(200, 170, 140);
        ofSetColor(colors[1]);
        ofDrawCircle(600, 170, 140);
        ofSetColor(colors[2]);
        ofDrawCircle(200, 570, 140);
        ofSetColor(colors[3]);
        ofDrawCircle(600, 570, 140);
    }
    
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("RGB: (     ,     ,     )", 105, 350);
    ofDrawBitmapString(ofToString((int)(colors[0].r)), 163, 350);
    ofDrawBitmapString(ofToString((int)(colors[0].g)), 210, 350);
    ofDrawBitmapString(ofToString((int)(colors[0].b)), 257, 350);
    ofDrawBitmapString("HSB: (     ,     ,     )", 105, 365);
    ofDrawBitmapString(ofToString((int)(colors[0].getHue())), 163, 365);
    ofDrawBitmapString(ofToString((int)(colors[0].getSaturation())), 210, 365);
    ofDrawBitmapString(ofToString((int)(colors[0].getBrightness())), 257, 365);
    
    ofDrawBitmapString("RGB: (     ,     ,     )", 505, 350);
    ofDrawBitmapString(ofToString((int)(colors[1].r)), 563, 350);
    ofDrawBitmapString(ofToString((int)(colors[1].g)), 610, 350);
    ofDrawBitmapString(ofToString((int)(colors[1].b)), 657, 350);
    ofDrawBitmapString("HSB: (     ,     ,     )", 505, 365);
    ofDrawBitmapString(ofToString((int)(colors[1].getHue())), 563, 365);
    ofDrawBitmapString(ofToString((int)(colors[1].getSaturation())), 610, 365);
    ofDrawBitmapString(ofToString((int)(colors[1].getBrightness())), 657, 365);
    
    ofDrawBitmapString("RGB: (     ,     ,     )", 105, 750);
    ofDrawBitmapString(ofToString((int)(colors[2].r)), 163, 750);
    ofDrawBitmapString(ofToString((int)(colors[2].g)), 210, 750);
    ofDrawBitmapString(ofToString((int)(colors[2].b)), 257, 750);
    ofDrawBitmapString("HSB: (     ,     ,     )", 105, 765);
    ofDrawBitmapString(ofToString((int)(colors[2].getHue())), 163, 765);
    ofDrawBitmapString(ofToString((int)(colors[2].getSaturation())), 210, 765);
    ofDrawBitmapString(ofToString((int)(colors[2].getBrightness())), 257, 765);
    
    ofDrawBitmapString("RGB: (     ,     ,     )", 505, 750);
    ofDrawBitmapString(ofToString((int)(colors[3].r)), 563, 750);
    ofDrawBitmapString(ofToString((int)(colors[3].g)), 610, 750);
    ofDrawBitmapString(ofToString((int)(colors[3].b)), 657, 750);
    ofDrawBitmapString("HSB: (     ,     ,     )", 505, 765);
    ofDrawBitmapString(ofToString((int)(colors[3].getHue())), 563, 765);
    ofDrawBitmapString(ofToString((int)(colors[3].getSaturation())), 610, 765);
    ofDrawBitmapString(ofToString((int)(colors[3].getBrightness())), 657, 765);
    
    ofNoFill();
    ofSetLineWidth(2);
    ofDrawLine(400, 0, 400, 800);
    ofDrawLine(0, 400, 800, 400);
    
    ofSetLineWidth(5);
    if (pause){
        ofDrawRectangle(50, 20, 300, 300);
        ofDrawRectangle(450, 20, 300, 300);
        ofDrawRectangle(50, 420, 300, 300);
        ofDrawRectangle(450, 420, 300, 300);
    } else {
        ofDrawCircle(200, 170, 150);
        ofDrawCircle(600, 170, 150);
        ofDrawCircle(200, 570, 150);
        ofDrawCircle(600, 570, 150);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key==' ') pause = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key==' ') pause = false;
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
