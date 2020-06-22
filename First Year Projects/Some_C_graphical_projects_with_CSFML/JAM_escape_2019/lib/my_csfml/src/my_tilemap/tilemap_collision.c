/*
** EPITECH PROJECT, 2019
** TILEMAP_COLLISION
** File description:
** Tilemap_collision function
*/

#include <SFML/Graphics.h>
#include "my_tilemap.h"

int tilemap_can_collide(tilemap_t *tilemap, int map_id, sfFloatRect bounds)
{
    if (!tilemap || !tilemap->nb_maps || !tilemap->maps)
        return (0);
    if (!tilemap->maps[map_id])
        return (0);
    if (bounds.left + bounds.width < 0)
        return (0);
    if (bounds.left > tilemap->width * tilemap->tilesize)
        return (0);
    if (bounds.top + bounds.height < 0)
        return (0);
    if (bounds.top > tilemap->height * tilemap->tilesize)
        return (0);
    return (1);
}

int tilemap_rect_col(sfFloatRect a, sfFloatRect b)
{
    if (a.left < b.left + b.width &&
        a.left + a.width > b.left &&
        a.top < b.top + b.height &&
        a.top + a.height > b.top)
        return (1);
    return (0);
}

int update_row_col(tilemap_t *tilemap, int *row, int *col, int col_min)
{
    col[0]++;
    if (col[0] - col_min > tilemap->frame_width / tilemap->tilesize + 2
        || col[0] >= tilemap->width) {
        col[0] = col_min;
        row[0]++;
        return (1);
    }
    return (0);
}

int tilemap_map_collision(tilemap_t *tilemap, int map_id,
    sfFloatRect bounds, sfFloatRect *collision)
{
    int row = 0;
    int col_min = bounds.left / tilemap->tilesize;
    int col = 0;

    if (col_min < 0)
        col_min = 0;
    if (!collision)
        collision = &(sfFloatRect){0, 0, 0, 0};
    if (!tilemap_can_collide(tilemap, map_id, bounds))
        return (0);
    collision[0] = (sfFloatRect){0, 0, tilemap->tilesize, tilemap->tilesize};
    while (row < tilemap->height) {
        collision->left = col * tilemap->tilesize;
        if (tilemap->maps[map_id][row][col] != 0 &&
            tilemap_rect_col(bounds, *collision))
            return (1);
        if (update_row_col(tilemap, &row, &col, col_min))
            collision->top = row * tilemap->tilesize;
    }
    return (0);
}