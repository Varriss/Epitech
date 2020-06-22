/*
** EPITECH PROJECT, 2019
** TILEMAP
** File description:
** Tilemap_create function
*/

#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include "my_tileset.h"
#include "my_tilemap.h"

void tilemap_update_bounds(tilemap_t *tilemap)
{
    if (!tilemap)
        return;
    tilemap->xmax = tilemap->frame_width - tilemap->width * tilemap->tilesize;
    tilemap->ymax = tilemap->frame_height;
    tilemap->ymax -= tilemap->height * tilemap->tilesize;
}

void init_tilemap(tilemap_t *tilemap)
{
    tilemap->last_time_update = -1;
    tilemap->x = 0;
    tilemap->y = 0;
    tilemap->width = 0;
    tilemap->height = 0;
    tilemap->xmin = 0;
    tilemap->xmax = 0;
    tilemap->ymin = 0;
    tilemap->ymax = 0;
    tilemap->tween = 0.5;
    tilemap->tileset = NULL;
    tilemap->nb_maps = 0;
    tilemap->maps = NULL;
}

tilemap_t *tilemap_create(int tilesize, int frame_width, int frame_height)
{
    tilemap_t *tilemap = malloc(sizeof(tilemap_t));

    if (!tilemap)
        return (NULL);
    init_tilemap(tilemap);
    tilemap->frame_width = frame_width;
    tilemap->frame_height = frame_height;
    tilemap->tilesize = tilesize;
    return (tilemap);
}

int tilemap_load_tiles(tilemap_t *tilemap, char const *tileset_path, int size)
{
    int rnt_value;
    sfTexture *texture = sfTexture_createFromFile(tileset_path, NULL);
    int nb_col_tiles;
    int nb_row_tiles;

    if (!texture)
        return (0);
    nb_col_tiles = sfTexture_getSize(texture).x / size;
    nb_row_tiles = sfTexture_getSize(texture).y / size;
    tilemap->tileset = tileset_create(nb_col_tiles * nb_row_tiles);
    if (!tilemap->tileset) {
        sfTexture_destroy(texture);
        return (0);
    }
    rnt_value = tileset_load(tilemap->tileset, tileset_path, size, size);
    sfTexture_destroy(texture);
    return (rnt_value);
}