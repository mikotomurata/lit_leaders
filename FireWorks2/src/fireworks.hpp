//
//  fireworks.hpp
//  FireWorks2
//
//  Created by Owner on 2017/08/17.
//
//

#ifndef fireworks_hpp
#define fireworks_hpp

#include <stdio.h>
#include "ofMain.h"

class FireWorks{
public:
    ofVec3f pos_1[30],pos_2[30];//pos_1が外側
    ofSpherePrimitive sphere[30],sphere_2[30];
    ofVec3f speed_1[30],speed_2[30],speed_3[30];
    ofVec3f acc[30];
    ofVec3f force_2;
    ofVec3f center;
    ofVec3f buffer_pos;
    
    float mass;
    bool color_flag;
    bool flag;
    float length_1;
    float alpha_1,alpha_2;
    
    
    FireWorks(ofVec3f Pos,int color_count,int type);
    FireWorks(){};
    ~FireWorks(){};
    
    void setup();
    void update();
    void display();
    
    int color_count_;
    int type_;
};


#endif /* fireworks_hpp */
