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
    
    model_path = "B_787_8.3ds";
    mAssimpModelLoader.setScale(0.5, 0.5, 0.5);
    mAssimpModelLoader.loadModel(model_path);
    
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
    
    mAssimpModelLoader.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);

    cam.begin();

    light.enable();
    
    ofEnableDepthTest();
    ofEnableSmoothing();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    ofEnableSeparateSpecularLight();
    
    
    light.draw();
    ofPushMatrix();
//    ofRotateY(angle/PI*360);
    ofRotateY(90);
    model.drawFaces();
    ofPopMatrix();
    
    ofDrawSphere(158, 150,133, 1);//大体の東京の位置
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
            
            ofSetColor(255, 0, 0);//人差し指
            ofDrawSphere(fingerPos.at(7), 10);
            
            ofSetColor(0,0,255);
            ofDrawSphere(fingerPos.at(20*i+4*f+3), 10);
            
            ofDrawLine(fingerPos.at(20*i+4*f+0), fingerPos.at(20*i+4*f+1));
            ofDrawLine(fingerPos.at(20*i+4*f+1), fingerPos.at(20*i+4*f+2));
            ofDrawLine(fingerPos.at(20*i+4*f+2), fingerPos.at(20*i+4*f+3));
            
            //          球の中心からの距離
            dist = ofDist(fingerPos.at(7).x, fingerPos.at(7).y, fingerPos.at(7).z, 0, 0, 0);
            //          弧の半径
            radius = (ofDist(fingerPos.at(7).x, fingerPos.at(7).y, fingerPos.at(7).z, 300, 0, 0))/2;
            
            if (dist <= 250 && 230 <= dist) {
                //                ofSetColor(255, 0, 0);
                //                ofDrawSphere(100, 0, 0, 50);
                //          弧の中心
                ofPoint center;
                center.x = (300+fingerPos.at(7).x)/2;
                center.y = fingerPos.at(7).y/2;
                center.z = fingerPos.at(7).z/2;
                
                angle = atan2(200-fingerPos.at(7).x, 0-fingerPos.at(7).y);
                //(200, 0)に対する傾き
                ofPushMatrix();
                ofTranslate(200, 0);
                ofRotateY(-90);
                ofRotateX(-90);
                endPoint = atan2(fingerPos.at(7).z,fingerPos.at(7).x+300);
                //            cout << endPoint/PI*180 << endl;
                ofPopMatrix();
                //            X軸対する傾き
                ofPushMatrix();
                ofRotateY(-90);
                angle2 = atan2(fingerPos.at(7).x, 0-fingerPos.at(7).y);
                ofPopMatrix();
                ofPushMatrix();
                ofTranslate(center.x, center.y, center.z);
                ofRotateZ(-1*angle/PI*180+90);
                
                ofRotateX(angle2/PI*180+180);
                
                theta +=0.01;
                //    弧を描く
                for (float i = 0; i < PI; i+=0.001) {
                    ofSetColor(255);
                    ofDrawCircle(cos(i)*radius, sin(i)*radius, 1);
                }
                //    飛行機
                if (radius > 0) {
                    if (theta < PI){
                        ofPushMatrix();
                        ofRotateY(-90);
                        ofSetColor(255);
                        mAssimpModelLoader.setPosition(0,sin(theta)*radius, -1*cos(theta)*radius);
                        mAssimpModelLoader.drawWireframe();
//                        ofSetColor(255, 120);
//                        ofDrawCircle(cos(theta)*radius, sin(theta)*radius, 25);
                        ofPopMatrix();
                    }
                }
                ofPopMatrix();

            }else{
                theta = 0;
                ofPushMatrix();
                ofRotateX(-90);
                angle3 = atan2(0-handPos.at(1).y, 0-handPos.at(1).x);
                ofPopMatrix();
                cout << angle/PI*180 << endl;
            }
        }
        ofPopMatrix();
    }
    
    
    cam.end();

}
//--------------------------------------------------------------
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
