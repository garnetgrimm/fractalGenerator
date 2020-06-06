#include <view/gui.hpp>
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


void GUI::initWindow() {

      double xScale = (double)4/(double)(WIDTH-1);
      double yScale = (double)4/(double)(HEIGHT-1);
      double yOffset = -(double)(HEIGHT-1)/2;
      double xOffset = -(double)(WIDTH-1)/2;

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

      bail = 5000;
      iterData* dataR = checkRange(WIDTH,HEIGHT);
      bail = 1000;
      iterData* dataG = checkRange(WIDTH,HEIGHT);
      bail = 100;
      iterData* dataB = checkRange(WIDTH,HEIGHT);
        
      for(int row = 0; row < WIDTH-1; row++) {
        for(int col = 0; col < HEIGHT-1; col++) {
    
          //uint32_t c = dataG[row*(WIDTH) + col].inSet ? 0xfcfbfe : 0x000000;
          //drawRect(col,row, 1, 1, c, 255);

          double x = (dataR[row*HEIGHT + col].startCords.real())/(xScale)-xOffset;
          double y = (dataR[row*HEIGHT  + col].startCords.imag()/(yScale))-yOffset;
          drawRect(x, y, 1, 1, 0xfcfbfe, ((float)20*dataR[row*HEIGHT + col].pointsVisited.size())/(float)255);
          
          for(complex<double> cd : dataB[row*HEIGHT + col].pointsVisited) {
            double x = (cd.real())/(xScale)-xOffset;
            double y = (cd.imag()/(yScale))-yOffset;
            drawRect(x, y, 1, 1, 0x5643fd, 5);
          }
          
          for(complex<double> cd : dataG[row*HEIGHT + col].pointsVisited) {
            double x = (cd.real())/(xScale)-xOffset;
            double y = (cd.imag()/(yScale))-yOffset;
            drawRect(x, y, 1, 1, 0x0c164f, 5);
          }
        }
      }

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
              case SDL_MOUSEBUTTONDOWN:
								switch(event.button.button) {
									case SDL_BUTTON_LEFT:
                      double cx = event.button.y*yScale+(yOffset*yScale);
                      double cy = event.button.x*xScale+(xOffset*xScale);
									  	cout << cx << " " << cy << endl;
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