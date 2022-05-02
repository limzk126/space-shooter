//
// Created by dylan on 5/1/22.
//
#ifndef SPACE_SHOOTER_STRUCTS_H
#define SPACE_SHOOTER_STRUCTS_H

typedef struct {
    void (*logic)(void);
    void (*draw)(void);
} Delegate;

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
    Delegate delegate;
    int keyboard[MAX_KEYBOARD_KEYS];
} App;

struct Entity {
    float x;
    float y;
    int w;
    int h;
    float dx;
    float dy;
    int health;
    int reload;
    int side;
    SDL_Texture *texture;
    struct Entity *next;
};
struct Explosion {
    float x;
    float y;
    float dx;
    float dy;
    int r, g, b, a;
    struct Explosion *next;
};

struct Debris {
    float x;
    float y;
    float dx;
    float dy;
    SDL_Rect rect;
    SDL_Texture *texture;
    int life;
    struct Debris *next;
};

typedef struct {
    struct Entity fighterHead, *fighterTail;
    struct Entity bulletHead, *bulletTail;
    struct Explosion explosionHead, *explosionTail;
    struct Debris debrisHead, *debrisTail;
} Stage;


typedef struct {
    int x;
    int y;
    int speed;
} Star;

#endif //SPACE_SHOOTER_STRUCTS_H
