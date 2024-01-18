#include "header.h"

void draw_circle(SDL_Renderer *renderer, double x, double y, double radius, int *color)
{
    int i;
    double x0, y0, x1, y1;
    double tau = 6.28318530718;
    double step = tau / (100 * radius);
    double t0 = 0, t1 = step;
    
    while (t1 < tau)
    {
        x0 = x + radius*cos(t0);
        y0 = y + radius*sin(t0);

        x1 = x + radius*cos(t1);
        y1 = y + radius*sin(t1);

        SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], 255);
        SDL_RenderDrawLine(renderer, x0, y0, x1, y1);

        t0 = t1; 
        t1 += step; 
    }
}
