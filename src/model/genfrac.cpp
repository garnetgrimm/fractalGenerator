#include "genfrac.hpp"
#include <iostream>
#include <math.h>

iterData checkPixel(double x, double y) {
    complex<double> firstCords(x,y);
    complex<double> newCords(x,y);
    iterData currData;
    currData.inSet = true;
    currData.startCords = firstCords;
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

iterData* checkRange(int width, int height) {
    double xScale = (double)4/(double)(width-1);
    double yScale = (double)4/(double)(height-1);
    double yOffset = -(double)(height-1)/2;
    double xOffset = -(double)(width-1)/2;

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