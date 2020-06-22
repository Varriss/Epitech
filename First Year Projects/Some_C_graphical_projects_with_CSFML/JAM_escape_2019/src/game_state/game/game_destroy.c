/*
** EPITECH PROJECT, 2020
** GAME_DESTROY
** File description:
** Game_destroy function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_audio.h"
#include "my_clock.h"
#include "my_tileset.h"
#include "my_tilemap.h"
#include "my_button.h"
#include "jam.h"
#include "entity.h"

void game_destroy_buttons(game_t *game)
{
    if (game->pause_buttons)
        button_destroy(game->pause_buttons);
    if (game->button_textures)
        tileset_destroy(game->button_textures);
}

void *game_destroy(game_t *game)
{
    if (!game)
        return (NULL);
    if (game->global_clock)
        clock_destroy(game->global_clock);
    if (game->audio)
        audio_destroy(game->audio);
    if (game->tilemap)
        tilemap_destroy(game->tilemap);
    game_destroy_buttons(game);
    if (game->bg_texture)
        sfTexture_destroy(game->bg_texture);
    if (game->blur_fg_texture)
        sfTexture_destroy(game->blur_fg_texture);
    if (game->bg_sprite)
        sfSprite_destroy(game->bg_sprite);
    if (game->blur_fg_sprite)
        sfSprite_destroy(game->blur_fg_sprite);
    player_destroy(game->player);
    free(game);
    return (NULL);
}