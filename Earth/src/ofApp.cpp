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
   
//    cout << model.getNormalizedScale() << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    model.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    light.enable();
   
    ofEnableDepthTest();
    ofEnableSmoothing();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    ofEnableSeparateSpecularLight();
    
    cam.begin();
    light.draw();
    ofPushMatrix();
    ofRotateY(90);
    model.drawFaces();
    ofPopMatrix();
    
    ofDrawSphere(150, 147,147, 1);//大体の関空の位置
    cam.end();
    light.disable();
    
    ofDisableDepthTest();
    ofDisableBlendMode();
    ofDisableSmoothing();
    ofDisableSeparateSpecularLight();
    
    
   
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
