/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019_2
** File description:
** event_functions
*/

#include "my_defender.h"

void key_pressed(sfEvent *event, prog_stat_t *prog_stat, list_t *g_o_list)
{
    if (event->key.code == sfKeyEscape && prog_stat->scene_index == 1) {
        sfTexture_updateFromRenderWindow(prog_stat->last_window,
        prog_stat->window, 0, 0);
        prog_stat->scene_index = 2;
    } else if (event->key.code == sfKeyEscape
    && prog_stat->scene_index == 2) {
        prog_stat->scene_index = 1;
    } else if (event->key.code == sfKeyEscape
    && prog_stat->scene_index == 4) {
        prog_stat->scene_index = 0;
    }
}

void close_window(sfEvent *event, prog_stat_t *prog_stat, list_t *g_o_list)
{
    sfRenderWindow_close(prog_stat->window);
}