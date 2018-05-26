#pragma once

#include "ofMain.h"

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
    
    void drawTriangle(ofVec2f pos1, ofVec2f pos2,ofVec2f pos3);
    ofVec2f pos1, pos2, pos3;
    ofVec2f centerTriangle(ofVec2f pos1, ofVec2f pos2, ofVec2f pos3);
    ofVec2f posCenter ;
    
    ofBoxPrimitive box[100];
    ofEasyCam cam;
    int size = 50;
    
    
		
};
