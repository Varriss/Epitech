/*
** EPITECH PROJECT, 2020
** MENU_CREATE
** File description:
** Menu_create function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_clock.h"
#include "my_button.h"
#include "jam.h"
#include "tilemap.h"

sfTexture **menu_load_preview_textures(void)
{
    sfTexture **textures = malloc(sizeof(sfTexture *) * (2));

    if (!textures)
        return (NULL);
    for (int k = 0; k < 1; k++) {
        textures[k] = sfTexture_createFromFile(MAPS_PREVIEW_PATH[k], NULL);
        if (!textures[k])
            return (menu_destroy_preview_textures(textures));
    }
    textures[1] = NULL;
    return (textures);
}

void menu_init(menu_t *menu, gamestate_manager_t *gsm)
{
    menu->clock = clock_create();
    menu->last_update = 0;
    menu->gsm = gsm;
    menu->current_map = 0;
    menu->x_map = -menu->current_map * WIDTH;
}

menu_t *menu_create(gamestate_manager_t *gsm)
{
    menu_t *menu = malloc(sizeof(menu_t));

    if (!menu)
        return (NULL);
    menu_init(menu, gsm);
    menu->title = button_create_from_path(RECT_TITLE, TITLE_PATH);
    menu->play_button = button_create_from_path(RECT_PLAY_BUT,
        PLAY_BUTTON_PATH);
    menu->quit_button = button_create_from_path(RECT_QUIT_BUT, QUIT_PATH);
    menu->preview_sprite = sfSprite_create();
    menu->preview_textures = menu_load_preview_textures();
    if (!menu->play_button || !menu->quit_button
        || !menu->preview_sprite || !menu->preview_textures || !menu->clock)
        return (menu_destroy(menu));
    return (menu);
}