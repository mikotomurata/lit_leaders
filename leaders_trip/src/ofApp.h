#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofxLeapMotion2.h"

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
    
    void exit();
    
    ofxLeapMotion leap;
    vector<ofxLeapMotionSimpleHand> simpleHands;//シンプルな手のモデルのvecter配列
    vector<ofVec3f> fingerPos;
    vector<ofVec3f> handPos;
    ofSpherePrimitive sphere;
    
    ofxAssimpModelLoader model;
    ofxAssimpModelLoader mAssimpModelLoader;
    string model_path;
    ofMesh mesh;
    ofLight light;
    float dist, radius, angle, theta, endPoint, angle2, angle3;
    
    
    
    ofEasyCam cam;
		
};