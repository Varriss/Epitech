/*
** EPITECH PROJECT, 2020
** PAUSE_CREATE
** File description:
** Pause_create function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_button.h"
#include "jam.h"

pause_t *pause_create(gamestate_manager_t *gsm)
{
    pause_t *pause = malloc(sizeof(pause_t));

    if (!pause)
        return (NULL);
    pause->gsm = gsm;
    pause->bg_texture = NULL;
    pause->bg_sprite = sfSprite_create();
    pause->resume_button = button_create_from_path(P_RECT_RESUME,
        P_RESUME_PATH);
    pause->restart_button = button_create_from_path(P_RECT_RESTART,
        P_REPLAY_PATH);
    pause->menu_button = button_create_from_path(P_RECT_MENU,
        P_MENU_PATH);
    pause->quit_button = button_create_from_path(P_RECT_QUIT,
        P_QUIT_PATH);
    if (!pause->bg_sprite)
        return (NULL);
    return (pause);
}