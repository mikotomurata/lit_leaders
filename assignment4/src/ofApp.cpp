#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    
    ofEnableDepthTest();//深度テストを有効

    glPointSize(5);//点の大きさを指定

    a = 0;

    //面からメッシュを作成
    myMesh = ofPlanePrimitive(2000, 2000, 100, 100).getMesh();

    ofTrueTypeFont::setGlobalDpi(300);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //getVertices().size()は頂点の数を取得
    for (int i = 0; i < myMesh.getVertices().size(); i++) {
        ofVec3f point = myMesh.getVertices()[i]/400.0;
        float z = ofNoise(point.x, point.y, ofGetElapsedTimef()) * 200.0;
        myMesh.setVertex(i, ofVec3f(myMesh.getVertices()[i].x,myMesh.getVertices()[i].y, z));
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
   if (a%4 == 0) {
        ofDrawBitmapString("OF_PRIMITIVE_POINTS", 50, 50 );
    }else if (a%4 == 1){
        myMesh.setMode(OF_PRIMITIVE_LINES);
        ofDrawBitmapString("OF_PRIMITIVE_LINES", 50, 50  );
    }else if(a%4 == 2){
        myMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        ofDrawBitmapString("OF_PRIMITIVE_TRIANGLE_STRIP",50, 50  );
    }else if(a%4 == 3){
        myMesh.setMode(OF_PRIMITIVE_TRIANGLES);
         ofDrawBitmapString("OF_PRIMITIVE_TRIANGLES", 50, 50  );
    }
    cam.begin();
    

    ofRotateX(90);

    myMesh.draw();

    if (a%4 == 0) {
        myMesh.setMode(OF_PRIMITIVE_POINTS);
//        ofDrawBitmapString("OF_PRIMITIVE_POINTS", 1200, 1200 );
    }else if (a%4 == 1){
        myMesh.setMode(OF_PRIMITIVE_LINES);
    }else if(a%4 == 2){
        light.enable();
        light.setPosition(-100, -500,100);
        light.draw();
        myMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    }else if(a%4 == 3){
        myMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    }
//
    cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == ' ') {
        a ++;
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
