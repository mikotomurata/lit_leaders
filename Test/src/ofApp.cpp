#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    
    /*ofEnableAlphaBlending();
    ofSetCircleResolution(60);
    ofBackground(0, 0, 0);
    
    ofSetFrameRate(60);
    rotation = 0;*/
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    //rotation += mouseX / 4.0;
    
    
    /*int a, b, sign, result, i;
        
        for(i = 0; i < 5; i++)
        {
            cout << "第１項 > ";
            cin >> a;
            cout << "第２項 > ";
            cin >> b;
            cout << "どれをしますか（1：加算，2：減算，3：乗算，4：除算） > ";
            cin >> sign;
            
            switch(sign)
            {
                case 1:
                    result = a + b; break;
                case 2:
                    result = a - b; break;
                case 3:
                    result = a * b; break;
                case 4:
                    result = a / b; break;
                default:
                    cout << "真面目にせんかい！" << endl;
                    continue;
            }
            
            cout << "答えは " << result << " です。" << endl;
        }
        return 0;
    */
    int a;
    
    cout << "何か値を入れてね > ";
    cin >> a;
    
    cout << "その数を３で割った余りは"
    << a % 3 << " です。" << endl;
    
    return 0;
    
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
   /* cam.begin();
    ofRotateZ(rotation);
    
    ofSetColor(0, 127, 255, 200);
    ofDrawCircle(100, 0, mouseY / 2.0);
    ofSetColor(255, 127, 0, 200);
    ofDrawCircle(-100, 0, mouseY / 2.0);
    
    
    cam.end();
    */

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
