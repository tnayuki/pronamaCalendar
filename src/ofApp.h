#pragma once

#include "ofMain.h"
#include "ofxEtherdream.h"

class ofApp : public ofBaseApp {
private:
    ofTrueTypeFont verdana;
    
    ofxIlda::Frame ildaFrame;
    ofxEtherdream etherdream;
    
    void drawStringToIldaFrame(std::string str, float x, float y, ofColor color);
    
public:
    void setup();
//    void update();
    void draw();

//    void keyPressed(int key);
//    void keyReleased(int key);
//    void mouseMoved(int x, int y );
//    void mouseDragged(int x, int y, int button);
//    void mousePressed(int x, int y, int button);
//    void mouseReleased(int x, int y, int button);
//    void windowResized(int w, int h);
//    void dragEvent(ofDragInfo dragInfo);
//    void gotMessage(ofMessage msg);
};
