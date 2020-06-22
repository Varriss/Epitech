/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** check_enemy_state
*/

#include "my_defender.h"

int check_enemy_state(enemy_t *enemy, list_t *game_scene,
prog_stat_t *prog_stat)
{
    list_t *cursor = game_scene->next;

    for (; cursor != game_scene && cursor->data->enemy != enemy;
    cursor = cursor->next);
    if (enemy->life <= 0)
        enemy->state = 0;
    if (enemy->pos.x == END_X && enemy->pos.y == END_Y) {
        enemy->state = 0;
        find_object(game_scene, level_type)->data->level->p_info->life -= 1;
    }
    if (enemy->state == 0) {
        enemy->destroy(NULL, enemy);
        enemy = NULL;
        cursor = rm_elem(cursor);
        return (0);
    }
    if (find_object(game_scene, level_type)->data->level->p_info->life <= 0)
        prog_stat->scene_index = 3;
    return (1);
}