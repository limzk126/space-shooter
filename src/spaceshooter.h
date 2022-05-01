//
// Created by dylan on 5/1/22.
//

#ifndef SPACE_SHOOTER_SPACESHOOTER_H
#define SPACE_SHOOTER_SPACESHOOTER_H

#include "common.h"

extern void initStage(void);
extern void cleanup(void);
extern void doInput(void);
extern void initSDL(void);
extern void prepareScene(void);
extern void presentScene(void);
extern SDL_Texture *loadTexture(char *);
extern void blit(SDL_Texture *, int, int);

App app;
Stage stage;

#endif //SPACE_SHOOTER_SPACESHOOTER_H
