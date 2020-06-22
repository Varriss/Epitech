/*
** EPITECH PROJECT, 2020
** TILESET_CREATE
** File description:
** Tileset_create function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_tileset.h"

tileset_t *tileset_create(int nb_tiles)
{
    tileset_t *tileset = malloc(sizeof(tileset_t));

    if (!tileset)
        return (NULL);
    tileset->nb_tiles = nb_tiles;
    tileset->tiles = malloc(sizeof(sfTexture *) * (nb_tiles + 1));
    if (!tileset->tiles)
        return (NULL);
    for (int tile = 0; tile < nb_tiles + 1; tile++)
        tileset->tiles[tile] = NULL;
    return (tileset);
}