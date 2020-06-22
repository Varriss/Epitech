/*
** EPITECH PROJECT, 2020
** GAMESTATE_MANAGER_HANDLE_EVENTS
** File description:
** Gamestate_manager_handle_events function
*/

#include <SFML/Graphics.h>
#include "my_gamestate_manager.h"

void gamestate_manager_handle_events(gamestate_manager_t *gsm, sfEvent event)
{
    if (gsm->current_state == -1 || !gsm->current_state_data
        || !gsm->current_state_data[gsm->current_state])
        return;
    if (!gsm->input_states || !gsm->input_states[gsm->current_state])
        return;
    gsm->input_states[gsm->current_state](
        gsm->current_state_data[gsm->current_state], event
    );
}