#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0x000000);
    ofSetFrameRate(60);
    
    //Kinect初期設定
    //深度とRGB情報のずれを調整
    kinect.setRegistration(true);
    kinect.setMirror(true);
    kinect.addImegeGenerator();
    kinect.addDepthGenerator();
    
    kinect.getDepthGenerator().GetAlternativeViewPointCap().SetViewPoint(kinect.getImegeGenerator());
    kinect.addUserGenerator();

    kinect.init();
    kinect.open();
    //角度を調整
    kinectAngle = 0;
    kinect.setCameraTiltAngle(kinectAngle);
    

}

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    /*cam.begin();
    
    drawPointCloud();
    cam.end();
     */
    kinect.drawDepth(0, 0, 640, 480);
    kinect.drawSkeletons(0, 0, 640, 480);
    
    if (kinect.getNumTravkedUsers > 0) {
        ofxOpenNI user = kinect,getTrackedUser(0);
    }
    
    

}
//--------------------------------------------------------------
void ofApp::drawPointCloud(){
    int w = 640;
    int h = 480;
    
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_POINTS);
    glPointSize(0.1);
    
    int step = 2;
    for (int y = 0; y<h; y+=step) {
        for (int x = 0; x<w; x+=step) {
            if (kinect.getDistanceAt(x,y)>0) {
                mesh.addColor(kinect.getColorAt(x, y));
                mesh.addVertex(kinect.getWorldCoordinateAt(x, y));
            }
        }
    }
    //meshの頂点を描画
    ofPushMatrix();
    ofScale(1, -1, -1);
    ofTranslate(0, 0, -1000);
    glEnable(GL_DEPTH_TEST);
    mesh.drawVertices();
    ofPopMatrix();
    
}
//--------------------------------------------------------------
void ofApp::exit(){
    kinect.close();
    
    
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case OF_KEY_UP:
            kinectAngle++;
            if (kinectAngle>27) {
                kinectAngle = 27;
                kinect.setCameraTiltAngle(kinectAngle);
            }
            break;
        case OF_KEY_DOWN:
            kinectAngle--;
            if (kinectAngle<-27) {
                kinectAngle = -27;
                kinect.setCameraTiltAngle(kinectAngle);

            }
            
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
