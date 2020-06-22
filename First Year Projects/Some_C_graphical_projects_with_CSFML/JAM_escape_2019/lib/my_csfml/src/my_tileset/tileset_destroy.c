/*
** EPITECH PROJECT, 2020
** TILESET_DESTROY
** File description:
** Tileset_destroy function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_tileset.h"

void *tileset_destroy(tileset_t *tileset)
{
    if (!tileset)
        return (NULL);
    if (tileset->tiles) {
        for (int tile = 0; tile < tileset->nb_tiles; tile++)
            sfTexture_destroy(tileset->tiles[tile]);
        free(tileset->tiles);
    }
    free(tileset);
    return (NULL);
}