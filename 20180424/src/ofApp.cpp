#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*pos1 = ofVec2f(100,200);
    pos2 = ofVec2f(300,400);
    pos3 = ofVec2f(300, 0);
*/
   /* for (int i = 0; i < 100; i++) {
        box[i].set(size);
    }*/
    for (int h=0; h<10; h++) {
        for (int w=0; w<10; w++) {
            box[h*10+w].setPosition(h*size,0,w*size);
        
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    /*
    drawTriangle(pos1,pos2,pos3);
    
    posCenter = centerTriangle(pos1,pos2,pos3);
    
    cout << posCenter << endl;
*/
    cam.begin();
    for (int i = 0; i<100; i++) {
        box[i].drawWireframe();
    }
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
//--------------------------------------------------------------
void ofApp::drawTriangle(ofVec2f pos1, ofVec2f pos2, ofVec2f pos3){

    ofDrawTriangle(pos1.x, pos1.y, pos2.x, pos2.y, pos3.x, pos3.y);
    
}
//--------------------------------------------------------------
ofVec2f ofApp::centerTriangle(ofVec2f pos1, ofVec2f pos2, ofVec2f pos3){
    
    posCenter = (pos1 + pos2 + pos3)/3;
    
    return posCenter;
}
