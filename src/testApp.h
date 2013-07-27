#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
private:
    void doRandExperiment();
    void doShuffleExperiment(int numShuffles);
    std::string pValue(double matrix[]);
    
    unsigned long experimentsDone;
    double shuffleCounts[52*52];
    double randCounts[52*52];
    
    void drawMatrix(float x, float y, float width, float height, double matrix[], double min, double max);
    
    ofTrueTypeFont arial24;
};
