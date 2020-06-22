/*
** EPITECH PROJECT, 2020
** BUTTON_UPDATE
** File description:
** Button_update function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_clock.h"
#include "my_button.h"

void button_update(button_t *button)
{
    if (!button)
        return;
    if (button->is_clicked || button->is_pressed ||
        clock_get_ms(button->clock) - button->pressed_at < MIN_ANIM_TIME)
        sfSprite_setScale(button->sprite, button->pressed_scale);
    else if (button->is_passed)
        sfSprite_setScale(button->sprite, button->passed_scale);
    else
        sfSprite_setScale(button->sprite, button->normal_scale);
    if (button->is_clicked)
        button->is_clicked--;
    if (button->is_released)
        button->is_released--;
}

int button_is_click(button_t *button)
{
    if ((button->is_pressed && !button->is_clicked) || button->is_released)
        return (1);
    return (0);
}

void button_force_press(button_t *button)
{
    if (!button)
        return;
    button->is_clicked = 2;
    button->is_pressed = 1;
    button->is_released = 0;
    button->is_passed = 1;
}

void button_force_release(button_t *button)
{
    if (!button)
        return;
    button->is_clicked = 0;
    button->is_pressed = 0;
    button->is_released = 2;
    button->is_passed = 0;
}

void button_force_reset(button_t *button)
{
    if (!button)
        return;
    button->is_clicked = 0;
    button->is_pressed = 0;
    button->is_released = 0;
    button->is_passed = 0;
}