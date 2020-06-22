/*
** EPITECH PROJECT, 2020
** BUTTON_DRAW
** File description:
** Button_draw function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_window.h"
#include "my_button.h"

void button_draw(sfRenderWindow *window, button_t *button)
{
    sfVector2f pos;

    if (!window || !button)
        return;
    pos = (sfVector2f){button->bounds->left + button->bounds->width / 2,
        button->bounds->top + button->bounds->height / 2};
    sfSprite_setPosition(button->sprite, pos);
    win_draw_sprite(window, button->sprite);
}