#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
     ofSetVerticalSync(true);
    
     cam.setOrientation(ofPoint(-20,0,0));
     
     glEnable(GL_DEPTH_TEST);
     glEnable(GL_NORMALIZE);
     
     leap.open();
    
    ofSetFrameRate(60);
    
    ofEnableAlphaBlending();
    
    soundplayer.load("sakuranoame.mp3");
    soundplayer.setLoop(true);
    soundplayer.setVolume(1.0);
    soundplayer.play();
    
    image.load("00000124.png");
    
    /////////////////////////////////////////////////////////////
    //花びら
    for(int i = 0; i < num; i++){
        pos[i].set(0+ofRandom(-10*i,i*5),0+ofRandom(i,i*10),0);
        noise[i]=ofRandom(3);
        
    }
    ////////////////////////////////////////////////////////////
    
   
     
    /////////////////////////////////////////////////////////////
    //球を飛ばす
    
    if(simpleHands.size()==2){
        sph_pos_x = (handPos.at(0).x + handPos.at(1).x)/2;
        sph_pos_y = (handPos.at(0).y + handPos.at(1).y)/2;
        sph_pos_z = (handPos.at(0).z + handPos.at(1).z)/2;

        sphere.setPosition(sph_pos_x,sph_pos_y,sph_pos_z);
       
    }
    
    
    }

//--------------------------------------------------------------
void ofApp::update(){
    
     
     
     
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
    
    
    
    ////////////////////////////////////////////////////////
    //音　球体
    leap.markFrameAsOld();
    volume = ofSoundGetSpectrum(1);
    size_sphere = volume[0]*800;
    
    color_mode = (int)ofGetElapsedTimef()%2;
    
    for(int i = 0; i < num; i++){
        pos[i].x +=ofRandom(6);
        pos[i].y +=ofRandom((-6));
        //pos[i].z +=(-10,10);
        if(pos[i].y<-1*ofGetHeight()/2 ){
            pos[i].y = ofGetHeight();
        }
        else if(pos[i].x>ofGetWidth() ){
            pos[i].x = -1*ofGetWidth();
        }
        
        
    }
    
    //
    
    if(simpleHands.size()==2){
        sph_pos_z -= 9;
    sphere.setPosition(sph_pos_x,sph_pos_y,sph_pos_z);
        
        if(sph_pos_z<-4000){
            sph_pos_z = (handPos.at(0).z + handPos.at(1).z)/2;
            
        }
    }
    
    
}


//--------------------------------------------------------------
void ofApp::draw(){
    
     ofBackground(0);
     cam.begin();
    
    
    
    //ofSetColor(255, 192, 203,255);
    ofSetColor(255, 255, 255,255);
    for(int i = 0; i < num;i++){
        ofPushMatrix();
        ofTranslate(pos[i].x, pos[i].y);
        ofRotateX(ofGetFrameNum()*noise[i]);
        ofRotateY(ofGetFrameNum()*noise[i]);
        ofRotateZ(ofGetFrameNum()*noise[i]);
        
        
        image.draw(0,0,pos[i].z,50,40);
        ofTranslate(-1*pos[i].x, -1*pos[i].y);
        ofPopMatrix();
    }
    
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
     
         ofSetColor(100);
         ofDrawSphere(fingerPos.at(20*i+4*f+3), 10);
         
         
         ofDrawLine(fingerPos.at(20*i+4*f+0), fingerPos.at(20*i+4*f+1));
         ofDrawLine(fingerPos.at(20*i+4*f+1), fingerPos.at(20*i+4*f+2));
         ofDrawLine(fingerPos.at(20*i+4*f+2), fingerPos.at(20*i+4*f+3));
     
       }
     }
    
    if(simpleHands.size()==2){
       float distance=sqrt(pow(handPos.at(0).x - handPos.at(1).x,2)
                           +pow(handPos.at(0).y - handPos.at(1).y,2)
                           +pow(handPos.at(0).z - handPos.at(1).z,2));
        
        if(color_mode == 1){
            ofSetColor(255, 192, 203,255);}
        if(color_mode == 0){
            ofSetColor(144, 238, 144,255);}

        
        
        
        sphere.setRadius(distance/6 + size_sphere);
        sphere.drawWireframe();
            }
    
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
