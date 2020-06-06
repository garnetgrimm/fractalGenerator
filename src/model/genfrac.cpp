#include "genfrac.hpp"
#include <iostream>
#include <math.h>

iterData genFrac::checkPixel(double x, double y) {
    complex<double> firstCords(x,y);
    complex<double> newCords(x,y);
    complex<double> scaledCords((newCords.real()/xScale)-xOffset,(newCords.imag()/yScale)-yOffset);
    iterData currData;
    currData.inSet = true;
    currData.startCords = scaledCords;
    for(int i = 0; i < bail; i++) {
        if(newCords.real()*newCords.real()+newCords.imag()*newCords.imag() > 2*2) {
            currData.inSet = false;
            break;
        } else {
            scaledCords = complex<double>((newCords.real()/xScale)-xOffset,(newCords.imag()/yScale)-yOffset);
            currData.pointsVisited.push_back(scaledCords);
            newCords = newCords*newCords + firstCords;
        }
    }
    return currData;
}

iterData* genFrac::checkRange() {
    //new avoids malloc
    iterData* tiles = new iterData [width*height];
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            tiles[row*width + col] = checkPixel((col+xOffset)*xScale, (row+yOffset)*yScale);
            //cout << tiles[row*col + col].startCords << endl;
        }
    }
    return tiles;
}