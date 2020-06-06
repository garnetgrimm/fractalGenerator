#include <iostream>
#include <thread>
#include <model/genfrac.cpp>
#include <view/gui.hpp>

#define WIDTH 640
#define HEIGHT 480
#define SCALE 1

using namespace std;

int main()
{
    GUI myGUI = GUI(WIDTH, HEIGHT, 1);
    myGUI.initWindow();

    /*for(int i = 0; i < WIDTH*HEIGHT; i++) {
        cout << data[i].startCords << endl;
    }*/

    //thread thread1(&GUI::initWindow, std::ref(myGUI));

    //iterData* data = checkRange(10, 2);

    //iterData data = checkPixel(-2,-2);
    //for(complex<double> point : data.pointsVisited) {
    //    cout << point << " ";
    //}
    //cout << endl;
    //cout << data.inSet << endl;
    //cout << data.startCords << endl;
    //thread1.join();
    return 0;
}
