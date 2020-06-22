/*
** EPITECH PROJECT, 2020
** TILESET_GET
** File description:
** Tileset_get function
*/

#include <stddef.h>
#include <SFML/Graphics.h>
#include "my_tileset.h"

sfTexture *tileset_get(tileset_t *tileset, int id)
{
    if (id > tileset->nb_tiles || id < 0)
        return (NULL);
    return (tileset->tiles[id]);
}