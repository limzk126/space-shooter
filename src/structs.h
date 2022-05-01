//
// Created by dylan on 5/1/22.
//
#ifndef SPACE_SHOOTER_STRUCTS_H
#define SPACE_SHOOTER_STRUCTS_H

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
    int up;
    int down;
    int left;
    int right;
} App;

typedef struct {
    int x;
    int y;
    SDL_Texture *texture;
} Entity;

#endif //SPACE_SHOOTER_STRUCTS_H
