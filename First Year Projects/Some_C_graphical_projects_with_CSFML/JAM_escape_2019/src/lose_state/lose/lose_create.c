/*
** EPITECH PROJECT, 2020
** LOSE_CREATE
** File description:
** Lose_create function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_tileset.h"
#include "my_clock.h"
#include "my_audio.h"
#include "my_button.h"
#include "my_sprite.h"
#include "jam.h"
#include "audio.h"

audio_t *lose_load_audio(void)
{
    audio_t *audio = audio_create(L_MUSIC_COUNT, L_SOUND_COUNT);

    if (!audio)
        return (NULL);
    audio_add_sound(&audio, WASTED_SOUND_PATH);
    return (audio);
}

int lose_load_button(lose_t *lose)
{
    sfTexture *texture;

    lose->button_textures = tileset_create(20);
    if (!lose->button_textures)
        return (EXIT_FAILURE);
    if (!tileset_load(lose->button_textures, GAME_BUTTONS, 64, 64))
        return (EXIT_FAILURE);
    texture = tileset_get(lose->button_textures, 1);
    lose->menu_button = button_create_from_texture(RECT_HELP_CLOSE, texture);
    if (!lose->menu_button)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

void lose_init(lose_t *lose, gamestate_manager_t *gsm)
{
    lose->gsm = gsm;
    lose->audio = NULL;
    lose->bg_texture = NULL;
    lose->wasted_texture = NULL;
    lose->bg_sprite = NULL;
    lose->wasted_sprite = NULL;
    lose->button_textures = NULL;
    lose->menu_button = NULL;
    lose->clock = NULL;
}

lose_t *lose_create(gamestate_manager_t *gsm)
{
    lose_t *lose = malloc(sizeof(lose_t));

    if (!lose)
        return (NULL);
    lose_init(lose, gsm);
    lose->audio = lose_load_audio();
    lose->wasted_texture = sfTexture_createFromFile(WASTED_PATH, NULL);
    lose->bg_sprite = sfSprite_create();
    lose->wasted_sprite = sfSprite_create();
    lose->clock = clock_create();
    if (!lose->audio || !lose->bg_sprite || !lose->wasted_sprite ||
        !lose->wasted_texture || !lose->clock)
        return (lose_destroy(lose));
    if (lose_load_button(lose))
        return (lose_destroy(lose));
    sprite_set_texture(lose->wasted_sprite, lose->wasted_texture,
        WIDTH, HEIGHT);
    sfClock_restart(lose->clock->clock);
    audio_play_sound(lose->audio, L_WASTED_SOUND);
    return (lose);
}