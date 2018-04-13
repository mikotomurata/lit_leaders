#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    kinect.setRegistration(true);//RGBイメージに合わせる深度画像を調整
    kinect.init();//初期化
    kinect.open();//データ取得開始
    if (!kinect.isConnected()) {
        ofSystemAlertDialog("Serial Error : Kinect is not connected.");
    }
    //Guiの設定
    ofxGuiSetDefaultWidth(300);
    ofxGuiSetDefaultHeight(18);
    gui.setup("Depth Masking Control");
    gui.setPosition(10,10);
    //gui.add(radius.set("Radius",0,0,255));
    gui.add(near.set("near",0, 0, 255));
    gui.add(far.set("far",0, 0, 255));
    gui.add(color.set("color",(255, 255, 255, 255), ofColor(0, 0, 0, 0), ofColor(255, 255, 255, 255)));
            //(スライダー名.setup(名前、初期値、最小値、最大値))
}

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update();//データ更新
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    //kinect.draw(0, 0, ofGetWidth(), ofGetHeight());
    if (kinect.isFrameNew()) {
        cameraImage.setFromPixels(kinect.getPixels().getData(), kinect.width, kinect.height, OF_IMAGE_COLOR);
        //(配列による画像データ、配列による画僧の幅、配列による画像の高さ、イメージタイプ)
        depthImage.setFromPixels(kinect.getPixels().getData(), kinect.width, kinect.height, OF_IMAGE_GRAYSCALE);
        
        unsigned char * cameraPixels = cameraImage.getPixels().getData();
        unsigned char * depthPixels = depthImage.getPixels().getData();
        maskedImage.allocate(kinect.width, kinect.height, OF_IMAGE_COLOR);
        unsigned char * maskedPixels = maskedImage.getPixels().getData();
        
    }
    cameraImage.draw(0, 0, kinect.width, kinect.height);
    depthImage.draw(0, kinect.height, kinect.width/2, kinect.height/2);
    ofSetColor(color);
    maskedImage.draw(kinect.width/2, kinect.height, kinect.width/2, kinect.height/2);
    ofSetColor(255);
   // ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, radius.get());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            kinect.init();
            kinect.open();
            if (!kinect.isConnected()) {
                ofSystemAlertDialog("Serial Error : Kinect is not connected.");
            }
            
            break;
            
        default:
            break;
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
