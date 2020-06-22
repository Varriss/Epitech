/*
** EPITECH PROJECT, 2019
** MUL
** File description:
** basic_sheets
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stddef.h>
#include "include/my.h"
#include <stdlib.h>
#include <math.h>

sfColor get_colorfade_of(sfColor changing)
{
    sfColor fade = {0, 0, 0, 125};
    fade = changing;
    fade.a = 125;
    return (fade);
}

void init_coord(t_pos *des, t_pos *ori)
{
    des->x = 0;
    des->y = 1080;
    ori->x = 0;
    ori->y = 0;
}

void erase_screen(t_framebuffer *fb, sfTexture *texture
, sfSprite *sprite, sfRenderWindow *window)
{
    t_pos ori = {0, 0};
    sfEvent eve;

    while ((ori.x < 1920) | (ori.y < 1080) && sfRenderWindow_isOpen(window)) {
        for (ori.y = 0; (ori.y <= 1080)
        && sfRenderWindow_isOpen(window); ori.y += 120) {
            for (ori.x = 0; (ori.x <= 1920)
            && sfRenderWindow_isOpen(window); ori.x += 120) {
                draw_square(fb, 120, sfBlack, ori);
                disp_refresh(window, fb, texture, sprite);
                while (sfRenderWindow_pollEvent(window, &eve))
                    if (eve.type == sfEvtKeyPressed)
                        sfRenderWindow_close(window);
            }
        }
    }
}

void draw_line(t_framebuffer *fb, t_pos ori, t_pos des, sfColor color
, int size)
{
    t_pos swap = {0, 0};
    float a = 0;
    float b = 0;

    if (ori.x > ori.y) {
        swap = des;
        des = ori;
        ori = swap;
    }
    a = (des.y - ori.y) / (des.x - ori.x);
    b = ori.y - a * ori.x;
    swap.x = ori.x;
    swap.y = (a * ori.x) + b;
    while ((swap.x != des.x) && (swap.y != des.y)) {
        swap.x = ori.x;
        swap.y = (a * ori.x + b);
        draw_square(fb, size, color, swap);
        ori.x++;
    }
}

void draw_circle(t_framebuffer *fb, t_pos ori, sfColor color, int size)
{
    int x = ori.x - size;
    int y = ori.y - size;
    int r_square = size*size;
    int tmp_x = x;

    for (int i = 0; i <= size; i++, y++) {
        for (int j = 0; j <= size; j++, tmp_x++)
            if (r_square >= ((tmp_x - ori.x)*(tmp_x - ori.x))
            + ((y - ori.y)*(y - ori.y))) {
                my_put_pixel(fb, tmp_x, y, color);
                my_put_pixel(fb, tmp_x + ((size - j)*2), y 
                + ((size - i)*2), color);
                my_put_pixel(fb, tmp_x, y + ((size - i)*2), color);
                my_put_pixel(fb, tmp_x + ((size - j)*2), y, color);
            }
        tmp_x = x;
    }
}