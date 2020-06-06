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
    int width;
    int height;
    public:
        int bail = 100;
        genFrac(int width, int height):
            width(width),
            height(height)
        {}
        double xScale = (double)4/(double)(width-1);
        double yScale = (double)4/(double)(height-1);
        double yOffset = -(double)(height-1)/2;
        double xOffset = -(double)(width-1)/2;
        iterData checkPixel(double x, double y);
        iterData* checkRange();
};