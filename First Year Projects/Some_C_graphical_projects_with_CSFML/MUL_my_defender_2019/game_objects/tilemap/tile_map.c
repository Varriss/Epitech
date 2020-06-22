/*
** EPITECH PROJECT, 2020
** TILE_MAP
** File description:
** Contains tile map
*/

#include <stdlib.h>
#include "my_defender.h"

static char default_map[MAP_HEIGHT][MAP_WIDTH + 1] = {
    "0000000000000000",
    "0000001111100000",
    "1111001000100000",
    "000100100010011E",
    "0001001000100100",
    "0001111000111100",
    "0000000000000000",
};

static g_tile_t *convert_tile(sfVector2f *current_pos, char tile_type)
{
    if (tile_type == (ground_type + '0'))
        return (create_g_tile(current_pos, "Ressources/tilemap/tile1.png"));
    else if (tile_type == (ground_type + '1'))
        return (create_g_tile(current_pos, "Ressources/tilemap/tile2.png"));
    else
        return (NULL);
}

static tile_t **fill_tilemap(char **map_str, tile_map_t *dest)
{
    tile_t **tilemap;
    sfVector2f current_pos = {0, 0};

    tilemap = malloc(sizeof(tile_t *) * dest->map_height);
    for (int i = 0; map_str[i] && i < dest->map_height; i++) {
        current_pos.y = (i * TILE_HEIGHT);
        current_pos.x = 0;
        tilemap[i] = malloc(sizeof(tile_t) * (dest->map_width));
        for (int j = 0; map_str[i][j] && j < dest->map_width; j++) {
            current_pos.x = (j) * TILE_WIDTH;
            tilemap[i][j].ground_tile = convert_tile(&current_pos
            , map_str[i][j]);
        }
    }
    return (tilemap);
}

static tile_map_t *create_map(char **map_str)
{
    tile_map_t *tile_map = malloc(sizeof(tile_map_t));

    tile_map->type = tile_map_type;
    tile_map->map_height = MAP_HEIGHT;
    tile_map->map_width = MAP_WIDTH;
    tile_map->map = map_str;
    tile_map->tiles = fill_tilemap(tile_map->map, tile_map);
    tile_map->update = NULL;
    tile_map->render = &render_tilemap;
    tile_map->destroy = &destroy_tilemap;
    tile_map->onclick = &up_tower;
    return (tile_map);
}

int initialize_map(list_t *go_list)
{
    tile_map_t *tile_map;
    list_data_t *map_object = malloc(sizeof(list_data_t));
    char **map_str = malloc(sizeof(char *) * (MAP_HEIGHT + 1));

    if (!map_str)
        return (84);
    map_str[MAP_HEIGHT] = NULL;
    for (int i = 0; i < MAP_HEIGHT; i++)
        map_str[i] = my_strdup(default_map[i]);
    tile_map = create_map(map_str);
    if (!tile_map)
        return (84);
    map_object->tile_map = tile_map;
    add_to_front(go_list, map_object);
    return (0);
}