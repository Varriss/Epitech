/*
** EPITECH PROJECT, 2020
** GAMESTATE_MANAGER_DESTROY
** File description:
** Gamestate_manager_destroy function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_gamestate_manager.h"

void *gamestate_manager_destroy(gamestate_manager_t *gsm)
{
    if (!gsm)
        return (NULL);
    for (int k = 0; k < gsm->gamestate_count; k++)
        gamestate_manager_unload_state(gsm, k);
    if (gsm->current_state_data)
        free(gsm->current_state_data);
    if (gsm->create_states)
        free(gsm->create_states);
    if (gsm->input_states)
        free(gsm->input_states);
    if (gsm->update_states)
        free(gsm->update_states);
    if (gsm->draw_states)
        free(gsm->draw_states);
    if (gsm->destroy_states)
        free(gsm->destroy_states);
    free(gsm);
    return (NULL);
}