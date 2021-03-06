//
// Created by dylan on 5/1/22.
//

#ifndef SPACE_SHOOTER_STAGE_H
#define SPACE_SHOOTER_STAGE_H

#include "common.h"

extern void blit(SDL_Texture *texture, int x, int y);
extern SDL_Texture *loadTexture(char *filename);
extern int collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
extern void calcSlope(int x1, int y1, int x2, int y2, float *dx, float *dy);
extern void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y);

extern App app;
extern Stage stage;

#endif //SPACE_SHOOTER_STAGE_H
