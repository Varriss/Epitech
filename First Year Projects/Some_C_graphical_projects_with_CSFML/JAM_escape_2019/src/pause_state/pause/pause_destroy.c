/*
** EPITECH PROJECT, 2020
** PAUSE_DESTROY
** File description:
** Pause_destroy function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_button.h"
#include "jam.h"

void *pause_destroy(pause_t *pause)
{
    if (!pause)
        return (NULL);
    if (pause->bg_texture)
        sfTexture_destroy(pause->bg_texture);
    if (pause->bg_sprite)
        sfSprite_destroy(pause->bg_sprite);
    if (pause->resume_button)
        button_destroy(pause->resume_button);
    if (pause->restart_button)
        button_destroy(pause->restart_button);
    if (pause->menu_button)
        button_destroy(pause->menu_button);
    if (pause->quit_button)
        button_destroy(pause->quit_button);
    free(pause);
    return (NULL);
}