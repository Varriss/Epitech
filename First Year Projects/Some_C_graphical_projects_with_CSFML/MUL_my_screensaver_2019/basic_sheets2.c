/*
** EPITECH PROJECT, 2019
** MUL
** File description:
** basic_sheets2
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stddef.h>
#include "include/my.h"
#include <stdlib.h>

void my_put_pixel(t_framebuffer *fb, unsigned int x, unsigned int y
, sfColor color)
{
    int index = (x + (y * fb->width)) * 4;

    fb->pixels[index + 0] = color.r;
    fb->pixels[index + 1] = color.g;
    fb->pixels[index + 2] = color.b;
    fb->pixels[index + 3] = color.a;
}

void line_print(t_framebuffer *fb)
{
    int x = 0;
    int y = 60;

    for (int i = 0; i <= 1000; i++) {
        my_put_pixel(fb, x++ , y, sfRed);
    }
}

void draw_square(t_framebuffer *fb, int size, sfColor color, t_pos p)
{
    int x = p.x;
    int y = p.y;
    int tmp_x = x;

    for (int i = 0; i <= size; i++, y++) {
        for (int j = 0; j <= size; j++)
            my_put_pixel(fb, tmp_x++ , y, color);
        tmp_x = x;
    }
}

void disp_refresh(sfRenderWindow *window, t_framebuffer *fb
, sfTexture *texture, sfSprite *sprite)
{
    sfRenderWindow_display(window);
    sfTexture_updateFromPixels(texture, fb->pixels, 1920, 1080, 0, 0);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

sfColor color_incr(sfColor changing)
{
    changing.r += 2;
    changing.g += 3;
    changing.b += 1;
    return (changing);
}