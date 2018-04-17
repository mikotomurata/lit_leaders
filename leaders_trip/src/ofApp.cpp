#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackgroundHex(0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    /*地球上の空港のやつ
    //ofSetCircleResolution(3);
    //ログの表示レベル？
    ofSetLogLevel("ofxCsv", OF_LOG_VERBOSE);
    
    //メッシュの頂点を点で表示
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    //距離に応じて点の大きさを変える？
    static GLfloat distance[] = { 0.0, 0.0, 1.0 };
    glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, distance);
    glPointSize(1500);
    */
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //dist = ofDist(200, 0, clickX, clickY);
   // radius = dist / 2;
    theta +=0.1;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    
    //基準(200, 0);
    //地球モデルの代わり
    /*ofSetColor(0, 50, 200);
    ofDrawSphere(0, 0, 0, 200);
    
    
    
    */
    
    //扇型
    //ofNoFill();
    ofPath curve;
    ofSetColor(255);
    curve.arc(0, 0, 200, 200, 0, 180);
    curve.setCircleResolution(60);
    curve.draw();
    
   //軌道に乗って動く
    if (theta < PI) {
        ofSetColor(255, 120);
        //飛行機の代わり
        ofDrawCircle(cos(theta)*200, sin(theta)*200, 50);
    }
    
    

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
    clickX = x;
    clickY = y;
    
    std::cout<< x <<std::endl;
     std::cout<< y <<std::endl;

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
