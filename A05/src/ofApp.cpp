#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetColor(0, 0, 0);
    /*
    soundplayer.load("sound.mp3");
    soundplayer.setVolume(1.0);
    soundplayer.setLoop(true);
    soundplayer.play();
    */
    soundstream.setup(this, 0, 1, 44100, 256, 4);//ofSoundStreamを初期化
    
   // video.initGrabber(ofGetWidth(),ofGetHeight());

}
//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    curVol = 0.0;
    for (int i =0; i <  bufferSize; i++) {
        curVol += input[i] * input[i];
        curVol /= bufferSize;
    }
     
}
//--------------------------------------------------------------
void ofApp::update(){
    
    curVol *= 2000;
    
   // video.update();
    
    /*volume = ofSoundGetSpectrum(1); //音量を取得
    size_circle = *volume*1300;*/
    
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
   // ofDrawCircle(x_circle, y_circle, 50);
    //ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, size_circle);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, curVol);
    
  //  video.draw(0,0);
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    /*
    if(key == 'a'){
        size_circle += 20;
    }
    if(key == 's'){
        size_circle -= 20;
    }
    */

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    /*
    if(key == 'q'){
        size_circle += 20;
    }
    if(key == 'w'){
        size_circle -= 20;
    }
*/
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
   /*
    x_circle = x;
    y_circle = y;
    
    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    */
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
   /*
    if(button == 0){//左
        ofSetColor(255, 0, 0);
    }
    if (button == 1) {//真ん中
        ofSetColor(0, 255, 0);
    }
    if (button == 2) {//右
        ofSetColor(0, 0, 255);
    }
    x_circle = x;
    y_circle = y;
    */
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    /*x_circle = x;
    y_circle = y;
*/
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
   /* x_circle = ofGetWidth()/2;
    y_circle = ofGetHeight()/2;
*/
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
