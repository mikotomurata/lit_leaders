#pragma once

#include "ofMain.h"

#include "ofxLeapMotion2.h"//ofxLeapMotion2„Çí„Ç§„É≥„ÇØ„É´„Éº„Éâ
#define num 1000

class ofApp : public ofBaseApp{
private:
    int size_sphere = 0;
    float *volume;
    ofSoundPlayer soundplayer;
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void exit();//„Ç¢„Éó„É™„Ç±„Éº„Ç∑„Éß„É≥ÁµÇ‰∫ÜÊôÇ„Å´Âëº„Å≥Âá∫„Åï„Çå„Çã
    
    ofxLeapMotion leap;//LeapMotion„ÅÆ„É°„Ç§„É≥„ÇØ„É©„Çπ„Çí„Ç§„É≥„Çπ„Çø„É≥„ÇπÂåñ
    vector<ofxLeapMotionSimpleHand> simpleHands;//„Ç∑„É≥„Éó„É´„Å™Êâã„ÅÆ„É¢„Éá„É´„ÅÆvectorÈÖçÂàó
    
    ofEasyCam cam;//EasyCam„ÅÆ„Ç§„É≥„Çπ„Çø„É≥„Çπ
    
    vector<ofVec3f> fingerPos;
    vector<ofVec3f> handPos;
    ofSpherePrimitive sphere;

    
    int color_mode;
    
    ofImage image;
    
    ofVec3f pos[num];
    float noise[num];
    
    float a;
    
    float sph_pos_x,sph_pos_y,sph_pos_z;
    
    ofSpherePrimitive v;
    float p_x,p_y,p_z;
    
    
};
