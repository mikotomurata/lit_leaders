#pragma once

#include "ofMain.h"
#define NUM 100

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
		
    int a = ofGetWidth()/8;
    int b = ofGetHeight()/6;
    
    int x;
    int y;
    int xx;
    int yy;
    
    int click = 0;
    ofEasyCam cam;
    
    int pos1 = ofRandom(-500,500);
    int pos2 = ofRandom(-500,500);
    int pos3 = ofRandom(-500,500);
    
    ofBoxPrimitive box, abox[NUM];
    };
