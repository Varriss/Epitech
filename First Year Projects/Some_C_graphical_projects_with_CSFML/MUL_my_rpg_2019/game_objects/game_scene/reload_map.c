/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_scene_buttons
*/

#include "my_rpg.h"

void reload_map(prog_stat_t *prog_stat, list_t *scene)
{
    list_data_t *data = malloc(sizeof(list_data_t));
    list_t *cursor = NULL;

    cursor = find_object(scene, tile_map_type);
    if (cursor && cursor->data->tile_map->destroy) {
        cursor->data->tile_map->destroy(prog_stat, cursor->data->tile_map);
        rm_elem(cursor);
    }
    cursor = find_object(scene, clock_type);
    if (cursor && cursor->data->clock->destroy) {
        cursor->data->clock->destroy(prog_stat, cursor->data->clock);
        rm_elem(cursor);
    }
    initialize_map(scene);
    data->clock = clock_create();
    add_to_queue(scene, data);
}