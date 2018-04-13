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
    
    /*
     ofSoundPlayer sound;
    float* volume;
    float* fftsmoothed;//FFT解析の結果を格納する配列
    int nBandstoGet;//FFT解析の精度
     */
    
    ofMesh myMesh;
    ofEasyCam cam;
    ofLight light;
    
    

    
    
		
};
