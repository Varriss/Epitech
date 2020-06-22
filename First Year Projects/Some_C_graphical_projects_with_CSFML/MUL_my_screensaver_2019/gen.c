/*
** EPITECH PROJECT, 2019
** MUL
** File description:
** gen
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stddef.h>
#include "my.h"
#include <stdlib.h>

sfRenderWindow *open_win(int width, int height, int bytes
, sfRenderWindow *window)
{
    sfVideoMode mode = {width, height, bytes};

    window = sfRenderWindow_create(mode, "My awesome window"
    , sfResize | sfClose, NULL);
    return (window);
}

t_framebuffer *frambuffer_gen(int width, int height, t_framebuffer *fb)
{
    fb->width = width;
    fb->height = height;
    fb->pixels = malloc((width * height) * 4);
    return (fb);
}

void framebuffer_kill(t_framebuffer *fb)
{
    free(fb->pixels);
}