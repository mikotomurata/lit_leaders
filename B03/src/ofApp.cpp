#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*
    ofBackground(0, 0, 0);
    
    ofSetVerticalSync(true);//画面の垂直同期
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetCircleResolution(60);
    
    sound.load("sound.mp3");
    sound.setLoop(true);
    sound.play();
    
    //FFT解析　初期化
    fftsmoothed = new float[8192];
    for (int i = 0; i < 8192; i++) {
        fftsmoothed[i]=0;
    }
    nBandstoGet = 360;
    
    */
    
    ofSetFrameRate(60);
    ofBackground(0,0,0);
    
    ofEnableDepthTest();//深度テストを有効
    
    light.enable();
    light.setPosition(-100, 100, 500);
    
    glPointSize(3);
    
    myMesh = ofPlanePrimitive(1000,1000,100,100).getMesh();
    
    for (int i=0; i<myMesh.getVertices().size(); i++) {
        myMesh.addColor(ofFloatColor(1,0.8,1,0.5));
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    /*
     ofSoundUpdate();
    volume= ofSoundGetSpectrum(nBandstoGet);
    
    for(int i= 0; i<nBandstoGet; i++){
        fftsmoothed[i] *= 0.96f;
        if(fftsmoothed[i] < volume[i]){
            fftsmoothed[i] = volume[i];
        }
    }
     */
    for (int i=0; i<myMesh.getVertices().size(); i++) {
        ofVec3f point = myMesh.getVertices()[i]/300.0;
        float size = 80+100*ofNoise(point.x, point.y, point.z, ofGetElapsedTimef());
        ofVec3f newPoint = point.normalize() * size;
        myMesh.setVertex(i,newPoint);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    /*
     int start_x = 200;
    int base_y = 500;
    float width = (float)(800)/nBandstoGet;
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    for (int i=0; i<nBandstoGet; i+=5) {
        ofPushMatrix();
        ofSetColor(ofColor(ofColor::fromHsb((float)255/nBandstoGet*i,100,255)));
        float length = 300 * fftsmoothed[i%nBandstoGet];//四角の幅
        ofRotateZ(i);
        ofDrawRectangle(0,150,5,length);
        ofPopMatrix();
    }
    */
    cam.begin();
    
    myMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    myMesh.draw();
    
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
