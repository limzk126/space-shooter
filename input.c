//
// Created by dylan on 5/1/22.
//
#include "input.h"

void doInput(void) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            exit(0);
            break;
        default:
            break;
        }
    }
}