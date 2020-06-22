/*
** EPITECH PROJECT, 2020
** GAME_CREATE
** File description:
** Game_create function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_audio.h"
#include "my_print.h"
#include "my_tileset.h"
#include "my_tilemap.h"
#include "my_clock.h"
#include "my_button.h"
#include "tilemap.h"
#include "jam.h"
#include "audio.h"
#include "entity.h"

tilemap_t *tilemap_init(char const *map_path)
{
    tilemap_t *tilemap = tilemap_create(TILESIZE, WIDTH, HEIGHT);

    if (!tilemap)
        return (NULL);
    if (!tilemap_load_tiles(tilemap, TILESET, TILESET_TILESIZE)) {
        my_putstr_error("Tilemap load tileset failed\n");
        tilemap_destroy(tilemap);
        return (NULL);
    }
    if (!tilemap_load_map(tilemap, map_path, NB_MAP_LAYERS)) {
        my_putstr_error("Tilemap load map failed\n");
        tilemap_destroy(tilemap);
        return (NULL);
    }
    return (tilemap);
}

void game_init(game_t *game)
{
    game->global_clock = clock_create();
    game->tilemap = tilemap_init(MAPS_PATH[0]);
    game->pause_buttons = NULL;
    game->button_textures = NULL;
    game->audio = NULL;
    game->bg_texture = NULL;
    game->bg_sprite = NULL;
    game->blur_fg_texture = NULL;
    game->blur_fg_sprite = NULL;
    game->player = NULL;
}

int game_init_buttons(game_t *game)
{
    sfTexture *txre = NULL;

    txre = tileset_get(game->button_textures, 2);
    game->pause_buttons = button_create_from_texture(RECT_PAUSE, txre);
    if (!game->pause_buttons)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int game_init_background(game_t *game)
{
    sfVector2f scale = {WIDTH, HEIGHT};

    game->bg_texture = sfTexture_createFromFile(BACKGROUND_PATH, NULL);
    game->bg_sprite = sfSprite_create();
    game->blur_fg_texture = sfTexture_createFromFile(BLUR_FOREGROUND_PATH,
        NULL);
    game->blur_fg_sprite = sfSprite_create();
    if (!game->bg_texture || !game->bg_sprite
        || !game->blur_fg_texture || !game->blur_fg_sprite)
        return (EXIT_FAILURE);
    scale.x /= (float)sfTexture_getSize(game->bg_texture).x;
    scale.y /= (float)sfTexture_getSize(game->bg_texture).y;
    sfSprite_setScale(game->bg_sprite, scale);
    sfSprite_setTexture(game->bg_sprite, game->bg_texture, sfTrue);
    scale = (sfVector2f){WIDTH, HEIGHT};
    scale.x /= (float)sfTexture_getSize(game->blur_fg_texture).x;
    scale.y /= (float)sfTexture_getSize(game->blur_fg_texture).y;
    sfSprite_setScale(game->blur_fg_sprite, scale);
    sfSprite_setTexture(game->blur_fg_sprite, game->blur_fg_texture, sfTrue);
    return (EXIT_SUCCESS);
}

game_t *game_create(gamestate_manager_t *gsm)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return (NULL);
    game->gsm = gsm;
    game_init(game);
    if (!game->global_clock || !game->tilemap)
        return (game_destroy(game));
    game->button_textures = tileset_create(20);
    if (!game->button_textures)
        return (game_destroy(game));
    if (!tileset_load(game->button_textures, GAME_BUTTONS, 64, 64)
        || game_init_buttons(game) || game_init_audio(game))
        return (game_destroy(game));
    if (game_init_background(game))
        return (game_destroy(game));
    game->player = player_create(game->global_clock, game->tilemap);
    if (!game->player)
        return (game_destroy(game));
    audio_play_loop_music(game->audio, G_MAIN_THEME);
    return (game);
}