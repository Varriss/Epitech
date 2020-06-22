/*
** EPITECH PROJECT, 2020
** BUTTON_INIT
** File description:
** Button_init function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_clock.h"
#include "my_button.h"

void button_init_null(button_t *button)
{
    button->clock = NULL;
    button->bounds = NULL;
    button->texture = NULL;
    button->sprite = NULL;
    button->text = NULL;
    button->callback = NULL;
    button->pressed_at = -MIN_ANIM_TIME;
    button->is_clicked = 0;
    button->is_pressed = 0;
    button->is_released = 0;
    button->is_passed = 0;
}

void button_init_bounds(button_t *button, sfIntRect bounds)
{
    button->bounds->height = bounds.height;
    button->bounds->left = bounds.left;
    button->bounds->top = bounds.top;
    button->bounds->width = bounds.width;
    button->normal_scale = (sfVector2f){button->bounds->width,
        button->bounds->height};
}
