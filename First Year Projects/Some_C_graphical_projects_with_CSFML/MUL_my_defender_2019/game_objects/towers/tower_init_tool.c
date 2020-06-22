/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tower_init_tool
*/

#include "my_defender.h"

static int costs[4] = {50, 150, 100, 100};

void t_one(prog_stat_t *prog_stat, button_t *button,
list_t *game_scene, sfEvent *eve)
{
    level_t *level = find_object(game_scene, level_type)->data->level;

    if (level->last_selected_tower != 1 && level->p_info->money >= costs[0]) {
        level->selected_tower = 1;
        level->last_selected_tower = 1;
    } else {
        level->selected_tower = 0;
        level->last_selected_tower = 0;
    }
}

void t_two(prog_stat_t *prog_stat, button_t *button,
list_t *game_scene, sfEvent *eve)
{
    level_t *level = find_object(game_scene, level_type)->data->level;

    if (level->last_selected_tower != 2 && level->p_info->money >= costs[1]) {
        level->selected_tower = 2;
        level->last_selected_tower = 2;
    } else {
        level->selected_tower = 0;
        level->last_selected_tower = 0;
    }
}

void t_three(prog_stat_t *prog_stat, button_t *button,
list_t *game_scene, sfEvent *eve)
{
    level_t *level = find_object(game_scene, level_type)->data->level;

    if (level->last_selected_tower != 3 && level->p_info->money >= costs[2]) {
        level->selected_tower = 3;
        level->last_selected_tower = 3;
    } else {
        level->selected_tower = 0;
        level->last_selected_tower = 0;
    }
}

void t_four(prog_stat_t *prog_stat, button_t *button,
list_t *game_scene, sfEvent *eve)
{
    level_t *level = find_object(game_scene, level_type)->data->level;

    if (level->last_selected_tower != 4 && level->p_info->money >= costs[3]) {
        level->selected_tower = 4;
        level->last_selected_tower = 4;
    } else {
        level->selected_tower = 0;
        level->last_selected_tower = 0;
    }
}