#include "ofApp.h"

#include "ofxDate.h"

void ofApp::drawStringToIldaFrame(std::string str, float x, float y, ofColor color) {
    vector <ofTTFCharacter> paths = verdana.getStringAsPoints(str);
    for (int i = 0; i < paths.size(); i++){
        vector <ofPolyline> polylines = paths[i].getOutline();
        for (int j = 0; j < polylines.size(); j++){
            ildaFrame.params.output.color = color;
            ofxIlda::Poly poly = ofxIlda::Poly(color);
            poly.setClosed(true);
            for (int k = 0; k < polylines[j].size(); k++){
                poly.lineTo(polylines[j][k].x * 0.004 + x, polylines[j][k].y * 0.004 + y);
            }
            ildaFrame.addPoly(poly);
        }
    }
}

void ofApp::setup(){
    etherdream.setup();

    verdana.loadFont("verdana.ttf", 18, false, false, true);

    for (int i = 0; i < 7; i++) {
        drawStringToIldaFrame(std::string(1, "SMTWTFS"[i]), 0.05 + i * 0.13, 0.25, i == 0 ? ofColor::red : ofColor::green);
    }
    
    char buf[3];
    ofxDate date = ofxDate(ofGetYear(), ofGetMonth(), 1);
    int w = date.getWeekday();
    for (int i = 0; i < date.daysPerMonth(); i++) {
        sprintf(buf, "%d", i + 1);
        drawStringToIldaFrame(buf, 0.05 + ((i + w) % 7) * 0.13, 0.35 + 0.1 * ((i + w) / 7), (i + w) % 7 == 0 ? ofColor::red : ofColor::green);
    }
}

void ofApp::draw(){
    ildaFrame.update();
    ildaFrame.draw(0, 0, ofGetWidth(), ofGetHeight());
    etherdream.setPoints(ildaFrame);
}
