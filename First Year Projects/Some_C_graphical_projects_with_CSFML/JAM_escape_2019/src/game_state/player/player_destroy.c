/*
** EPITECH PROJECT, 2020
** PLAYER_DESTROY
** File description:
** Player_destroy function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_audio.h"
#include "my_tileset.h"
#include "my_tilemap.h"
#include "my_animation.h"
#include "my_clock.h"
#include "tilemap.h"
#include "jam.h"
#include "entity.h"

void *player_destroy(player_t *player)
{
    if (!player)
        return (NULL);
    if (player->sprite)
        sfSprite_destroy(player->sprite);
    if (player->animation)
        animation_destroy(player->animation);
    free(player);
    return (NULL);
}