/*
** EPITECH PROJECT, 2020
** MENU_HANDLE_EVENTS
** File description:
** Menu_handle_events function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_button.h"
#include "jam.h"

void menu_handle_events(menu_t *menu, sfEvent event)
{
    if (!menu)
        return;
    button_handle_events(menu->play_button, event);
    button_handle_events(menu->quit_button, event);
}