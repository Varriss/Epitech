/*
** EPITECH PROJECT, 2020
** PAUSE_HANDLE_EVENTS
** File description:
** Pause_handle_events function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_gamestate_manager.h"
#include "my_button.h"
#include "jam.h"

void pause_handle_events(pause_t *pause, sfEvent event)
{
    if (!pause)
        return;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
        gamestate_manager_set_state(pause->gsm, GAME_STATE, 1);
        return;
    }
    button_handle_events(pause->resume_button, event);
    button_handle_events(pause->restart_button, event);
    button_handle_events(pause->menu_button, event);
    button_handle_events(pause->quit_button, event);
}