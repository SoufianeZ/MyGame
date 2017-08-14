//
//  EventManager.c
//  MyGame
//
//  Created by Zarkane Soufiane on 14/08/2017.
//  Copyright © 2017 Zarkane Soufiane. All rights reserved.
//

#include "EventManager.hpp"

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

