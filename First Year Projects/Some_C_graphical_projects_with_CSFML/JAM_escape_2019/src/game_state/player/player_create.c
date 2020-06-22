/*
** EPITECH PROJECT, 2020
** PLAYER_CREATE
** File description:
** Player_create function
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

int init_anim(player_t *player, animation_t *animation)
{
    if (animation_add_animation(animation, (int *)ANIM_IDLE_ANIM))
        return (1);
    animation_set_anim_delay(animation, 100);
    amination_safe_set_anim_seq(player->animation, ANIM_IDLE_ID);
    return (0);
}

player_t *player_create(my_clock_t *clock, tilemap_t *tilemap)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return (NULL);
    player->clock = clock;
    player->last_time_update = clock_get_ms(clock);
    player->tilemap = tilemap;
    player->x = 1.5;
    player->y = 1.5;
    player->x_vel = 0;
    player->y_vel = 0;
    player->width = player->tilemap->tilesize * 0.7;
    player->height = player->tilemap->tilesize * 0.7;
    player->sprite = sfSprite_create();
    player->animation = animation_create(SPRITESHEET_PATH, TEXTURE_X,
        TEXTURE_Y, ANIM_COUNT);
    player->horizontal_move = 0;
    player->vertical_move = 0;
    if (!player->sprite && !player->animation)
        return (player_destroy(player));
    if (init_anim(player, player->animation))
        return (player_destroy(player));
    return (player);
}