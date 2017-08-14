//
//  main.cpp
//  MyGame
//
//  Created by Zarkane Soufiane on 09/08/2017.
//  Copyright © 2017 Zarkane Soufiane. All rights reserved.
//

#include <SDL2/SDL.h>
#include <stdio.h>
#include "main.hpp"

int main(int argc, const char * argv[]) {
    
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    SDL_Init(SDL_INIT_VIDEO);
    
    window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    Plane plane;
    plane.x = SCREEN_WIDTH/2;
    plane.y = SCREEN_HEIGHT-30;
    
    int done = 0;
    
    while (!done) {
        
        done = processEvents(window, &plane);
        
        doRender(renderer, &plane);
        
        //      SDL_Delay(3);
    }
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
    SDL_Quit();
    return 0;
}
