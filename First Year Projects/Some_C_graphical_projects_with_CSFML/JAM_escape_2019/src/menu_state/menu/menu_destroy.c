/*
** EPITECH PROJECT, 2020
** MENU_DESTROY
** File description:
** Menu_destroy function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_clock.h"
#include "my_button.h"
#include "jam.h"

void *menu_destroy_preview_textures(sfTexture **textures)
{
    if (!textures)
        return (NULL);
    for (int k = 0; textures[k]; k++)
        sfTexture_destroy(textures[k]);
    free(textures);
    return (NULL);
}

void menu_destroy_buttons(menu_t *menu)
{
    if (menu->play_button)
        button_destroy(menu->play_button);
    if (menu->quit_button)
        button_destroy(menu->quit_button);
}

void *menu_destroy(menu_t *menu)
{
    if (!menu)
        return (NULL);
    if (menu->clock)
        clock_destroy(menu->clock);
    if (menu->preview_sprite)
        sfSprite_destroy(menu->preview_sprite);
    menu_destroy_preview_textures(menu->preview_textures);
    if (menu->title)
        button_destroy(menu->title);
    menu_destroy_buttons(menu);
    free(menu);
    return (NULL);
}