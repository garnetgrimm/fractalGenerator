#ifndef GUI_H
#define GUI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <model/genfrac.hpp>

class waveController;

class GUI {
public:
  GUI(const int WIDTH, const int HEIGHT, const int RESOLUTION):
    WIDTH(WIDTH),
    HEIGHT(HEIGHT),
    RESOLUTION(RESOLUTION),
    running(true)
  { }
  void initWindow();
  const int HEIGHT;
  const int WIDTH;
  const int RESOLUTION;
  bool running;
private:
  SDL_Renderer* rend;
  void drawRect(float x, float y, float width, float height, uint32_t color, uint8_t alpha);
};

#endif
