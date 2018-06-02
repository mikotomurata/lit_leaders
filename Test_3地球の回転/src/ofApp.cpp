#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    model.loadModel("SimpleEarth/Earth Planet.DAE");
    model.setPosition(0, 0, 0);
    model.setScale(1, -1, -1);
    light.setPosition(0, 0, 0);
    light.setPointLight();
    light.setAmbientColor(ofFloatColor(255.0,255.0, 255.0,255.0));
    model.getMesh(0).clearNormals();
    model.setNormalizationFactor(-1.0);
    
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    cam.setOrientation(ofPoint(-20,0,0));
    glEnable(GL_DEPTH_TEST);//深さを有効
    
    glEnable(GL_NORMALIZE);//法線ベクトルの自動正規化
    
    leap.open();
    
   

}

//--------------------------------------------------------------
void ofApp::update(){
    model.update();
    
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
//    cout<< clickY<< endl;
//    if (320 < clickX && clickX < 340 && -210 < clickY && clickY < -190 ) {
//        mode = 0;
//        ofRotateY(angle/PI*360);
//        angleEarth = angle/PI*360;
//    }
//        else{
//            ofRotateY(angleEarth);
//        }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    cam.begin();
    
    ofEnableDepthTest();
    ofEnableSmoothing();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    ofEnableSeparateSpecularLight();
    
    //    light.draw();
    light.enable();
    
    ofPushMatrix();
    ofRotateY(90);
    //切り替える条件
    if (mode == 0) {
        ofRotateY(angle/PI*360);
        angleEarth = angle/PI*360;
        model.drawFaces();
    }else{
        ofRotateY(angleEarth);
    }
//    model.drawFaces();
    ofPopMatrix();
    
    ofDrawSphere(150, 147,147, 1);//大体の関空の位置
    cam.end();
    light.disable();
    
    ofDisableDepthTest();
    ofDisableBlendMode();
    ofDisableSmoothing();
    ofDisableSeparateSpecularLight();
    
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
            
//            ofSetColor(255, 0, 0);//人差し指
            ofDrawSphere(fingerPos.at(7), 10);
            
//            ofSetColor(0,0,255);
            ofDrawSphere(fingerPos.at(20*i+4*f+3), 10);
            
            ofDrawLine(fingerPos.at(20*i+4*f+0), fingerPos.at(20*i+4*f+1));
            ofDrawLine(fingerPos.at(20*i+4*f+1), fingerPos.at(20*i+4*f+2));
            ofDrawLine(fingerPos.at(20*i+4*f+2), fingerPos.at(20*i+4*f+3));
            
            ofPushMatrix();
            ofRotateX(-90);
            angle = atan2(0-fingerPos.at(7).y, 0-fingerPos.at(7).x);
            ofPopMatrix();
            
        }
    }
        cam.end();
}
//--------------------------------------------------------------
void ofApp::exit(){
    
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'z') {
        mode = 0;
    }else if (key == 'x'){
        mode = 1;
    }else if (key == 'c'){
        mode =2;
    }

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
