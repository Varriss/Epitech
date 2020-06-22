/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019_2
** File description:
** tile_map_callbacks
*/

#include <stdlib.h>
#include "my_defender.h"

static int prices[4] = {50, 150, 200, 250};

void up_tower(prog_stat_t *prog_stat, struct button *button,
list_t *scene, sfEvent *eve)
{
    int tower = find_object(scene, level_type)->data->level->selected_tower;
    int x = eve->mouseButton.x / TILE_WIDTH;
    int y = eve->mouseButton.y / TILE_HEIGHT;
    char **map = find_object(scene, tile_map_type)->data->tile_map->map;
    level_t * level = NULL;

    if ((eve->mouseButton.y < WINDOW_HEIGHT - 200) && (map[y][x] == '0') 
    && (tower > 0)) {
        map[y][x] = (tower + 1) + '0';
        add_to_queue(scene, init_tower(tower + 1
        , x * TILE_WIDTH, y * TILE_HEIGHT));
        level = find_object(scene, level_type)->data->level;
        level->selected_tower = 0;
        level->p_info->money -= prices[tower - 1];
    }
}

void destroy_tilemap(prog_stat_t *prog_stat, tile_map_t *tilemap)
{
    g_tile_t *cursor = NULL;

    for (int i = 0; i < tilemap->map_height; i++) {
        for (int j = 0; j < tilemap->map_width; j++) {
            cursor = tilemap->tiles[i][j].ground_tile;
            if (cursor)
                cursor->destroy(cursor);
        }
    }
    free(tilemap->tiles);
    free_my_str_arr(tilemap->map);
    free(tilemap);
}

void render_tilemap(prog_stat_t *prog_stat, tile_map_t *tilemap)
{
    g_tile_t *cursor = NULL;

    for (int i = 0; i < tilemap->map_height; i++) {
        for (int j = 0; j < tilemap->map_width; j++) {
            cursor = tilemap->tiles[i][j].ground_tile;
            if (cursor)
                cursor->render(cursor, prog_stat->window);
        }
    }
}