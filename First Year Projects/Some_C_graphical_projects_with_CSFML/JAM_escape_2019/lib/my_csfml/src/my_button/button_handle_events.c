/*
** EPITECH PROJECT, 2020
** BUTTON_HANDLE_EVENTS
** File description:
** Button_handle_events function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_clock.h"
#include "my_button.h"

int button_is_clicked(button_t *button, sfVector2f click_pos)
{
    if (sfIntRect_contains(button->bounds, (int)click_pos.x, (int)click_pos.y))
        return (1);
    return (0);
}

void button_handle_events_click(button_t *button, sfEvent event)
{
    sfVector2f click_pos = {0, 0};

    if (event.type == sfEvtMouseButtonPressed) {
        click_pos = (sfVector2f){event.mouseButton.x, event.mouseButton.y};
        if (!button_is_clicked(button, click_pos))
            return;
        button->is_clicked = 2;
        button->is_pressed = 1;
        button->is_released = 0;
        button->pressed_at = clock_get_ms(button->clock);
        if (button->callback)
            button->callback();
    }
    else if (event.type == sfEvtMouseButtonReleased) {
        if (button->is_pressed)
            button->is_released = 2;
        button->is_pressed = 0;
    }
}

void button_handle_events_pass(button_t *button, sfEvent event)
{
    sfVector2u click_pos = {0, 0};

    if (event.type == sfEvtMouseMoved) {
        click_pos = (sfVector2u){event.mouseMove.x, event.mouseMove.y};
        if (sfIntRect_contains(button->bounds, click_pos.x, click_pos.y))
            button->is_passed  = 1;
        else
            button->is_passed  = 0;
    }
}

void button_handle_events(button_t *button, sfEvent event)
{
    if (!button)
        return;
    button_handle_events_click(button, event);
    button_handle_events_pass(button, event);
}