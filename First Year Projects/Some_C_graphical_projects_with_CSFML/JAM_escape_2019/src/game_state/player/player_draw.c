/*
** EPITECH PROJECT, 2020
** PLAYER_DRAW
** File description:
** Player_draw function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_audio.h"
#include "my_tileset.h"
#include "my_animation.h"
#include "my_tilemap.h"
#include "my_clock.h"
#include "tilemap.h"
#include "jam.h"
#include "entity.h"

void player_draw(sfRenderWindow *window, player_t *player)
{
    sfVector2f scale = {0.7, 0.7};
    sfVector2f move = {player->x * player->tilemap->tilesize + player->tilemap->x,
        player->y * player->tilemap->tilesize + player->tilemap->y};
    sfTexture *texture = animation_get_animation(player->animation);

    if (!texture)
        return;
    move.x -= player->width / 2;
    move.y -= player->height / 2;
    sfSprite_setPosition(player->sprite, move);
    sfSprite_setScale(player->sprite, scale);
    sfSprite_setTexture(player->sprite, texture, sfFalse);
    win_draw_sprite(window, player->sprite);
}