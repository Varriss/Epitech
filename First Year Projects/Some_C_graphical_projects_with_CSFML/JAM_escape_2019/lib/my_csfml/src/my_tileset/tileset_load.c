/*
** EPITECH PROJECT, 2020
** TILESET_LOAD
** File description:
** Tileset_load function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_tileset.h"

int tileset_load_all(tileset_t *tileset, sfImage *texture)
{
    int tilesize_x = tileset->tilesize_x;
    int tilesize_y = tileset->tilesize_y;
    sfTexture *tile = NULL;
    int nb_col_tiles = sfImage_getSize(texture).x / tilesize_x;
    int nb_row_tiles = sfImage_getSize(texture).y / tilesize_y;
    int x;
    int y;

    for (int id = 0; id < nb_col_tiles * nb_row_tiles; id++) {
        x = id % nb_col_tiles;
        y = id / nb_col_tiles;
        tile = sfTexture_createFromImage(texture,
            &(sfIntRect){x * tilesize_x, y * tilesize_y,
                tilesize_x, tilesize_y});
        sfTexture_setSmooth(tile, sfTrue);
        if (!tile)
            return (0);
        tileset->tiles[x + y * nb_col_tiles] = tile;
    }
    return (1);
}

int tileset_load(tileset_t *tileset, char const *tileset_path,
    int tilesize_x, int tilesize_y)
{
    sfImage *texture = sfImage_createFromFile(tileset_path);
    int rtn_value;

    if (!texture)
        return (0);
    tileset->tilesize_x = tilesize_x;
    tileset->tilesize_y = tilesize_y;
    rtn_value = tileset_load_all(tileset, texture);
    sfImage_destroy(texture);
    return (rtn_value);
}