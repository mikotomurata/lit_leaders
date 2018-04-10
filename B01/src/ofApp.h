#pragma once

#include "ofMain.h"
#define NUM 150

class ofApp : public ofBaseApp{

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
		
    ofEasyCam cam;
    
    ofBoxPrimitive box,mBox[NUM];
    
    int boxSize;
    
    //座標を保存する変数
    ofVec2f p, vec;
    
    ofImage BackgroundImage;
    ofSoundPlayer soundplayer;
    
    
};

