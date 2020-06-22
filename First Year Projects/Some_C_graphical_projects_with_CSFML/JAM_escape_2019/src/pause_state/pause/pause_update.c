/*
** EPITECH PROJECT, 2020
** PAUSE_UPDATE
** File description:
** Pause_update function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_gamestate_manager.h"
#include "my_button.h"
#include "jam.h"

void pause_button_check(pause_t *pause)
{
    if (button_is_click(pause->resume_button)) {
        gamestate_manager_set_state(pause->gsm, GAME_STATE, 1);
        return;
    }
    if (button_is_click(pause->restart_button)) {
        gamestate_manager_unload_state(pause->gsm, GAME_STATE);
        gamestate_manager_set_state(pause->gsm, GAME_STATE, 1);
        return;
    }
    if (button_is_click(pause->menu_button)) {
        gamestate_manager_unload_state(pause->gsm, GAME_STATE);
        gamestate_manager_set_state(pause->gsm, MENU_STATE, 1);
        return;
    }
    if (button_is_click(pause->quit_button)) {
        kill_game();
        return;
    }
}

void pause_update(pause_t *pause)
{
    if (!pause)
        return;
    button_update(pause->resume_button);
    button_update(pause->restart_button);
    button_update(pause->menu_button);
    button_update(pause->quit_button);
    pause_button_check(pause);
}