/*
** EPITECH PROJECT, 2019
** TILEMAP_DESTROY
** File description:
** Tilemap_destroy function
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_tilemap_libmy.h"
#include "my_tileset.h"
#include "my_tilemap.h"

int free_datas(char *map_data, char **map_datas, int rnt_value)
{
    if (map_data)
        free(map_data);
    if (map_datas)
        free_2d_str(map_datas);
    return (rnt_value);
}

int **destroy_map(int **map)
{
    if (!map)
        return (NULL);
    for (int k = 0; map[k]; k++)
        free(map[k]);
    free(map);
    return (NULL);
}

void destroy_maps(tilemap_t *tilemap)
{
    if (!tilemap->maps)
        return;
    for (int map_id = 0; map_id < tilemap->nb_maps; map_id++)
        if (tilemap->maps[map_id])
            destroy_map(tilemap->maps[map_id]);
    free(tilemap->maps);
}

void *tilemap_destroy(tilemap_t *tilemap)
{
    if (!tilemap)
        return (NULL);
    if (tilemap->tileset)
        tileset_destroy(tilemap->tileset);
    destroy_maps(tilemap);
    free(tilemap);
    return (NULL);
}