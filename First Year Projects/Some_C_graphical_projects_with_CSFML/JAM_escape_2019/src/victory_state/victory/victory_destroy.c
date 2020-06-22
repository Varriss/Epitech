/*
** EPITECH PROJECT, 2020
** VICTORY_DESTROY
** File description:
** Victory_destroy function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_tileset.h"
#include "my_clock.h"
#include "my_audio.h"
#include "my_button.h"
#include "jam.h"

void *victory_destroy(victory_t *victory)
{
    if (!victory)
        return (NULL);
    if (victory->clock)
        clock_destroy(victory->clock);
    if (victory->audio)
        audio_destroy(victory->audio);
    if (victory->bg_texture)
        sfTexture_destroy(victory->bg_texture);
    if (victory->wasted_texture)
        sfTexture_destroy(victory->wasted_texture);
    if (victory->bg_sprite)
        sfSprite_destroy(victory->bg_sprite);
    if (victory->wasted_sprite)
        sfSprite_destroy(victory->wasted_sprite);
    if (victory->button_textures)
        tileset_destroy(victory->button_textures);
    if (victory->menu_button)
        button_destroy(victory->menu_button);
    free(victory);
    return (NULL);
}