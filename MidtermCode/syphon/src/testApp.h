//
//  testApp.h
//  Spatial Media Midterm
//
//  Created by Ju Young Park on 3/12/13.
//
//

#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxSyphon.h"
#include "ofxSpacebrew.h"
#include "wish.h"
#include <fstream>

#endif

class testApp : public ofBaseApp{
	
public:
	
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void drawCircle(float x, float y, float z, bool flip, bool bigSize, int count);
	
    ofVec2f getRandomNumber();
    //void drawChampagne();
    bool isLocOverlapped(ofVec2f location);
    
    int getStringLength(int i);
    
    float counter;
    
    float circleX, circleY, circleD;
    int xGridNum;
    int yGridNum;
    bool mouseOver;
    bool circleSize;
    //ofImage sample;
    ofVec2f tempLoc, tempLoc2;
    //vector<string> data;
    
    
    vector<int> letterCount;
    //vector<ofVec2f> circleLoc;
    vector<ofVec2f> loc;
    float           nextLetterTime;
    int             lengthPos;
    int             lineCount;
    
    Spacebrew::Connection spacebrew;
    void onMessage( Spacebrew::Message & m );
    
    
    string allWishes;
    
    
    string message;
    vector<Wish> messages;
    
    vector<string> msgList;
    vector<int> msgLength;
    int counterWish;
    int index;
    float smallZ;
    float flowInc;
    bool isRandomTime;
    
    ofColor c;
    ofSoundPlayer mySound;
    ofVideoPlayer myPlayer;
    
    bool startPlaying;
    bool audioPlaying;
    bool drawCircles;
    bool afterParty;
    
    
    
    //syphon stuff----------------------------------------------
    
    
	float 	counterSy;
	bool	bSmooth;
	
    ofTexture tex;
    
	ofxSyphonServer mainOutputSyphonServer;
	//ofxSyphonServer individualTextureSyphonServer;
	
	ofxSyphonClient mClient;
};



