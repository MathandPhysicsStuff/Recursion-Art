#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "SDL2/SDL.h"

enum BOOL { FALSE, TRUE };


void draw_circle(SDL_Renderer *renderer, double x, double y, double radius, int *color);

#endif
