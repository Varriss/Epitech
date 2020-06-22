/*
** EPITECH PROJECT, 2020
** GAME_UPDATE
** File description:
** Game_update function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include "my_audio.h"
#include "my_gamestate_manager.h"
#include "my_clock.h"
#include "my_tilemap.h"
#include "my_button.h"
#include "jam.h"
#include "audio.h"
#include "entity.h"

void game_update_sound_and_pause(game_t *game)
{
    if (game->global_clock->is_paused)
        clock_unpause(game->global_clock);
    if (is_game_mute()) {
        sfMusic_setVolume(game->audio->musics[G_MAIN_THEME], 0);
        sfSound_setVolume(game->audio->sounds[G_CANON_SOUND], 0);
        sfSound_setVolume(game->audio->sounds[G_MISSILE_SOUND], 0);
        sfSound_setVolume(game->audio->sounds[G_SNIPER_SOUND], 0);
        sfSound_setVolume(game->audio->sounds[G_EXPLOSION_SOUND], 0);
    }
    else {
        sfMusic_setVolume(game->audio->musics[G_MAIN_THEME], 80);
        sfSound_setVolume(game->audio->sounds[G_CANON_SOUND], 100);
        sfSound_setVolume(game->audio->sounds[G_MISSILE_SOUND], 100);
        sfSound_setVolume(game->audio->sounds[G_SNIPER_SOUND], 100);
        sfSound_setVolume(game->audio->sounds[G_EXPLOSION_SOUND], 20);
    }
}

void game_update(game_t *game)
{
    if (!game)
        return;
    if (clock_get_s(game->global_clock) >= 360) {
        gamestate_manager_set_state(game->gsm, LOSE_STATE, 1);
        return;
    }
    if (game->player->x >= game->tilemap->width - 2, game->player->y >= game->tilemap->height - 2) {
        gamestate_manager_set_state(game->gsm, VICTORY_STATE, 1);
        return;
    }
    player_update(game->player);
    game_update_sound_and_pause(game);
    button_update(game->pause_buttons);
    if (button_is_click(game->pause_buttons)) {
        button_force_reset(game->pause_buttons);
        clock_pause(game->global_clock);
        gamestate_manager_set_state(game->gsm, PAUSE_STATE, 0);
        return;
    }
    tilemap_set_pos(game->tilemap, game->global_clock,
        WIDTH / 2 - game->player->x * game->tilemap->tilesize,
        HEIGHT / 2 - game->player->y * game->tilemap->tilesize);
}