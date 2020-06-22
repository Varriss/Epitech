/*
** EPITECH PROJECT, 2019
** TILEMAP_DRAW
** File description:
** Tilemap_draw function
*/

#include <SFML/Graphics.h>
#include "my_window.h"
#include "my_tileset.h"
#include "my_tilemap.h"

sfVector2f get_pos(tilemap_t *tilemap, int row, int col)
{
    sfVector2f pos;

    pos.x = col * tilemap->tilesize + tilemap->x;
    pos.y = row * tilemap->tilesize + tilemap->y;
    return (pos);
}

void tilemap_draw_map(sfRenderWindow *window, sfSprite *sprite,
    tilemap_t *tilemap, int **map)
{
    int row = 0;
    int col_min = -tilemap->x / tilemap->tilesize;
    int col = 0;
    sfTexture *texture_tile;

    if (col_min < 0)
        col_min = 0;
    while (row < tilemap->height) {
        if (map[row][col] != 0) {
            texture_tile = tileset_get(tilemap->tileset, map[row][col] - 1);
            sfSprite_setTexture(sprite, texture_tile, sfFalse);
            sfSprite_setPosition(sprite, get_pos(tilemap, row, col));
            win_draw_sprite(window, sprite);
        }
        col++;
        if (col - col_min > tilemap->frame_width / tilemap->tilesize + 2
            || col >= tilemap->width) {
            col = col_min;
            row++;
        }
    }
}

void tilemap_draw_layer_scale(sfRenderWindow *window, tilemap_t *tilemap,
    int layer, float s)
{
    sfSprite *sprite;
    float scale_x = tilemap->tilesize / (float)tilemap->tileset->tilesize_x;
    float scale_y = tilemap->tilesize / (float)tilemap->tileset->tilesize_y;

    scale_x *= s;
    scale_y *= s;
    if (layer < 0 || layer > tilemap->nb_maps)
        return;
    sprite = sfSprite_create();

    sfSprite_scale(sprite, (sfVector2f){scale_x, scale_y});
    if (tilemap->maps[layer])
        tilemap_draw_map(window, sprite, tilemap, tilemap->maps[layer]);
    sfSprite_destroy(sprite);
}

void tilemap_draw_layer(sfRenderWindow *window, tilemap_t *tilemap, int layer)
{
    sfSprite *sprite;
    float scale_x = tilemap->tilesize / (float)tilemap->tileset->tilesize_x;
    float scale_y = tilemap->tilesize / (float)tilemap->tileset->tilesize_y;

    if (layer < 0 || layer > tilemap->nb_maps)
        return;
    sprite = sfSprite_create();

    sfSprite_scale(sprite, (sfVector2f){scale_x, scale_y});
    if (tilemap->maps[layer])
        tilemap_draw_map(window, sprite, tilemap, tilemap->maps[layer]);
    sfSprite_destroy(sprite);
}

void tilemap_draw(sfRenderWindow *window, tilemap_t *tilemap)
{
    sfSprite *sprite = sfSprite_create();
    float scale_x = tilemap->tilesize / (float)tilemap->tileset->tilesize_x;
    float scale_y = tilemap->tilesize / (float)tilemap->tileset->tilesize_y;

    sfSprite_scale(sprite, (sfVector2f){scale_x, scale_y});
    for (int map_id = 0; tilemap->maps && map_id < tilemap->nb_maps; map_id++)
        if (tilemap->maps[map_id])
            tilemap_draw_map(window, sprite, tilemap, tilemap->maps[map_id]);
    sfSprite_destroy(sprite);
}