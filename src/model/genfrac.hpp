#pragma once

#include "vector"
#include <complex>

using namespace std;

static int bail = 100;

class iterData {
    public:
        iterData():
            pointsVisited(1) {} 
        bool inSet;
        complex<double> startCords = complex<double>(0,0);
        vector<complex<double>> pointsVisited;
};

iterData checkPixel(double x, double y);
iterData* checkRange(int width, int height);