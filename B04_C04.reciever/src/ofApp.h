#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define PORT 8020

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
    
    ofxOscReceiver reciever;//受信するインスタンス
    ofPoint remoteMouse;//受信したマウスの座標を格納
    
    string mouseButtonState;//受信したマウスの状態
    
    
    
		
};

