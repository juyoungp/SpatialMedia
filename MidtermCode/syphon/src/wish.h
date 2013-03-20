//
//  wish.h
//  newyearsmsg
//
//  Created by Jess on 3/5/13.
//
//

#ifndef __newyearsmsg__wish__
#define __newyearsmsg__wish__

#include <iostream>
#include "ofMain.h"

#endif /* defined(__newyearsmsg__wish__) */


class Wish{
    
public:
    
    void init(string newMsg);
    //void update();
    void display();
    ofVec2f getMsgLoc();
    ofVec2f getRandomNumberY();
    int getStringLength();
    string getString();
    string myWish;
    //ofVec2f textLoc;
    int x,y;
    ofVec2f msgLoc;
    ofTrueTypeFont myfont;
    vector<ofVec2f> locList;
    
    
};