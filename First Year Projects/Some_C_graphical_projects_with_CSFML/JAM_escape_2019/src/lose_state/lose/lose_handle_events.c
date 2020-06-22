/*
** EPITECH PROJECT, 2020
** LOSE_HANDLE_EVENTS
** File description:
** Lose_handle_events function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_gamestate_manager.h"
#include "my_button.h"
#include "jam.h"

void lose_handle_events(lose_t *lose, sfEvent event)
{
    button_handle_events(lose->menu_button, event);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
        gamestate_manager_set_state(lose->gsm, MENU_STATE, 1);
        return;
    }
}