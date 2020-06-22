/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019_2
** File description:
** menu_callbacks
*/

#include "my_defender.h"

void get_controls(prog_stat_t *prog_stat, button_t *button, list_t *scene,
sfEvent *eve)
{
    prog_stat->scene_index = 4;
}

void main_menu(prog_stat_t *prog_stat, button_t *button, list_t *scene,
sfEvent *eve)
{
    prog_stat->scene_index = 0;
}

void quit_game(prog_stat_t *prog_stat, button_t *button, list_t *scene,
sfEvent *eve)
{
    prog_stat->running = 0;
}

void start_game(prog_stat_t *prog_stat, button_t *button, list_t *scene,
sfEvent *eve)
{
    prog_stat->scene_index = 1;
}