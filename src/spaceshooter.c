#include "spaceshooter.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

int main() {
    memset(&app, 0, sizeof(App));
    memset(&player, 0, sizeof(Entity));

    initSDL();

    player.x = 100;
    player.y = 100;
    player.texture = loadTexture("gfx/player.png");

    bullet.texture = loadTexture("gfx/playerBullet.png");

    atexit(cleanup);

    while (1) {
        prepareScene();

        doInput();

        if (app.up)
        {
            player.y -= 4;
        }

        if (app.down)
        {
            player.y += 4;
        }

        if (app.left)
        {
            player.x -= 4;
        }

        if (app.right)
        {
            player.x += 4;
        }

        if (app.fire && bullet.health == 0)
        {
            int bulletW, bulletH;
            int playerW, playerH;
            SDL_QueryTexture(player.texture, NULL, NULL, &playerW, &playerH);
            SDL_QueryTexture(bullet.texture, NULL, NULL, &bulletW, &bulletH);
            bullet.x = player.x + playerW / 2 - bulletW / 2;
            bullet.y = player.y + playerH / 2 - bulletH / 2;
            bullet.dx = 16;
            bullet.dy = 0;
            bullet.health = 1;
        }

        bullet.x += bullet.dx;
        bullet.y += bullet.dy;

        if (bullet.x > SCREEN_WIDTH)
        {
            bullet.health = 0;
        }

        blit(player.texture, player.x, player.y);

        if (bullet.health > 0)
        {
            blit(bullet.texture, bullet.x, bullet.y);
        }

        presentScene();

        SDL_Delay(16);
    }

    return 0;
}

#pragma clang diagnostic pop