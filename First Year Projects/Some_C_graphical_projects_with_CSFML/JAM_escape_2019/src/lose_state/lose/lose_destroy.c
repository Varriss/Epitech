/*
** EPITECH PROJECT, 2020
** LOSE_DESTROY
** File description:
** Lose_destroy function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_tileset.h"
#include "my_clock.h"
#include "my_audio.h"
#include "my_button.h"
#include "jam.h"

void *lose_destroy(lose_t *lose)
{
    if (!lose)
        return (NULL);
    if (lose->clock)
        clock_destroy(lose->clock);
    if (lose->audio)
        audio_destroy(lose->audio);
    if (lose->bg_texture)
        sfTexture_destroy(lose->bg_texture);
    if (lose->wasted_texture)
        sfTexture_destroy(lose->wasted_texture);
    if (lose->bg_sprite)
        sfSprite_destroy(lose->bg_sprite);
    if (lose->wasted_sprite)
        sfSprite_destroy(lose->wasted_sprite);
    if (lose->button_textures)
        tileset_destroy(lose->button_textures);
    if (lose->menu_button)
        button_destroy(lose->menu_button);
    free(lose);
    return (NULL);
}