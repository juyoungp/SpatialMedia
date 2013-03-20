//
//  testApp.cpp
//  Spatial Media Midterm
//
//  Created by Ju Young Park on 3/12/13.
//
//

#include "testApp.h"

const int width = 800;
const int height = 600;

//--------------------------------------------------------------
void testApp::setup(){
	
    //syphon stuff----------------------------------------------
    
    ofSetWindowTitle("New Year's Party");
    
	mainOutputSyphonServer.setName("Jess's Screen");
	//individualTextureSyphonServer.setName("Texture Output");

	mClient.setup();
    
    mClient.setApplicationName("Simple Server");
    mClient.setServerName("");
	
    tex.allocate(width, height, GL_RGBA);
    
    //graphic part ---------------------------------------------
    
    
    ofSetCircleResolution(50);
	ofBackground(0);
    
    ofSetFrameRate(30); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
    
    xGridNum = 40;
    yGridNum = 28;
    
    mouseOver = false;
    circleSize = false;
    afterParty = false;
    
    lineCount      = 0;
    lengthPos = 1;
    drawCircles = true;
    mySound.loadSound("partymusic_audio.wav");
    mySound.setLoop(true);
    myPlayer.loadMovie("movies/countdownfinal.mov");
    
    
    
    string host = "sandbox.spacebrew.cc";
    string name = "new_years_wish";
    string description = "tell me your wish of 2014!";
    
    message = "";
    
    spacebrew.connect( host, name, description );
    spacebrew.addSubscribe( "text", "string" );
    Spacebrew::addListener(this, spacebrew);
    
    counterWish = 200;
    index = 0;
    for(int i=0; i<counterWish; i++){
        Wish* wish = new Wish();
        messages.push_back(*wish);
        messages[i].init("");
    }
    
    smallZ = 0;
    flowInc = 0;

    
}

//--------------------------------------------------------------
void testApp::update(){
    if(startPlaying){
    myPlayer.update();
    }
    counter = counter + 0.05f;
    }

//--------------------------------------------------------------
void testApp::draw(){
	
    
    ofSetColor(255);
    
    
    
    loc.clear();
    msgLength.clear();
    
    for(int i= 0; i<= index; i++){

        messages[i].display();
        loc.push_back(messages[i].getMsgLoc());
        msgLength.push_back(messages[i].getStringLength());
    }
    
    
    for(int i = 0; i < yGridNum; i++){
        for(int j= 0; j < xGridNum; j++){
            
            circleD = ofGetWidth()/(xGridNum*2);
            
            circleX = circleD+ 2*j*circleD;
            circleY = circleD+ 2*i*circleD;
            tempLoc2.x = circleX;
            tempLoc2.y = circleY;
            
            
            if(isLocOverlapped(tempLoc2)){
                mouseOver = true;
            }
            else{ mouseOver = false;}
            
            if(drawCircles){
                drawCircle(circleX, circleY, circleD, mouseOver, circleSize, i);
            }
            
            
        }
        
        
    }
    
    
    if(startPlaying){
        
        myPlayer.draw(0, 0, ofGetWidth()/2, ofGetHeight());
        myPlayer.draw(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight());
        myPlayer.play();
    } else {
        myPlayer.stop();
    }
    
    
    //if(audioPlaying){
        
      //  mySound.play();
    //} else {
      //  mySound.stop();
    //}
    
    // Syphon Stuff--------------------------------------------
    
    ofSetColor(255, 255, 255);
    
    ofEnableAlphaBlending();
    
    mClient.draw(50, 50);
    
	mainOutputSyphonServer.publishScreen();

    
    
}





bool testApp::isLocOverlapped(ofVec2f location){
    for(int j=0; j<loc.size(); j++){
        if(msgLength[j]>0){
            if((loc[j].x>= (location.x - ((msgLength[j]-1) * circleD)) &&
            loc[j].x<= (location.x + ((msgLength[j]+2) * circleD))) &&
           (loc[j].y >= (location.y - (circleD*3))) &&
           (loc[j].y <= (location.y + (circleD*3)))){
            
                return true;
            }
            
        }
        
        
        
        
    }
    
    //lengthPos =1;
    return false;
}






void testApp::drawCircle(float x, float y, float z, bool flip, bool bigSize, int count){
    drawCircles = true;
    ofPushMatrix();
    ofEnableAlphaBlending();
    
    ofTranslate(x, y);
    if(mouseOver && !afterParty) { ofRotateY(sin(counter)*90); }
    
    if(bigSize && afterParty){
        z = z + 5 * sin(counter*10);
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        ofFill();
        ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    
    }
    ofSetColor(167,140,37);
    ofFill();
	//ofSetHexColor(0xCCCCCC);
	ofCircle(0, 0, z);
    
    //-----------------small dot
    
    smallZ = z - ofRandom(5);
    //flowInc = ofRandom(-3,3);
    ofSetColor(230,180,140);
    ofFill();
    ofCircle(flowInc, 0, smallZ);
    
    
    ofPopMatrix();

    
	
}

//--------------------------------------------------------------
void testApp::onMessage( Spacebrew::Message & m ){
    
    message = ofToString(m.value);
    
    
    //cout<<index<<message<<endl;
    
    if(message.compare("s") == 0 || message.compare("S")==0){
        drawCircles = !drawCircles;
        audioPlaying = !audioPlaying;
        //startPlaying = !startPlaying;
        afterParty = true;
        mySound.play();
        
        
        myPlayer.stop();
        circleSize = true;
        
    } else if(message.compare("v") == 0 || message.compare("V")==0){
        drawCircles = !drawCircles;
        startPlaying = !startPlaying;
        mySound.stop();
        circleSize = false;
        
    } else {
        
        index++;
        
        msgList.push_back(message);
        messages[index].init(message);
        allWishes += message[index];
        
    }
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){

    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}
