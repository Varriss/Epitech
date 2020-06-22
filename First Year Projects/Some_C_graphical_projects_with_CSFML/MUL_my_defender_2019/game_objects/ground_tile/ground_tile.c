/*
** EPITECH PROJECT, 2020
** GROUND_TILE
** File description:
** Contains functions for ground_tiles
*/

#include <stdlib.h>
#include "my_defender.h"

static void render_g_tile(g_tile_t *tile, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, tile->sprite, NULL);
}

static void destroy_g_tile(g_tile_t *tile)
{
    sfTexture_destroy(tile->texture);
    sfSprite_destroy(tile->sprite);
    free(tile);
}

static void fill_tile_dimensions(sfIntRect *rect, sfVector2f *pos)
{
    rect->left = pos->x;
    rect->top = pos->y;
    rect->width = TILE_WIDTH;
    rect->height = TILE_HEIGHT;
}

g_tile_t *create_g_tile(sfVector2f *pos, char *path)
{
    g_tile_t *this_tile = malloc(sizeof(g_tile_t));

    if (!this_tile)
        return (NULL);
    this_tile->texture = sfTexture_createFromFile(path, NULL);
    this_tile->sprite = sfSprite_create();
    this_tile->type = ground_type;
    fill_tile_dimensions(&(this_tile->rect), pos);
    this_tile->pos.x = pos->x;
    this_tile->pos.y = pos->y;
    sfSprite_setTexture(this_tile->sprite, this_tile->texture, sfTrue);
    sfSprite_setPosition(this_tile->sprite, this_tile->pos);
    this_tile->update = NULL;
    this_tile->render = &render_g_tile;
    this_tile->destroy = &destroy_g_tile;
    return (this_tile);
}

