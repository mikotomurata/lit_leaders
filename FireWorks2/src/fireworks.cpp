//
//  fireworks.cpp
//  FireWorks2
//
//  Created by Owner on 2017/08/17.
//
//

#include "fireworks.hpp"
FireWorks::FireWorks(ofVec3f Pos,int color_count,int type){
    for(int i = 0; i<30; i++){
        pos_1[i] = Pos;
        pos_2[i] = Pos;
        
        sphere[i].setPosition(pos_1[i]);
        
        sphere[i].setRadius(1);
        
        sphere_2[i].setPosition(pos_2[i]);
        
        sphere_2[i].setRadius(1);
        
        speed_1[i]= ofVec3f(0,0,0);
        acc[i]= ofVec3f(0,0,0);
        
        color_count_ = color_count;
        
        type_ = type;
    }
    mass = 20;
    alpha_1=255;
    
}

void FireWorks::setup(){
    center = ofVec3f(0,0,0);
    flag = true;
    color_flag = true;
    force_2 = ofVec3f(0,1,0);
    for(int i=0; i<30; i++){
        
        if(type_ == 0){//丸
            speed_2[i].x=(cos(PI*12/180*i))*5;
            speed_2[i].y=(sin(PI*12/180*i))*5;
            speed_3[i].x=(cos(PI*12/180*i))*3;
            speed_3[i].y=(sin(PI*12/180*i))*3;
        }
        
        
        else if (type_== 1){//ハート
            speed_2[i].x=(8*sin(PI*12/180*i)*sin(PI*12/180*i)*sin(PI*12/180*i));
            speed_2[i].y=(6.5*cos(PI*12/180*i)-2.5*cos(2*(PI*12/180*i))-1*cos(3*(PI*12/180*i))-0.5*cos(4*(PI*12/180*i)));
            speed_3[i].x=(4*sin(PI*12/180*i)*sin(PI*12/180*i)*sin(PI*12/180*i));
            speed_3[i].y=(3.25*cos(PI*12/180*i)-1.25*cos(2*(PI*12/180*i))-0.5*cos(3*(PI*12/180*i))-0.25*cos(4*(PI*12/180*i)));
            
        }
        else if (type_ == 2){//ダイヤ
            speed_2[i].x=(5*cos(PI*12/180*i)*cos(PI*12/180*i)*cos(PI*12/180*i));
            speed_2[i].y=(7*sin(PI*12/180*i)*sin(PI*12/180*i)*sin(PI*12/180*i));
            speed_3[i].x=(3*cos(PI*12/180*i)*cos(PI*12/180*i)*cos(PI*12/180*i));
            speed_3[i].y=(4*sin(PI*12/180*i)*sin(PI*12/180*i)*sin(PI*12/180*i));
            
        }
        else if (type_ == 3){//謎
            speed_2[i].x=(6*cos(6*(PI*12/180*i)));
            speed_2[i].y=(6*sin(9*(PI*12/180*i)));
            speed_3[i].x=(3*cos(3*(PI*12/180*i)));
            speed_3[i].y=(3*sin(4.5*(PI*12/180*i)));
            
        }
        else if (type_ == 4){//楕円
            speed_2[i].x=(cos(PI*12/180*i))*5;
            speed_2[i].y=(sin(PI*12/180*i))*2.5;
            speed_3[i].x=(cos(PI*12/180*i))*2.5;
            speed_3[i].y=(sin(PI*12/180*i))*1.25;
            
        }
        else if (type_ == 5){//土星
            speed_2[i].x=(6*sin(9*(PI*12/180*i)));
            speed_2[i].y=(6*sin(9*(PI*12/180*i)));
            speed_3[i].x=(3*sin((3*PI*12/180*i)));
            speed_3[i].y=(3*sin(4.5*(PI*12/180*i)));
            
        }
        else if (type_ == 6){//花
            speed_2[i].x=3*(cos(PI*12/180*i)*(1+0.5*sin(5*(PI*12/180*i))+0.3*cos(10*(PI*12/180*i))));
            speed_2[i].y=3*(sin(PI*12/180*i)*(1+0.5*sin(5*(PI*12/180*i))+0.3*cos(10*(PI*12/180*i))));
            speed_3[i].x=2*(cos(PI*12/180*i)*(1+0.5*sin(5*(PI*12/180*i))+0.3*cos(10*(PI*12/180*i))));
            speed_3[i].y=2*(sin(PI*12/180*i)*(1+0.5*sin(5*(PI*12/180*i))+0.3*cos(10*(PI*12/180*i))));
            
        }
        
        
        
        
        
    }
    
}

