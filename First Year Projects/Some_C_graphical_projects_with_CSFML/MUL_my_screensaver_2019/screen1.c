/*
** EPITECH PROJECT, 2019
** MUL
** File description:
** screen1
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stddef.h>
#include "include/my.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

void do_things1(sfRenderWindow *window, t_framebuffer *fb
, sfTexture *texture, sfSprite *sprite)
{
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        logar_color_disp(window, fb, texture, sprite);
        erase_screen(fb, texture, sprite, window);
    }
    framebuffer_kill(fb);
    free(fb);
    sfRenderWindow_destroy(window);
}

void logar_color_disp(sfRenderWindow *window, t_framebuffer *fb
, sfTexture *texture, sfSprite *sprite)
{
    sfEvent eve;
    sfColor changing = {50, 1, 100, 255};
    t_pos ori = {0, 0};
    t_pos des = {0, 1080};

    while (des.y > 0 && sfRenderWindow_isOpen(window)) {
        draw_line(fb, ori, des, sfBlack, 2);
        des.x < 1920 ? des.x += 2 : (des.y > 0 ? des.y-- : 0);
        draw_line(fb, ori, des, get_colorfade_of(changing), 2);
        des.x < 1920 ? des.x += 2 : (des.y > 0 ? des.y-- : 0);
        draw_line(fb, ori, des, changing, 1);
        changing = color_incr(changing);
        disp_refresh(window, fb, texture, sprite);
        while (sfRenderWindow_pollEvent(window, &eve))
            if (eve.type == sfEvtKeyPressed)
                sfRenderWindow_close(window);
    }
}

void screen1(void)
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
    do_things1(window, fb, texture, sprite);
}