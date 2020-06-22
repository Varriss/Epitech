/*
** EPITECH PROJECT, 2020
** GAMESTATE_MANAGER_SET_STATE
** File description:
** Gamestate_manager_set_state function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_gamestate_manager.h"

void gamestate_manager_load_state(gamestate_manager_t *gsm, int state)
{
    if (!gsm || state < 0 || state >= gsm->gamestate_count)
        return;
    if (gsm->current_state_data[state])
        return;
    if (!gsm->create_states || !gsm->create_states[state])
        return;
    gsm->current_state_data[state] = gsm->create_states[state](gsm);
}

void gamestate_manager_unload_state(gamestate_manager_t *gsm, int state)
{
    if (!gsm || state < 0 || state >= gsm->gamestate_count)
        return;
    if (!gsm->current_state_data)
        return;
    if (!gsm->destroy_states || !gsm->destroy_states[state])
        return;
    gsm->current_state_data[state] = gsm->destroy_states[state](
        gsm->current_state_data[state]
    );
    gsm->current_state_data[state] = NULL;
}

int gamestate_manager_set_state(gamestate_manager_t *gsm,
    int state, int destroy)
{
    if (!gsm || state < 0 || state >= gsm->gamestate_count)
        return (EXIT_FAILURE);
    if (destroy)
        gamestate_manager_unload_state(gsm, gsm->current_state);
    gsm->current_state = state;
    gamestate_manager_load_state(gsm, gsm->current_state);
    if (!gsm->current_state_data[gsm->current_state])
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}