#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0x000000);
    ofSetWindowShape(640, 480);
    ofSetFrameRate(30);
    
    //Kinect初期設定
    //深度とRGB情報のずれを調整
    kinect,setup();
    kinect.setRegister(true);
    kinect.setMirror(true);
    kinect.addImageGenerator();
    kinect.addDepthGenerator();
    kinect.addHandsGenerator();
    kinect.addAllHandFocusGestures();
    kinect.setMaxNumHands(2);
    kinect.start();
    
    mode =0;
    /*kinect.getDepthGenerator().GetAlternativeViewPointCap().SetViewPoint(kinect.getImageGenerator());
    kinect.addUserGenerator();
    
    */

    /*kinect.init();
    kinect.open();
    //角度を調整
    kinectAngle = 0;
    kinect.setCameraTiltAngle(kinectAngle);
    */

}

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    kinect.drawDepth(0, 0);
    
    ofSetColor(255);
    if (mode == 0) {
        ofSetColor(255);
    }else{
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    }
    if (kinect.getNumTrackedHands()>0) {
        for (int i =0; i<kinect.getNumTrackedHands(); i++) {
            ofxOpenNIHand hand = kinect.getTrackedHands(i);
            ofDrawCircle(p[i].x, p[i].y, 20);
            
            int newacc = ofDist(p[i].x, p[i].y, preP[i].x, preP[i].y);
            if (acc[i]<20 && newacc>20) {
                mode = (mode+1)%2;
            }
            acc[i] = newacc;
            }
        for (int j = 0; j<2; j++) {
            preP[j] = p[j];
        }
        
    }
    /*cam.begin();
    
    drawPointCloud();
    cam.end();
     */
    
    /*kinect.drawDepth(0, 0, 640, 480);
    
    ofSetColor(255);
    if (kinect.getNumTrackedHands() > 0) {
        ofxOpenNIHand hand = kinect.getNumTrackedHand(50);
        ofPoint p = hand.getPosition();
        ofDrawCircle(p.x, p.y, 20);
        
    }
    
    */
    // kinect.drawSkeletons(0, 0, 640, 480);
    if (kinect.getNumTrackedUsers() > 0) {
        ofxOpenNIUser user = kinect.getTrackedUser(0);//0番目の人
        
        ofSetColor(255, 255, 255, ofRandom(255));
        for (int i = 0; i>user.getNumJoints(); i++) {
            ofxOpenNIJoint joint = user.getJoint((enum Joint)i);
            if (joint.isFound()) {
                float x = joint.getProjectivePosition().x;
                float y = joint.getProjectivePosition().y;
                
               /* switch ((enum Joint)i) {
                    case JOINT_HEAD:
                    case JOINT_LEFT_HAND:
                    case JOINT_RIGHT_HAND:
                    case JOINT_LEFT_FOOT:
                    case JOINT_RIGHT_FOOT:
                        ofSetColor(255, 0, 0);
                        ofDrawCircle(x, y, 20);
                        break;
                        
                    default:
                        ofSetColor(255);
                        ofDrawCircle(x, y, 10);
                        break;
                }*/
                ofDrawCircle(x, y, 20);
            }
        }
        
    }
    /*
    if (kinect.getNumTravkedUsers > 0) {
        ofxOpenNI user = kinect,getTrackedUser(0);
    }
    */
    /*
    ofSetLineWidth(2);
    ofSetColor(100, 200, 255);
    for (int i = 0; i < user.getNumLimbs; i++) {
        ofxOpenNILimb limb = user.getLimb((enum Limb)i);
        if (limb.isFound()) {
            float sX = limb.getStarJoint().getProjectivePosition().x;
            float sY = limb.getStarJoint().getProjectivePosition().y;
            float eX = limb.getEndJoint().getProjectivePosition().x;
            float eY = limb.getEndJoint().getProjectivePosition().y;
            ofDrawLine(sX, sY, eX, eY);
            
        }
    }
    */

}
//--------------------------------------------------------------
/*void ofApp::drawPointCloud(){
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
 
 }*/
//--------------------------------------------------------------
/*void ofApp::exit(){
  //  kinect.close();
    
    
}*/
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    /*switch (key) {
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
    }*/
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
