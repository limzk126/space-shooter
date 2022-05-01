#include "spaceshooter.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

static void capFrameRate(long *, float *);
static long total = 0;
static long frames = 0;

/**
 * wait has a value of 16 or 17 depending on the value of remainder (0.667, 1.334 or 1.001).
 * wait has an average value of 16.667 with time.
 * One second has 1000 milliseconds and 60 frames, hence one frame is 16.67 milliseconds.
 * SDL_Delay is used to pad a frame if it takes too little time.
 *
 * @param then
 * @param remainder
 */
static void capFrameRate(long *then , float *remainder) {
    long wait, frameTime;

    wait = 16 + *remainder;
    total += wait;
    frames++;
    printf("total: %ld frames: %ld\n", total, frames);
    *remainder -= (int)*remainder;

    frameTime = SDL_GetTicks() - *then;

    wait -= frameTime;

    if (wait < 1)
    {
        wait = 1;
    }

    SDL_Delay(wait);

    *remainder += 0.667;

    *then = SDL_GetTicks();
}


int main() {
    long then;
    float remainder;

    memset(&app, 0, sizeof(App));

    initSDL();

    atexit(cleanup);

    initStage();

    then = SDL_GetTicks();

    remainder = 0;

    while (1) {
        prepareScene();

        doInput();

        app.delegate.logic();

        app.delegate.draw();

        presentScene();

        capFrameRate(&then, &remainder);
    }

    return 0;
}

#pragma clang diagnostic pop