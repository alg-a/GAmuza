#pragma once

#include "ofMain.h"

#include "ofxLua.h"

class ofApp : public ofBaseApp, ofxLuaListener {
    
public:
    
    // main
    void setup();
    void update();
    void draw();
    void exit();
    
    // input
    void keyPressed(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
};
