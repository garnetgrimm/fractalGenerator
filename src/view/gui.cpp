#include "gui.hpp"
#include <chrono>
#include <iostream>
#include <cmath>
#include <model/genfrac.hpp>

void GUI::drawRect(float x, float y, float width, float height, uint32_t color, uint8_t alpha) {
  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = width;
  rect.h = height;

  int r = ((color & 0xFF0000) >> 16);
  int g = ((color & 0x00FF00) >>  8);
  int b = ((color & 0x0000FF) >>  0);

  SDL_SetRenderDrawColor(rend, r, g, b, alpha);
  SDL_RenderFillRect(rend, &rect);
}

void GUI::drawFract(genFrac* gf) {

      gf->changeTrueRange(1,1);

      gf->bail = 100;
      iterData* dataR = gf->checkRange();
      gf->bail = 100;
      iterData* dataG = gf->checkRange();
      gf->bail = 100;
      iterData* dataB = gf->checkRange();

      for(int row = 0; row < WIDTH; row++) {
        for(int col = 0; col < HEIGHT; col++) {
          iterData* currR = &dataR[row*HEIGHT + col];

          //uint32_t c = dataG[row*(WIDTH) + col].inSet ? 0xfcfbfe : 0x000000;
          //drawRect(col,row, 1, 1, c, 255);

          drawRect(currR->startCords.real(), currR->startCords.imag(), 1, 1, 0xFFFFFF, (255*currR->pointsVisited.size())/255);
          
          for(complex<double> cd : dataB[row*HEIGHT + col].pointsVisited) {
            drawRect(cd.real(), cd.imag(), 1, 1, 0xedf252, 6);
          }
          
          for(complex<double> cd : dataG[row*HEIGHT + col].pointsVisited) {
            drawRect(cd.real(), cd.imag(), 1, 1, 0x0c164f, 15);
          }
        }
      }

}

void GUI::initWindow() {

      double xBound = 2;
      double yBound = 2;

      // retutns zero on success else non-zero
      if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
          printf("error initializing SDL: %s\n", SDL_GetError());
      }
      SDL_Window* win = SDL_CreateWindow("GAME",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

      Uint32 render_flags = SDL_RENDERER_ACCELERATED;
      rend = SDL_CreateRenderer(win, -1, render_flags);

      SDL_SetRenderDrawBlendMode(rend, SDL_BLENDMODE_BLEND);

      // clears the screen
      SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
      SDL_RenderClear(rend);      

      genFrac gf(WIDTH,HEIGHT);
      drawFract(&gf);

      SDL_Surface *sshot = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
      SDL_RenderReadPixels(rend, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
      SDL_SaveBMP(sshot, "red.bmp");
      SDL_FreeSurface(sshot);

      // triggers the double buffers
      // for multiple rendering
      SDL_RenderPresent(rend);

      // annimation loop
      while (running) {
          SDL_Event event;
          // Events mangement

          int dir = 0;

          while (SDL_PollEvent(&event)) {
              switch (event.type) {
              case SDL_QUIT:
                  // handling of close button
                  running = false;
                  break;
              case SDL_MOUSEWHEEL:
                  if(yBound <= 1) yBound *= pow(2, event.wheel.y);
                  else {
                    yBound += event.wheel.y;
                  }
                  /*gf.changeTrueRange(yBound,yBound);
                  SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
                  SDL_RenderClear(rend);
                  drawFract(&gf);
                  SDL_RenderPresent(rend);*/
                  break;
              case SDL_MOUSEBUTTONDOWN:
								switch(event.button.button) {
									case SDL_BUTTON_LEFT:
                      //double cx = event.button.y*yScale+(yOffset*yScale);
                      //double cy = event.button.x*xScale+(xOffset*xScale);
									  	//cout << cx << " " << cy << endl;
										break;
                }
            }
          }
          // calculates to 60 fps
          //SDL_Delay(1000 / 60);
          SDL_Delay(1000 / 60);
      }

      //SDL_DestroyTexture(tex);
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);

}