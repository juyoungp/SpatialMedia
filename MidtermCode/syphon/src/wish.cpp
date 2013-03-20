//
//  wish.cpp
//  newyearsmsg
//
//  Created by Jess on 3/5/13.
//
//

#include "wish.h"

void Wish::init(string newMsg){
    
    //textLoc.set(100,100);
    //msgLoc.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    msgLoc.x = ofRandom(200, ofGetWidth()-200);
    msgLoc.y = ofRandom(100, ofGetHeight()-100);

    locList.push_back(msgLoc);
    
    myWish = newMsg;
    
}

ofVec2f Wish::getRandomNumberY(){
    msgLoc.y +=70;
    
    
}


ofVec2f Wish::getMsgLoc(){
    return msgLoc;
    
}

string Wish::getString(){
    return myWish;

}

int Wish::getStringLength(){
    return myWish.length();
}

void Wish::display(){
    
    for(int i =0; i<locList.size(); i++){
        if(locList[i].y == msgLoc.y){
            msgLoc.y = ofRandom(100, ofGetHeight()-100);
        } else if(locList[i].x == msgLoc.x){
            msgLoc.x = ofRandom(200, ofGetWidth()-200);
        }
    }
    
    ofSetColor(225);
    myfont.loadFont("Helvetica Neue CE 75 Bold.ttf", 22);
    myfont.drawString(myWish, msgLoc.x-120, msgLoc.y);
    
    
}