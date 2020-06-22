/*
** EPITECH PROJECT, 2020
** VICTORY_HANDLE_EVENTS
** File description:
** Victory_handle_events function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_gamestate_manager.h"
#include "my_button.h"
#include "jam.h"

void victory_handle_events(victory_t *victory, sfEvent event)
{
    button_handle_events(victory->menu_button, event);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
        gamestate_manager_set_state(victory->gsm, MENU_STATE, 1);
        return;
    }
}