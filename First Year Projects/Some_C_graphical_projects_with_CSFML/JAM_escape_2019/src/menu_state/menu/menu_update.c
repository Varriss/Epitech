/*
** EPITECH PROJECT, 2020
** MENU_UPDATE
** File description:
** Menu_update function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_gamestate_manager.h"
#include "my_button.h"
#include "jam.h"
#include "tilemap.h"

void menu_update_buttons(menu_t *menu)
{
    button_update(menu->play_button);
    button_update(menu->quit_button);
}

void menu_update(menu_t *menu)
{
    if (!menu)
        return;
    menu_update_buttons(menu);
    if ((menu->play_button->is_pressed && !menu->play_button->is_clicked)
        || menu->play_button->is_released) {
        gamestate_manager_set_state(menu->gsm, GAME_STATE, 1);
        return;
    }
    if ((menu->quit_button->is_pressed && !menu->quit_button->is_clicked)
        || menu->quit_button->is_released)
        kill_game();
    menu->last_update = clock_get_ms(menu->clock);
}