#pragma once

#include "vector"
#include <complex>

using namespace std;

class iterData {
    public:
        iterData():
            pointsVisited(1) {} 
        bool inSet;
        complex<double> startCords = complex<double>(0,0);
        vector<complex<double>> pointsVisited;
};

class genFrac {
    public:
        int bail = 100;
        genFrac();
        genFrac(int width, int height):
            width(width),
            height(height)
        {
            changeTrueRange(trueXBounds,trueYBounds);
        }
        double yOffset;
        double xOffset;
        iterData checkPixel(double x, double y);
        iterData* checkRange();
        void changeTrueRange(double x, double y);
    private:
        double trueXBounds = 0.5;
        double trueYBounds = 0.5;
        double xScale;
        double yScale;
        int width;
        int height;
};