//
// Created by dylan on 5/1/22.
//
#include "init.h"

void initSDL(void) {
    int rendererFlags = SDL_RENDERER_ACCELERATED;
    int windowFlags = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    //Note: SDL_WINDOWPOS_UNDEFINED tells the OS to position window wherever it likes.
    app.window = SDL_CreateWindow("spaceshooter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

    if (!app.window) {
        printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    //Npte: -1 tells SDL to use the first graphics acceleration device it finds
    app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

    if (!app.renderer) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }

    // Configure SDL2_image to load png and jpg images.
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
}

void cleanup(void)
{
    SDL_DestroyRenderer(app.renderer);

    SDL_DestroyWindow(app.window);

    app.renderer = NULL;
    app.window = NULL;

    SDL_Quit();
}

