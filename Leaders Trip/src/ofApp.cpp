
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    
    model.loadModel("SimpleEarth/Earth Planet.DAE");
    model.setPosition(0, 0, 0);
    model.setScale(1, -1, -1);
    light1.setPosition(0, 0, 0);
    light1.setPointLight();
    light1.setAmbientColor(ofFloatColor(255.0,255.0, 255.0,255.0));
    model.getMesh(0).clearNormals();
    model.setNormalizationFactor(-1.0);
    
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    cam.setOrientation(ofPoint(-20,0,0));
    glEnable(GL_DEPTH_TEST);//深さを有効
    glEnable(GL_NORMALIZE);//法線ベクトルの自動正規化
    
    model_path = "B_787_8.3ds";
    mAssimpModelLoader.setScale(0.1, 0.1, 0.1);
    mAssimpModelLoader.loadModel(model_path);
    
    ofTrueTypeFont::setGlobalDpi(25);
    verdana.load("verdana.ttf", 50);
    verdana.setLineHeight(24);
    verdana.setLetterSpacing(1.0);
    
    
    //    マレーシア
    Image[0].load("15720.jpg");
    Image[1].load("15718.jpg");
    Image[2].load("15719.jpg");
    //    シンガポール
    Image[3].load("15723.jpg");
    Image[4].load("15724.jpg");
    Image[5].load("15726.jpg");
    //    台湾
    Image[6].load("15714.jpg");
    Image[7].load("15715.jpg");
    Image[8].load("15716.jpg");
    //   イギリス
    Image[9].load("15729.jpg");
    Image[10].load("15732.jpg");
    Image[11].load("16091.jpg");
    //
    
    mode = 1;
    
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
    theta += 0.01;
    
    mAssimpModelLoader.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    cam.begin();
    ofSetColor(255);
    if (mode == 0) {
        verdana.drawString("1", 300, 300);
    }else if(mode == 1){
        verdana.drawString("2", 300, 300);
    }else if(mode == 2){
        verdana.drawString("3", 300, 300);
    }
    
    //    ofPushMatrix();
    //    ofTranslate(0, 0, 300);
    //    ofSetColor(0, 255, 255);
    //    verdana.drawString("MALAYSIA", 50, 25);
    //    ofPopMatrix();
    light1.enable();
    
    ofEnableDepthTest();
    ofEnableSmoothing();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    ofEnableSeparateSpecularLight();
    
    //    light1.draw();
    //    light2.draw();
    //    球の描画
    if (mode == 0) {//回る方
        ofPushMatrix();
        //        ofRotateY(angleEarth_1);
        ofRotateY(angleEarth/PI*180);
        angleEarth_1 = angleEarth/PI*180;
        ofPushMatrix();
        ofRotateY(90);
        
        model.drawFaces();
        ofPopMatrix();
        ofSetColor(255);
        ofDrawSphere(158, 150,133, 1);//大体の東京の位置
        //    ofDrawSphere(158, 150,33, 1);
        ofDrawSphere(50,25,250,1);//マレーシアの位置
        //    ofDrawSphere(52,25,155,1);
        ofDrawSphere(63, 5, 247, 1);//シンガポールの位置
        //    ofDrawSphere(63, 5, 147, 1);
        ofDrawSphere(-150, 208, -5, 1);//イギリスの位置
        //    ofDrawSphere(-150, 208, -105, 1);
        ofDrawSphere(120, 105,200, 1);//台湾の位置
        //    ofDrawSphere(120, 105, 100, 1);
        ofPopMatrix();
    }else if(mode == 1){//飛ぶ方
        ofPushMatrix();
        ofRotateY(angleEarth_1);
        ofPushMatrix();
        ofRotateY(90);
        model.drawFaces();
        ofPopMatrix();
        ofDrawSphere(158, 150,133, 1);//大体の東京の位置
        ofDrawSphere(50,25,250,1);//マレーシアの位置
        ofDrawSphere(63, 5, 247, 1);//シンガポールの位置
        ofDrawSphere(-150, 208, -5, 1);//イギリスの位置
        ofDrawSphere(120, 105,200, 1);//台湾の位置
        ofPopMatrix();
    }
    else if(mode == 2){//デジタルアート的なやつ
        ofPushMatrix();
        ofRotateY(ofGetFrameNum()/4);
        ofPushStyle();
        ofNoFill();
        ofSetColor(255, 255, 255, 100);
        ofDrawSphere(0, 0, 255);
        ofPopStyle();
        ofPopMatrix();
    }
    
    light1.disable();
    
    ofDisableDepthTest();
    ofDisableBlendMode();
    ofDisableSmoothing();
    ofDisableSeparateSpecularLight();
    // 手のこと
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
            //        ---------------------------------------------
            //          球の中心からの距離
            distSphere = ofDist(fingerPos.at(7).x, fingerPos.at(7).y, fingerPos.at(7).z, 0, 0, 0);
            //国からの距離
            distMY = ofDist(fingerPos.at(7).x, fingerPos.at(7).y, fingerPos.at(7).z,50,25,250);
            distSGP = ofDist(fingerPos.at(7).x, fingerPos.at(7).y, fingerPos.at(7).z, 63, 5, 247);
            distUK = ofDist(fingerPos.at(7).x, fingerPos.at(7).y, fingerPos.at(7).z, -150, 208, -5);
            distTP = ofDist(fingerPos.at(7).x, fingerPos.at(7).y, fingerPos.at(7).z,120, 105,200);
            
            ofPushMatrix();
            ofRotateX(-90);
            angleMY = atan2(0-25, 0-50);
            angleSGP = atan2(0-5, 0-65);
            angleTP = atan2(0-105, 0-120);
            angleUK = atan2(0-208, 0+150);
            ofPushMatrix();
            ofTranslate(158, 150, 133);
            planePoint = atan2(0-fingerPos.at(7).y, 0-fingerPos.at(7).x);
            ofPopMatrix();
            ofPopMatrix();
            ofPushMatrix();
            ofRotateX(-90);
            angleEarth = atan2(0-fingerPos.at(7).y, 0-fingerPos.at(7).x);
            ofPopMatrix();
            
            
            //          弧の半径
            
            radius = (ofDist(fingerPos.at(7).x, fingerPos.at(7).y, fingerPos.at(7).z, 158, 150,133))/2;
            
            light2.enable();
            light2.setPosition(0, -1*sin(theta)*radius/2, -1*cos(theta)*radius/2);
            light2.setPointLight();
            light2.setAmbientColor(ofFloatColor(255.0,255.0, 255.0,255.0));
            // mode別の動き
            if (mode == 0) {
                
            }else if (mode == 1){//飛行機飛ばす
                //仮の場所
                ofPushMatrix();
                ofRotateY(angleEarth_1);
                if (distSphere <= 255 && 230 <= distSphere) {
                    //弧の中心
                    ofPoint center;
                    center.x = (158+fingerPos.at(7).x)/2;
                    center.y = (150+fingerPos.at(7).y)/2;
                    center.z = (133+fingerPos.at(7).z)/2;
                    //弧の角度
                    ofPushMatrix();
                    ofTranslate(0, 0, 133);
                    angle = atan2(158-fingerPos.at(7).x, 150-fingerPos.at(7).y);
                    ofPopMatrix();
                    //東京の位置に対する傾き
                    ofPushMatrix();
                    ofTranslate(158, 150,133);
                    ofRotateY(-90);
                    ofRotateX(-90);
                    endPoint = atan2(fingerPos.at(7).z,fingerPos.at(7).x+158);
                    ofPopMatrix();
                    //X軸対する弧の傾き
                    ofPushMatrix();
                    ofRotateY(-90);
                    ofTranslate(0, 0, 133);
                    angle2 = atan2(fingerPos.at(7).x, 0-fingerPos.at(7).y);
                    ofPopMatrix();
                    ofPushMatrix();
                    ofTranslate(center.x, center.y, center.z);
                    ofRotateZ(-1*angle/PI*180+90);
                    ofRotateX(angle2/PI*180+180);
                    
                    //触れた座標の代入
                    earthPoint.x = fingerPos.at(7).x;
                    earthPoint.y = fingerPos.at(7).y;
                    earthPoint.z = fingerPos.at(7).z;
                    
                    //    弧を描く
                    for (float i = 0; i < PI; i+=0.001) {
                        ofSetColor(255);
                        ofDrawCircle(cos(i)*radius, sin(i)*radius, 1);
                    }
                    
                    //    飛行機
                    if (radius > 0) {
                        if (theta < PI){
                            ofPushMatrix();
                            ofRotateY(90);
                            ofRotateX(180);
                            ofSetColor(255);
                            mAssimpModelLoader.setPosition(0,-1*sin(theta)*radius, -1*cos(theta)*radius);
                            mAssimpModelLoader.drawWireframe();
                            
                            ofPopMatrix();
                        }
                    }
                    //画像を出す
                    ofPopMatrix();
                    if (distMY < 25) {
                        for (int i = 0; i < 3; i++) {
                            //                            ofSetColor(255, 255, 255);
                            //                            verdana.drawString("MALAYSIA", -300, 250);
                            ofPushMatrix();
                            ofTranslate(fingerPos.at(7).x,fingerPos.at(7).y,fingerPos.at(7).z);
                            ofRotateY(angleMY/PI*180);
                            Image[i].draw(cos((PI/3)*i+PI/6)*100, sin((PI/3)*i+PI/6)*100, 100, 50);
                            ofPushMatrix();
                            ofTranslate(-1*fingerPos.at(7).x,-1*fingerPos.at(7).y,0);
                            //                            ofTranslate(-300, -300);
                            ofRotateY(180);
                            ofSetColor(255, 255, 255);
                            verdana.drawString("MALAYSIA", -100, 25);
                            ofPopMatrix();
                            ofPopMatrix();
                            
                        }
                    }else if (distSGP < 25) {
                        for (int i = 3; i < 6; i++) {
                            //                            ofSetColor(255, 255, 255);
                            //                            verdana.drawString("SINGAPOLE", -300, 250);
                            ofPushMatrix();
                            ofTranslate(fingerPos.at(7).x,fingerPos.at(7).y,fingerPos.at(7).z);
                            ofRotateY(angleSGP/PI*180);
                            Image[i].draw(cos((PI/3)*(i-2)+PI/6)*100, sin((PI/3)*(i-2)+PI/6)*100, 100, 50);
                            ofPushMatrix();
                            ofTranslate(-1*fingerPos.at(7).x,-1*fingerPos.at(7).y,0);
                            ofRotateY(180);
                            ofSetColor(255, 255, 255);
                            verdana.drawString("SINGAPOLE", -150, 5);
                            ofPopMatrix();
                            ofPopMatrix();
                            
                        }
                        
                    }else if (distTP < 25) {
                        for (int i = 6; i < 9; i++) {
                            ofPushMatrix();
                            ofTranslate(fingerPos.at(7).x,fingerPos.at(7).y,fingerPos.at(7).z);
                            ofRotateY(angleTP/PI*180+180);
                            Image[i].draw(-1*cos((PI/3)*(i-5)+PI/6)*100, sin((PI/3)*(i-5)+PI/6)*100, 100, 50);
                            ofPushMatrix();
                            ofTranslate(-1*fingerPos.at(7).x,-1*fingerPos.at(7).y,0);
                            //                            ofRotateY(180);
                            ofSetColor(255, 255, 255);
                            verdana.drawString("TAIWAN", 120, 105);
                            ofPopMatrix();
                            ofPopMatrix();
                        }
                    }else if (distUK < 25) {
                        for (int i = 9; i < 12; i++) {
                            ofPushMatrix();
                            ofTranslate(fingerPos.at(7).x,fingerPos.at(7).y,fingerPos.at(7).z);
                            ofRotateY(angleUK/PI*180);
                            Image[i].draw(cos((PI/3)*(i-8)+PI/6)*100, sin((PI/3)*(i-8)+PI/6)*100, 100, 50);
                            ofPushMatrix();
                            ofTranslate(-1*fingerPos.at(7).x,-1*fingerPos.at(7).y,0);
                            //                            ofRotateY(180);
                            ofSetColor(255, 255, 255);
                            verdana.drawString("ENGLAND", -150, 208);
                            ofPopMatrix();
                            ofPopMatrix();
                            
                        }
                    }
                }else{
                    theta = 0;
                    
                    ofPushMatrix();
                    ofTranslate(158, 150, 133);
                    ofRotateY(90);
                    ofRotateX(-90);
                    ofRotateY(-90-1*(planePoint/PI*180));
                    ofSetColor(255);
                    mAssimpModelLoader.setPosition(0, 0,0);
                    mAssimpModelLoader.drawWireframe();
                    ofPopMatrix();
                }
                ofPopMatrix();
            }else if (mode == 2){//フレームのところ
                ofPushMatrix();
                ofRotateY(ofGetFrameNum()/4);
                ofPushMatrix();
                ofTranslate(0, 0, 33);
                ofSetColor(255, 255, 255);
                verdana.drawString("TOKYO", 158, 150);
                ofPopMatrix();
                ofDrawLine(0, 0, 0, 158, 150,33);
                
                //地名描く
                
                ofPushMatrix();
                ofTranslate(0, 0, 155);
                ofSetColor(255, 255, 255);
                verdana.drawString("MALAYSIA", 52, 25);
                ofPopMatrix();
                ofDrawLine(0, 0, 0, 50,25, 155);
                
                ofPushMatrix();
                ofTranslate(0, 0, 147);
                ofSetColor(255, 255, 255);
                verdana.drawString("SINGAPOLE", 63, 5);
                ofPopMatrix();
                ofDrawLine(0, 0, 0,63, 5, 147);
                
                ofPushMatrix();
                ofTranslate(0, 0, 100);
                ofSetColor(255, 255, 255);
                verdana.drawString("TAIWAN", 120, 105);
                ofPopMatrix();
                ofDrawLine(0, 0, 0, 120, 105, 100);
                
                ofPushMatrix();
                ofTranslate(0,0,-105);
                ofSetColor(255, 255, 255);
                verdana.drawString("ENGLAND", -150, 208);
                ofPopMatrix();
                ofDrawLine(0, 0, 0, -150, 208, -105);
                
                ofPopMatrix();
                if (distSphere <= 255 && 230 <= distSphere) {
                    ofDrawLine(0, 0, 0, fingerPos.at(7).x, fingerPos.at(7).y, fingerPos.at(7).z);
                }
            }
        }
        
        ofPopMatrix();
    }
    ofPopMatrix();
    //    ofPushMatrix();
    //    ofTranslate(0, 0, 300);
    //    ofSetColor(255, 255, 255);
    //    verdana.drawString("MALAYSIA", 10, 25);
    //    ofPopMatrix();
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

