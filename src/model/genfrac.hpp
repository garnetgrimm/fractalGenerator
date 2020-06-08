#pragma once

#include "vector"
#include <complex>
#include <iostream>

using namespace std;

class iterData {
    public: 
        bool inSet = true;
        complex<double> startCords;
        vector<complex<double>> pointsVisited;
};

class chunk {
    public:
        chunk(double startX, double startY, double endX, double endY, int detail):
            startX(startX),
            startY(startY),
            endX(endX),
            endY(endY),
            detail(detail),
            stepX((endX-startX)/detail),
            stepY((endY-startY)/detail)
        {
            data = new iterData [(detail)*(detail+1)];
        }
        const int detail;
        const double startX;
        const double startY;
        const double endX;
        const double endY;
        const double stepX;
        const double stepY;
        iterData* data;
};

class genFrac {
    public:
        int bail = 10;
        genFrac() {
            loadChunk(-2,-2,2,2,500);
        }
        vector<chunk> chunk_map;
        iterData checkPixel(double x, double y);
        void loadChunk(double startX, double startY, double endX, double endY, int detail);
};