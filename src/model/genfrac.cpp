#include "genfrac.hpp"
#include <iostream>
#include <math.h>

iterData genFrac::checkPixel(double x, double y) {
    complex<double> firstCords(x,y);
    complex<double> newCords(x,y);
    iterData currData;
    currData.startCords = firstCords;
    currData.inSet = true;
    for(int i = 0; i < bail; i++) {
        if(newCords.real()*newCords.real()+newCords.imag()*newCords.imag() > 2*2) {
            currData.inSet = false;
            break;
        } else {
            currData.pointsVisited.push_back(newCords);
            newCords = newCords*newCords + firstCords;
        }
    }
    return currData;
}

void genFrac::loadChunk(double startX, double startY, double endX, double endY, int detail) {
    chunk currChunk(startX,startY,endX,endY,detail);
    int index = 0;
    double x = startX;
    double y = startY;
    while(x < endX) {
        x+=currChunk.stepX;
        while(y < endY) {
            y+=currChunk.stepY;
            currChunk.data[index] = checkPixel(x,y);
            index++;
        }
        y = startY;
    }
    chunk_map.push_back(currChunk);
}