/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** level
*/

#include <stdlib.h>
#include "my_defender.h"

static player_info_t *init_player_info(void)
{
    player_info_t *p_info = malloc(sizeof(player_info_t));

    p_info->life = 5;
    p_info->money = 300;
    p_info->score = 0;
    return (p_info);
}

static level_info_t *init_level_info(char **map)
{
    level_info_t *l_info = malloc(sizeof(level_info_t));

    l_info->map = map;
    l_info->enemies_to_spawn[0] = 5;
    l_info->enemies_to_spawn[1] = 0;
    l_info->enemies_to_spawn[2] = 0;
    l_info->enemies_left = 0;
    return (l_info);
}

void init_level(list_t *g_o_list)
{
    level_t *level = malloc(sizeof(level_t));
    list_data_t *level_elem = malloc(sizeof(list_data_t));

    level->type = level_type;
    level->update = NULL;
    level->render = NULL;
    level->destroy = &destroy_level;
    level->l_info = init_level_info(\
        find_object(g_o_list, tile_map_type)->data->tile_map->map);
    level->p_info = init_player_info();
    level->selected_tower = 0;
    level->last_selected_tower = 0;
    level_elem->level = level;
    add_to_front(g_o_list, level_elem);
}