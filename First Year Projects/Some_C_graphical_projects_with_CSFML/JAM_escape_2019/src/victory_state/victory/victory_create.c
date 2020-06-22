/*
** EPITECH PROJECT, 2020
** VICTORY_CREATE
** File description:
** Victory_create function
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

audio_t *victory_load_audio(void)
{
    audio_t *audio = audio_create(L_MUSIC_COUNT, L_SOUND_COUNT);

    if (!audio)
        return (NULL);
    audio_add_sound(&audio, WASTED_SOUND_PATH);
    return (audio);
}

int victory_load_button(victory_t *victory)
{
    sfTexture *texture;

    victory->button_textures = tileset_create(20);
    if (!victory->button_textures)
        return (EXIT_FAILURE);
    if (!tileset_load(victory->button_textures, GAME_BUTTONS, 64, 64))
        return (EXIT_FAILURE);
    texture = tileset_get(victory->button_textures, 1);
    victory->menu_button = button_create_from_texture(RECT_HELP_CLOSE, texture);
    if (!victory->menu_button)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

void victory_init(victory_t *victory, gamestate_manager_t *gsm)
{
    victory->gsm = gsm;
    victory->audio = NULL;
    victory->bg_texture = NULL;
    victory->wasted_texture = NULL;
    victory->bg_sprite = NULL;
    victory->wasted_sprite = NULL;
    victory->button_textures = NULL;
    victory->menu_button = NULL;
    victory->clock = NULL;
}

victory_t *victory_create(gamestate_manager_t *gsm)
{
    victory_t *victory = malloc(sizeof(victory_t));

    if (!victory)
        return (NULL);
    victory_init(victory, gsm);
    victory->audio = victory_load_audio();
    victory->wasted_texture = sfTexture_createFromFile(VICTORY_PATH, NULL);
    victory->bg_sprite = sfSprite_create();
    victory->wasted_sprite = sfSprite_create();
    victory->clock = clock_create();
    if (!victory->audio || !victory->bg_sprite || !victory->wasted_sprite ||
        !victory->wasted_texture || !victory->clock)
        return (victory_destroy(victory));
    if (victory_load_button(victory))
        return (victory_destroy(victory));
    sprite_set_texture(victory->wasted_sprite, victory->wasted_texture,
        WIDTH, HEIGHT);
    sfClock_restart(victory->clock->clock);
    audio_play_sound(victory->audio, L_WASTED_SOUND);
    return (victory);
}