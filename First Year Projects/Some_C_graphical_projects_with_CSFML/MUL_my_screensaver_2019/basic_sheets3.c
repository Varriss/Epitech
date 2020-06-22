/*
** EPITECH PROJECT, 2019
** MUL
** File description:
** basic_sheets3
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stddef.h>
#include "include/my.h"
#include <stdlib.h>
#include <math.h>

void draw_empty_circle(t_framebuffer *fb, t_pos ori, sfColor color, int size)
{
    t_pos disp = {0, 0};
    int x = ori.x - size;
    int y = ori.y - size;
    int tmp_x = x;

    for (int i = 0; i <= size; i++, y++, tmp_x = x)
        for (int j = 0; j <= size; j++, tmp_x++)
            if (size == (int)sqrtf(((tmp_x - ori.x)
            *(tmp_x - ori.x)) + ((y - ori.y)*(y - ori.y)))) {
                disp.x = tmp_x;
                disp.y = y;
                draw_square(fb, size/4, color, disp);
                disp.y += ((size - i) * 2);
                draw_square(fb, size/4, color, disp);
                disp.x += ((size - j) * 2);
                draw_square(fb, size/4, color, disp);
                disp.y -= ((size - i) * 2);
                draw_square(fb, size/4, color, disp);
                disp.x -= ((size - j) * 2);
            }
}

void get_fade_ball(t_framebuffer *fb, t_pos ori, sfColor color, accel acc)
{
    balfade *bowl = NULL;
    bowl = malloc(sizeof(balfade));

    bowl->cir.ori = ori;
    bowl->cir.change = color;
    bowl->cir_fade.fadecol = color;
    bowl->cir_fade.fadecol.a = 50;
    bowl->cir_fade.preori.x = ori.x - acc.x;
    bowl->cir_fade.preori.y = ori.y - acc.y;
    draw_square(fb, 10, bowl->cir_fade.fadecol, bowl->cir_fade.preori);
    bowl->cir_fade.preori.x -= acc.x / 2;
    bowl->cir_fade.preori.y -= acc.y / 2;
    draw_square(fb, 10, bowl->cir_fade.fadecol, bowl->cir_fade.preori);
    draw_square(fb, 10, bowl->cir.change, bowl->cir.ori);
    draw_empty_circle(fb, bowl->cir.ori, bowl->cir.change, 3);
}