/*
** EPITECH PROJECT, 2020
** GAME_INIT
** File description:
** Game_init function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
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

sfText *init_text(void)
{
    sfText *text = sfText_create();
    static sfFont *font = NULL;
    static sfVector2f pos = {100, 20};

    if (font == NULL)
        font = sfFont_createFromFile("assets/solvic_font.ttf");
    sfText_setColor(text, sfWhite);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, pos);
    return (text);
}

int game_init_audio(game_t *game)
{
    game->audio = audio_create(G_MUSIC_COUNT, G_SOUND_COUNT);

    if (!game->audio)
        return (EXIT_FAILURE);
    audio_add_sound(&game->audio, CANON_SOUND_PATH);
    audio_add_sound(&game->audio, MISSILE_SOUND_PATH);
    audio_add_sound(&game->audio, SNIPER_SOUND_PATH);
    audio_add_sound(&game->audio, EXPLOSION_SOUND_PATH);
    audio_add_music(&game->audio, MAIN_THEME_PATH);
    if (!game->audio)
        return (EXIT_FAILURE);
    sfSound_setVolume(game->audio->sounds[G_EXPLOSION_SOUND], 20);
    sfMusic_setVolume(game->audio->musics[G_MAIN_THEME], 80);
    return (EXIT_SUCCESS);
}