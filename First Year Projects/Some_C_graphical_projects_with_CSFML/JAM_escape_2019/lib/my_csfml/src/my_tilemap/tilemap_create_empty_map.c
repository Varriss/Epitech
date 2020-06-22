/*
** EPITECH PROJECT, 2020
** TILEMAP_CREATE_EMPTY_MAP
** File description:
** Tilemap_create_empty_map function
*/

#include <stdlib.h>
#include <stddef.h>
#include <SFML/Graphics.h>
#include "my_tilemap.h"

int *create_empty_line(int width)
{
    int *line = malloc(sizeof(int) * (width));

    if (!line)
        return (NULL);
    for (int k = 0; k < width; k++)
        line[k] = 0;
    return (line);
}

int create_empty_map(tilemap_t *tilemap, int ***map)
{
    int width = tilemap->width;
    int height = tilemap->height;

    map[0] = malloc(sizeof(int *) * (height + 1));
    if (!map[0])
        return (1);
    for (int row = 0; row < height + 1; row++)
        map[0][row] = NULL;
    for (int row = 0; row < height; row++) {
        map[0][row] = create_empty_line(width);
        if (!map[0][row])
            return (1);
    }
    return (0);
}

int tilemap_create_empty_maps(tilemap_t *tilemap, int nb_maps,
    int width, int height)
{
    tilemap->width = width;
    tilemap->height = height;
    tilemap->nb_maps = nb_maps;
    tilemap->maps = malloc(sizeof(int **) * (nb_maps + 1));
    if (!tilemap->maps)
        return (0);
    for (int map_id = 0; map_id < tilemap->nb_maps + 1; map_id++)
        tilemap->maps[map_id] = NULL;
    for (int map_id = 0; map_id < tilemap->nb_maps; map_id++)
        if (create_empty_map(tilemap, &tilemap->maps[map_id]))
            return (0);
    return (1);
}