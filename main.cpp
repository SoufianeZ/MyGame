//
//  main.cpp
//  MyGame
//
//  Created by Zarkane Soufiane on 09/08/2017.
//  Copyright © 2017 Zarkane Soufiane. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 780;

typedef struct {
    int x, y;
}Plane;

int main(int argc, const char * argv[]) {
    
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    SDL_Init(SDL_INIT_VIDEO);
    
    window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    Plane plane;
    plane.x = SCREEN_WIDTH/2;
    plane.y = SCREEN_HEIGHT-40;

    int done = 0;
    SDL_Event event;
    
    while (!done) {
        
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_WINDOWEVENT_CLOSE:
                    done = 1;
                    break;
                case SDL_QUIT:
                    done = 1;
                    break;
            }
        }
        
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_LEFT]){
            plane.x--;
        }
        if (state[SDL_SCANCODE_RIGHT]){
            plane.x++;
        }
        if (state[SDL_SCANCODE_UP]){
            plane.y -= 0.5;
        }
        if (state[SDL_SCANCODE_DOWN]){
            plane.y++;
        }
        
        SDL_SetRenderDrawColor(renderer, 0, 50, 100, 255);
        
        SDL_RenderClear(renderer);
        
        SDL_SetRenderDrawColor(renderer, 100, 50, 25, 255);
        
        SDL_Rect rect = { plane.x, plane.y, 20, 20 };
        SDL_RenderFillRect(renderer, &rect);
        
        SDL_RenderPresent(renderer);
        
    }
    
    SDL_Delay(10);
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
    SDL_Quit();
    return 0;
}
