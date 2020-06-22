/*
** EPITECH PROJECT, 2019
** MUL
** File description:
** screen2
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stddef.h>
#include "include/my.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <time.h>

circl_mov *move_the_circl(circl_mov *c_1, int size)
{
    if (c_1->ori.x >= 1910 - size) {
        c_1->acc.x *= -1;
        c_1->change.a += 50;
    }
    if (c_1->ori.x <= 10 + size) {
        c_1->acc.x *= -1;
        c_1->change.g -= 20;
    }
    if (c_1->ori.y >= 1070 - size) {
        c_1->acc.y *= -1;
        c_1->change.r -= 70;
    }
    if (c_1->ori.y <= 10 + size) {
        c_1->acc.y *= -1;
        c_1->change.b -= 100;
    }
    c_1->ori.x += c_1->acc.x;
    c_1->ori.y += c_1->acc.y;
    return (c_1);
}

circl_mov *init_circle(void)
{
    circl_mov *c_1 = malloc(sizeof(circl_mov));

    srand(time(NULL));
    c_1->ori.x = rand() % 1800 + 70;
    srand(time(NULL));
    c_1->ori.y = rand() % 900 + 70;
    srand(time(NULL));
    c_1->acc.x = 2;
    c_1->acc.y = 2;
    if ((rand() % 2 + 1 == 2))
        c_1->acc.y *= -1;
    if ((rand() % 2 + 1 == 2))
        c_1->acc.x *= -1;
    c_1->change = sfBlue;
    return (c_1);
}

void ball_fade(t_framebuffer *fb
, sfTexture *texture, sfSprite *sprite, sfRenderWindow *window)
{
    sfEvent eve;
    circl_mov *c_1 = init_circle();
    int size = 1;
    int grow = 0;

    for (int h = 0; h < 100000 && sfRenderWindow_isOpen(window); h++) {
        draw_circle(fb, c_1->ori, get_colorfade_of(c_1->change), size);
        c_1 = move_the_circl(c_1, size);
        draw_circle(fb, c_1->ori, c_1->change, size);
        if (size == 1)
            grow = 1;
        if (size == 50)
            grow = -1;
        size += grow;
        disp_refresh(window, fb, texture, sprite);
        while (sfRenderWindow_pollEvent(window, &eve))
            if (eve.type == sfEvtKeyPressed)
                sfRenderWindow_close(window);
    }
}

t_framebuffer *do_things2(sfRenderWindow *window, t_framebuffer *fb
, sfTexture *texture, sfSprite *sprite)
{
    sfEvent eve;

    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        ball_fade(fb, texture, sprite, window);
        erase_screen(fb, texture, sprite, window);
        disp_refresh(window, fb, texture, sprite);
        while (sfRenderWindow_pollEvent(window, &eve))
            if (eve.type == sfEvtKeyPressed)
                sfRenderWindow_close(window);
    }
    return (fb);
}

void screen2(void)
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
    fb = do_things2(window, fb, texture, sprite);
    framebuffer_kill(fb);
    free(fb);
    sfRenderWindow_destroy(window);
}