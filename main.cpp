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

typedef struct {
    int x, y;
}Shot;

int processEvents(SDL_Window *window, Plane *plane) {
    
    SDL_Event event;
    int done = 0;
    
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
    if (state[SDL_SCANCODE_LEFT] && plane->x >10){
        plane->x-=5;
    }
    if (state[SDL_SCANCODE_RIGHT] && plane->x < SCREEN_WIDTH-30){
        plane->x+=5;
    }
    if (state[SDL_SCANCODE_UP] && plane->y > 10){
        plane->y-=5;
    }
    if (state[SDL_SCANCODE_DOWN] && plane->y < SCREEN_HEIGHT-30){
        plane->y+=5;
    }
    
    return done;
}

void doRender(SDL_Renderer *renderer, Plane *plane){
    
    SDL_SetRenderDrawColor(renderer, 0, 50, 100, 255);
    
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, 100, 50, 25, 255);
    
    SDL_Rect rect = { plane->x, plane->y, 20, 20 };
    SDL_RenderFillRect(renderer, &rect);
    
    SDL_RenderPresent(renderer);
}

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