void FireWorks::update(){
    for(int i=0; i<30; i++){
        
        if(pos_1[i].y>ofGetHeight()/3){
            flag=false;
        }
        if(flag == true){
            if(pos_1[i].y <= ofGetHeight()/3){
                acc[i] = force_2/mass;
                speed_1[i] += acc[i]*3;
                pos_1[i] += speed_1[i];
                pos_1[i].x += 2*cos(ofGetFrameNum()/2);
                pos_2[i] += speed_1[i];
                pos_2[i].x += 2*cos(ofGetFrameNum()/2);
            }
            buffer_pos = pos_1[0];
        }
        if (flag == false) {
            
            pos_1[i] += speed_2[i];//外側
            speed_2[i] .y -= 0.1;//垂れる
            pos_2[i] += speed_3[i];//内側
            speed_3[i].y -= 0.12;//垂れる
        }
        
    }
}

void FireWorks::display(){
    
    update();
    for(int i=0; i<30; i++){
        sphere[i].setPosition(pos_1[i]);
        sphere[i].setRadius(4);
        sphere_2[i].setPosition(pos_2[i]);
        sphere_2[i].setRadius(3);
        
        if (flag ==true) {
            ofSetColor(255, 255, 255);
            
        }
        else if (flag == false){//外側
            length_1 = (pos_1[0] - buffer_pos).length();
            alpha_1 = ofMap(length_1, 0, 500, 255, 0);
            
            if(color_count_ == 0){
                ofSetColor(255, 0, 0, alpha_1);
            }
            
            else if (color_count_ == 1){
                ofSetColor(255, 255, 0,alpha_1);
                
            }else if (color_count_ == 2){
                ofSetColor(255, 255, 0,alpha_1);
                
            }
            else if (color_count_ == 3){
                ofSetColor(60, 60, 255,alpha_1);
                
            }else if (color_count_ == 4){
                ofSetColor(255, 0, 0,alpha_1);
                
            }
            else if (color_count_ == 5){
                ofSetColor(120, 255, 120,alpha_1);
                
            }else if (color_count_ == 6){
                ofSetColor(190, 0, 255,alpha_1);
                
            }else if (color_count_ == 7){
                ofSetColor(255, 150, 60,alpha_1);
                
            }
            
        }
        sphere[i].draw();
        
        if(flag == true){
            ofSetColor(255, 255, 255);
            
        }
        else if (flag ==false){//内側
            if(color_count_ == 0){
                ofSetColor(255, 255, 0,alpha_1);
            }
            
            else if (color_count_ == 1){
                ofSetColor(60, 60, 255,alpha_1);
                
            }else if (color_count_ == 2){
                ofSetColor(255, 0, 0,alpha_1);
                
            }else if (color_count_ == 3){
                ofSetColor(255, 255 ,0,alpha_1);
                
            }else if (color_count_ == 4){
                ofSetColor(120, 255, 120,alpha_1);
                
            }else if (color_count_ == 5){
                ofSetColor(255, 0, 0,alpha_1);
                
            }else if (color_count_ == 6){
                ofSetColor(255, 150, 60,alpha_1);
                
            }else if (color_count_ == 7){
                ofSetColor(190, 0, 255,alpha_1);
                
            }
            
            
            
        }
        sphere_2[i].draw();
    }
    if (flag == true) {
        ofSetColor(0, 0, 0,50);
    }
    else if (flag == false){
        ofSetColor(0, 0, 0,30);
    };
    ofDrawRectangle(-1*ofGetWidth()/2, -1*ofGetHeight()/2, ofGetWidth()*3, ofGetHeight()*3);
}
