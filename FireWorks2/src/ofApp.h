#pragma once

#include "ofMain.h"

#include "fireworks.hpp"
#include "fireworks_2.hpp"

#include <iostream>
#include <vector>


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
    
    FireWorks* fireworks;
    vector <FireWorks*> fireworks_;
    
    FireWorks_2* fireworks_2;
    vector <FireWorks_2*> fireworks_2_;
    
    
    
    int count,count_2;
    int start,start_2;
    
    ofLight light;
		
};
