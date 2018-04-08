#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(60);
     ofBackground(0, 0, 0);
    
    x = 100;
    y = 100;
    xx = 5;
    yy = 5;
    
    for (int i = 0; i<NUM; i++){
        abox[i].setPosition(ofRandom(-1000,1000), ofRandom(-1000,1000), ofRandom(-1000,1000));
        abox[i].set(50);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    x = x + xx;
    y = y + yy;
    if(x < 100 || ofGetWidth()-100 < x)
        xx *= -1;
    if(y < 100 || ofGetHeight()-100< y)
        yy *= -1;
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    
    
    for(int i = 0; i<NUM; i++){
        
        
        abox[i].draw();
        //ofDrawBox(pos1, pos2, pos3, 100, 100, 100);
        
    }
        
    
    
    
    
   
    cam.end();
    /*ofSetColor(0, 0, 255);
    
    ofDrawCircle(x, y,0, 100);
     */
    
    /*for(int i = 0; i < 8 ; i++){
        ofSetLineWidth(2);
        ofSetColor(255, 0, 0);
        ofDrawLine(i*a, 0, i*a, ofGetHeight());
    }
    for(int i = 0; i < 6 ; i++){
        ofSetLineWidth(2);
        ofSetColor(255, 0, 0);
        ofDrawLine(0, i*b, ofGetWidth(), i*b);
        
    }
    
    ofSetColor(0, 0, 255);
    ofDrawCircle(a*3, b, 100);
    
    ofSetColor(0, 255, 50);
    ofDrawRectangle(x*4, y*2, x*2, y*2);
    
    ofSetColor(255, 0, 255);
    ofDrawTriangle(x*2+25, y*4+25, x*2+25,y*6-25 , x*4-25,y*6-25 );
    
    ofSetColor(255, 255, 0);
    ofDrawEllipse(x,y*3, 200, 700);
     */
    
    
    
    
    
    
    //for(int i = 0; i>)
    //128
    
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    /*if(key == 'a'){
        xx *= 2;
        yy *= 2;
    }else if(key == 'b'){
        xx *= 0.5;
        yy *= 0.5;
    }
     */
    
    /*switch (key){
        case 'a':
            xx *= 2;
            yy *= 2;
            break;
        case 'b':
            xx *= 0.5;
            yy *= 0.5;
            break;
        default:
            break;
    }
*/
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
    click++;
    
    if (click % 4 == 0) {
        ofBackground(255, 255, 255);
    }else if(click % 4 == 1){
        ofBackground(255, 255, 0);
    }else if(click % 4 == 2){
        ofBackground(255, 0, 255);
    }else{
        ofBackground(0, 255, 255);
    }
    
    xx *= -1;
    yy *= -1;
*/
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
