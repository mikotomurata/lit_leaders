#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableAlphaBlending();
     leap.open();

}

//--------------------------------------------------------------
void ofApp::update(){
    
    simpleHands=leap.getSimpleHands();
    if ( leap.isFrameNew() && simpleHands.size()){
        
        fingerPos.clear();
        
        handPos.clear();
        
        leap.setMappingX(-230,230,-ofGetWidth()/2,ofGetWidth()/2);
        leap.setMappingY(90,490,-ofGetHeight()/2,ofGetHeight()/2);
        leap.setMappingZ(-150,150,-200,200);
        
        fingerType fingerTypes[]={THUMB,INDEX, MIDDLE,RING,PINKY};
        
        for(int i=0; i<simpleHands.size(); i++ ) {
            handPos.push_back(simpleHands[i].handPos);
            
            for(int f=0; f<5; f++){
                ofPoint mcp=simpleHands[i].fingers[ fingerTypes[f]].mcp;
                fingerPos.push_back(mcp);
                
                ofPoint pip=simpleHands[i].fingers[ fingerTypes[f]].pip;
                fingerPos.push_back(pip);
                
                ofPoint dip=simpleHands[i].fingers[ fingerTypes[f]].dip;
                fingerPos.push_back(dip);
                
                ofPoint tip=simpleHands[i].fingers[ fingerTypes[f]].tip;
                fingerPos.push_back(tip);
            }
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    
    ofNoFill();
    ofSetColor(255, 120);
    ofDrawSphere(0, 0, 300);
    
    for(int i=0; i<simpleHands.size(); i++){
        
        ofSetColor(255, 255, 255);
        ofDrawSphere(handPos.at(i), 20);
        
        for (int f=0; f<5; f++ ){
            
            ofSetColor(255);
            ofDrawSphere(fingerPos.at(20*i+4*f+0), 10);
            
            ofSetColor(200);
            ofDrawSphere(fingerPos.at(20*i+4*f+1), 10);
            
            ofSetColor(155);
            ofDrawSphere(fingerPos.at(20*i+4*f+2), 10);
            
            ofSetColor(255, 0, 0);//人差し指
            ofDrawSphere(fingerPos.at(7), 10);
            
            ofSetColor(0,0,255);
            ofDrawSphere(fingerPos.at(20*i+4*f+3), 10);
            
            ofDrawLine(fingerPos.at(20*i+4*f+0), fingerPos.at(20*i+4*f+1));
            ofDrawLine(fingerPos.at(20*i+4*f+1), fingerPos.at(20*i+4*f+2));
            ofDrawLine(fingerPos.at(20*i+4*f+2), fingerPos.at(20*i+4*f+3));
            dist = ofDist(0, 0, 0, fingerPos.at(7).x, fingerPos.at(7).y, fingerPos.at(7).z);
            if(270 < dist && dist < 300){
                for (int i = 0; i < 100; i++) {
                    point[i] = ofVec3f(fingerPos.at(7).x, fingerPos.at(7).y, fingerPos.at(7).z);
                    cout << point[i].x << endl;
                }
            }
        }
    }
    for (int i = 0; i < 100; i++) {
        ofSetColor(255);
        ofDrawLine(0, 0, 0, point[i].x, point[i].y, point[i].z);
    }
    
    
    
    cam.end();
}
//-------------------------------------------------------------
void ofApp::exit(){
    
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
