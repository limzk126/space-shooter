//
// Created by dylan on 5/1/22.
//

#ifndef SPACE_SHOOTER_STAGE_H
#define SPACE_SHOOTER_STAGE_H

#include "common.h"

extern void blit(SDL_Texture *texture, int x, int y);
extern SDL_Texture *loadTexture(char *filename);

extern App app;
extern Stage stage;

#endif //SPACE_SHOOTER_STAGE_H
