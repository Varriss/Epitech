/*
** EPITECH PROJECT, 2020
** GAMESTATE_MANAGER_UPDATE
** File description:
** Gamestate_manager_update function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_gamestate_manager.h"

void gamestate_manager_update(gamestate_manager_t *gsm)
{
    if (gsm->current_state == -1 || !gsm->current_state_data
        || !gsm->current_state_data[gsm->current_state])
        return;
    if (!gsm->update_states || !gsm->update_states[gsm->current_state])
        return;
    gsm->update_states[gsm->current_state](
        gsm->current_state_data[gsm->current_state]
    );
}