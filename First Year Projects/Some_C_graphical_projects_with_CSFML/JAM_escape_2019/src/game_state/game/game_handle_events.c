/*
** EPITECH PROJECT, 2020
** GAME_HANDLE_INPUTS
** File description:
** Game_handle_inputs function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_gamestate_manager.h"
#include "my_clock.h"
#include "my_button.h"
#include "jam.h"
#include "entity.h"

void game_handle_events(game_t *game, sfEvent event)
{
    if (!game)
        return;
    button_handle_events(game->pause_buttons, event);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
        clock_pause(game->global_clock);
        gamestate_manager_set_state(game->gsm, PAUSE_STATE, 0);
        return;
    }
    player_handle_events(game->player, event);
}