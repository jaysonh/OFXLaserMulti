#pragma once

#include "ofMain.h"
#include "ofxLaserManager.h"
#include "ofxLaserDacEtherdream.h"
#include "ofxGui.h"

struct dac_broadcast {
    uint8_t mac_address[6];
    uint16_t hw_revision;
    uint16_t sw_revision;
    uint16_t buffer_capacity;
    uint32_t max_point_rate;
    struct dac_status status;
} __attribute__ ((packed));

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed  (int key);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    void showLaserEffect(int effectnum);
    
    ofParameter<int> currentLaserEffect;
    int numLaserEffects;
    
    ofxLaser::Manager laser;
    ofxLaser::DacEtherdream dac;
    bool drawingShape = false;
    int laserWidth;
    int laserHeight;
    
    void searchForDacs();
    
    
    vector<ofPolyline> polyLines;
    
    float elapsedTime; 
    
};

