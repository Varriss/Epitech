/*
** EPITECH PROJECT, 2020
** BUTTON_DESTROY
** File description:
** Button_destroy function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_clock.h"
#include "my_button.h"

void *button_destroy(button_t *button)
{
    if (!button)
        return (NULL);
    if (button->clock)
        clock_destroy(button->clock);
    if (button->bounds)
        free(button->bounds);
    if (button->text)
        free(button->text);
    if (button->texture)
        sfTexture_destroy(button->texture);
    if (button->sprite)
        sfSprite_destroy(button->sprite);
    free(button);
    return (NULL);
}