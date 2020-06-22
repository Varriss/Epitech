/*
** EPITECH PROJECT, 2020
** MENU_DRAW
** File description:
** Menu_draw function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_sprite.h"
#include "my_button.h"
#include "my_window.h"
#include "jam.h"
#include "tilemap.h"

void menu_draw_map_selector(sfRenderWindow *window, menu_t *menu)
{
    sfTexture *texture = NULL;
    sfSprite *sprite = menu->preview_sprite;
    sfVector2f pos = {menu->x_map, 0};

    for (int k = 0; k < 1; k++) {
        texture = menu->preview_textures[k];
        sfSprite_setPosition(sprite, pos);
        sprite_set_texture(sprite, texture, WIDTH, HEIGHT);
        win_draw_sprite(window, sprite);
        pos.x += WIDTH;
    }
}

void menu_draw(sfRenderWindow *window, menu_t *menu)
{
    if (!menu || !window)
        return;
    win_clear(window, sfGreen);
    menu_draw_map_selector(window, menu);
    button_draw(window, menu->title);
    button_draw(window, menu->play_button);
    button_draw(window, menu->quit_button);
    win_display(window);
}