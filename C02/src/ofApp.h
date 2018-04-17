#pragma once

#include "ofMain.h"

#include "ofxOpenNI.h"

class ofApp : public ofBaseApp{
private:
    ofxOpenNI kinect;

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
    
    ofPoint p[2];
    ofPoint preP[2];
    float acc[2];
    int mode;
    
    /*
     void exit();
    void drawPointCloud();
    ofxKinect kinect;
    int kinectAngle;
    ofEasyCam cam;
    */
		
};