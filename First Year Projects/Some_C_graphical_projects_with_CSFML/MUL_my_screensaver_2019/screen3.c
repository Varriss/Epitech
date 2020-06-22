/*
** EPITECH PROJECT, 2019
** MUL
** File description:
** screen3
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stddef.h>
#include "include/my.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <time.h>

void raining_blood(sfRenderWindow *window, t_framebuffer *fb
, sfTexture *texture, sfSprite *sprite)
{
    t_pos ori = {100, 10};
    accel acc = {5, 5};
    sfEvent eve;

    srand(time(NULL));
    while (sfRenderWindow_isOpen(window)) {
        while (ori.x <= 1900 && ori.y <= 950 
        && ori.x >= 20 && sfRenderWindow_isOpen(window)) {
            get_fade_ball(fb, ori, sfRed, acc);
            ori.x += acc.x;
            ori.y += acc.y;
            disp_refresh(window, fb, texture, sprite);
            while (sfRenderWindow_pollEvent(window, &eve))
                if (eve.type == sfEvtKeyPressed)
                    sfRenderWindow_close(window);
        }
        ori.y = 10;
        ori.x = rand() % 1800 + 30;
        (rand() % 2 + 1) == 2 ? acc.x *= -1 : 0;
    }
}

t_framebuffer *do_things3(sfRenderWindow *window, t_framebuffer *fb
, sfTexture *texture, sfSprite *sprite)
{
    sfEvent eve;
    t_pos ori = {500, 500};

    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        draw_empty_circle(fb, ori, sfBlue, 10);
        raining_blood(window, fb, texture, sprite);
        disp_refresh(window, fb, texture, sprite);
        while (sfRenderWindow_pollEvent(window, &eve))
            if (eve.type == sfEvtKeyPressed)
                sfRenderWindow_close(window);
    }
    return (fb);
}

void screen3(void)
{
    sfRenderWindow *window = NULL;
    window = open_win(1920, 1080, 32, window);
    t_framebuffer *fb = malloc(sizeof(t_framebuffer));
    sfTexture *texture;
    sfSprite *sprite;

    fb = frambuffer_gen(1920, 1080, fb);
    texture = sfTexture_create(1920, 1080);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    fb = do_things3(window, fb, texture, sprite);
    framebuffer_kill(fb);
    free(fb);
    sfRenderWindow_destroy(window);
}