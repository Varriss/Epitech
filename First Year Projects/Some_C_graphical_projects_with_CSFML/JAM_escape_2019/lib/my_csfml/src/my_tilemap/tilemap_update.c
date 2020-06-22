/*
** EPITECH PROJECT, 2020
** TILEMAP_UPDATE
** File description:
** Tilemap_update function
*/

#include <SFML/Graphics.h>
#include "my_clock.h"
#include "my_tilemap.h"

int tilemap_get_elapse(tilemap_t *tilemap, my_clock_t *clock)
{
    return (clock_get_ms(clock) - tilemap->last_time_update);
}

void tilemap_force_pos(tilemap_t *tilemap, float x, float y)
{
    if (!tilemap)
        return;
    tilemap->x += x;
    tilemap->y += y;
}

void tilemap_set_pos(tilemap_t *tilemap, my_clock_t *clock, float x, float y)
{
    float elapse;

    if (!tilemap)
        return;
    if (tilemap->last_time_update == -1)
        tilemap->last_time_update = clock_get_ms(clock);
    elapse = tilemap_get_elapse(tilemap, clock) / 100.0;
    tilemap->x += (x - tilemap->x) * tilemap->tween * elapse;
    tilemap->y += (y - tilemap->y) * tilemap->tween * elapse;
    /*if (tilemap->x > tilemap->xmin)
        tilemap->x = tilemap->xmin;
    if (tilemap->y > tilemap->ymin)
        tilemap->y = tilemap->ymin;
    if (tilemap->x < tilemap->xmax)
        tilemap->x = tilemap->xmax;
    if (tilemap->y < tilemap->ymax)
        tilemap->y = tilemap->ymax;*/
    tilemap->last_time_update = clock_get_ms(clock);
}