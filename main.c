#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "SDL2/SDL.h"

#include "header.h"

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

const int SCREEN_WIDTH = 1280; //640 405;
const int SCREEN_HEIGHT = 720; //640;
const int screen_centerX = SCREEN_WIDTH / 2;
const int screen_centerY = SCREEN_HEIGHT / 2;

int main()
{
    //Initiating SDL2 stuff
    if (SDL_Init(SDL_INIT_VIDEO) < 0) printf("SDL2 video failed to initialize: \n", SDL_GetError());
    else printf("System is ready to go!\n");

    window = SDL_CreateWindow("Strange Attractor",
                               SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               SCREEN_WIDTH, SCREEN_HEIGHT,
                               SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window,
                                   -1,
                                   SDL_RENDERER_ACCELERATED);


    /*Place where variables, structs, and some functions are initiated*/
    /*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/ 
    /*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/ 
    
    int WHITE[3] = {255, 255, 255};
    double radius = 1;

    /*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
    /*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
   
    //Main render loop
    SDL_bool running = SDL_TRUE;
    while (running == SDL_TRUE)
    {

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = SDL_FALSE;
                break;
            }

            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                    //exit program
                    case SDLK_ESCAPE:
                        running = SDL_FALSE;
                        break;

                    case SDLK_i:
                        if (radius-1 > 0)
                            radius -= 1;
                        break;

                    case SDLK_o:
                        radius += 1;
                        break;

                }
            }
        }
        

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        draw_circle(renderer, screen_centerX, screen_centerY, radius, WHITE);


        SDL_RenderPresent(renderer);
        SDL_Delay(1);
    }
   

    SDL_DestroyWindow(window);
    SDL_Quit();
}
