//
//  Renderer.cpp
//  MyGame
//
//  Created by Zarkane Soufiane on 14/08/2017.
//  Copyright © 2017 Zarkane Soufiane. All rights reserved.
//

#include "Renderer.hpp"

void doRender(SDL_Renderer *renderer, Plane *plane){
    
    SDL_SetRenderDrawColor(renderer, 0, 50, 100, 255);
    
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, 100, 50, 25, 255);
    
    SDL_Rect rect = { plane->x, plane->y, 20, 20 };
    SDL_RenderFillRect(renderer, &rect);
    
    SDL_RenderPresent(renderer);
}
