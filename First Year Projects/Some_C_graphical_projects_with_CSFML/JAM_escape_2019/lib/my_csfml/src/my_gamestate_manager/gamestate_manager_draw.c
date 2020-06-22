/*
** EPITECH PROJECT, 2020
** GAMESTATE_MANAGER_DRAW
** File description:
** Gamestate_manager_draw function
*/

#include <SFML/Graphics.h>
#include "my_gamestate_manager.h"

void gamestate_manager_draw(sfRenderWindow *window, gamestate_manager_t *gsm)
{
    if (gsm->current_state == -1 || !gsm->current_state_data
        || !gsm->current_state_data[gsm->current_state])
        return;
    if (!gsm->draw_states || !gsm->draw_states[gsm->current_state])
        return;
    gsm->draw_states[gsm->current_state](
        window, gsm->current_state_data[gsm->current_state]
    );
}