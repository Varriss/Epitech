/*
** EPITECH PROJECT, 2019
** TILEMAP_LOAD_MAP
** File description:
** Tilemap_load_map function
*/

#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include "my_tilemap_libmy.h"
#include "my_tilemap.h"

int get_map_size(tilemap_t *tilemap, char **map_datas)
{
    if (!tilemap || !map_datas)
        return (0);
    if (!map_datas[0] || !my_str_isint(map_datas[0]))
        return (0);
    tilemap->width = my_get_nbr(map_datas[0]);
    if (!map_datas[1] || !my_str_isint(map_datas[1]))
        return (0);
    tilemap->height = my_get_nbr(map_datas[1]);
    return (1);
}

int *tilemap_create_map_line(char **line_tokens, int width)
{
    int *map_line = malloc(sizeof(int) * (width + 1));

    if (!map_line)
        return (NULL);
    for (int k = 0; k < width; k++) {
        if (!line_tokens[k] || !my_str_isint(line_tokens[k])) {
            free(map_line);
            return (NULL);
        }
        map_line[k] = my_get_nbr(line_tokens[k]) * (rand() % (4 * 4 - 1) + 1);
    }
    map_line[width] = -1;
    return (map_line);
}

int **tilemap_create_map(char **map_datas, int width, int height)
{
    int **map = malloc(sizeof(int *) * (height + 1));
    char **line;

    if (!map)
        return (NULL);
    for (int k = 0; k < height + 1; k++)
        map[k] = NULL;
    for (int y = 0; y < height; y++) {
        line = my_strtok(map_datas[y], ' ');
        if (!line)
            return (destroy_map(map));
        map[y] = tilemap_create_map_line(line, width);
        free_2d_str(line);
        if (!map[y])
            return (destroy_map(map));
    }
    return (map);
}

int tilemap_create_maps(tilemap_t *tilemap, char **datas)
{
    int after = 2;
    int w = tilemap->width;
    int h = tilemap->height;

    tilemap->maps = malloc(sizeof(int **) * (tilemap->nb_maps + 1));
    if (!tilemap->maps)
        return (0);
    for (int map_id = 0; map_id < tilemap->nb_maps + 1; map_id++)
        tilemap->maps[map_id] = NULL;
    if (str_array_len((char const **)datas) < 2 + (h + 1) * tilemap->nb_maps)
        return (0);
    for (int map_id = 0; map_id < tilemap->nb_maps; map_id++) {
        tilemap->maps[map_id] = tilemap_create_map(&datas[after], w, h);
        if (!tilemap->maps[map_id])
            return (0);
        after += h + 1;
    }
    return (1);
}

int tilemap_load_map(tilemap_t *tilemap, char const *map_path, int nb_maps)
{
    char *map_data = NULL;
    char **map_datas = NULL;

    if (!map_path || !tilemap)
        return (0);
    tilemap->nb_maps = nb_maps;
    map_data = read_file(map_path);
    if (!map_data)
        return (0);
    map_datas = my_strtok(map_data, (char)'\n');
    if (!map_datas)
        return (free_datas(map_data, map_datas, 0));
    if (!get_map_size(tilemap, map_datas))
        return (free_datas(map_data, map_datas, 0));
    if (!tilemap_create_maps(tilemap, map_datas))
        return (free_datas(map_data, map_datas, 0));
    tilemap_update_bounds(tilemap);
    return (free_datas(map_data, map_datas, 1));
}