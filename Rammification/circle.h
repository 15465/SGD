#ifndef Circle_H
#define Circle_H

#include "SDL.h"

void set_pixel(SDL_Renderer* rend, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

void draw_circle(SDL_Renderer* surface, int n_cx, int n_cy, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

#endif