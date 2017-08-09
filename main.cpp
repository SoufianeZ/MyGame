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
const int SCREEN_HEIGHT = 480;

int main(int argc, const char * argv[]) {
    
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    SDL_Init(SDL_INIT_VIDEO);
    
    window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
    SDL_Rect rect = { 220, 140, 200, 200 };
    SDL_RenderFillRect(renderer, &rect);
        
    SDL_RenderPresent(renderer);
    
    SDL_Delay(2000);
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
    SDL_Quit();
    return 0;
    
}
