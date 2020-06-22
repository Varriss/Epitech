/*
** EPITECH PROJECT, 2020
** PLAYER_UPDATE
** File description:
** Player_update function
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

void collide_x(player_t *player, sfFloatRect tile_col)
{
    if (player->x_vel > 0) {
        player->x = (tile_col.left - player->width / 2) / (float)player->tilemap->tilesize;
    }
    else {
        player->x = (tile_col.left + tile_col.width + player->width / 2) / (float)player->tilemap->tilesize;
    }
}

void update_x(player_t *player)
{
    sfInt64 tmp_elapse = clock_get_ms(player->clock) - player->last_time_update;
    sfFloatRect tile_col;
    float d_acc;
    sfFloatRect bounds = {0, player->y * player->tilemap->tilesize - player->height / 2, player->width, player->height};

    while (tmp_elapse >= 0) {
        d_acc = VEL_ACC * (tmp_elapse % 100) / 1000.0;
        player->x_vel += d_acc * player->horizontal_move;
        if (player->horizontal_move == 0)
            player->x_vel *= 0.3;
        if (player->x_vel > VEL_MAX && player->x_vel > 0)
            player->x_vel = VEL_MAX;
        if (player->x_vel < -VEL_MAX && player->x_vel < 0)
            player->x_vel = -VEL_MAX;
        player->x += player->x_vel * (tmp_elapse % 100) / 1000.0;
        bounds.left = player->x * player->tilemap->tilesize - player->width / 2;
        if (tilemap_map_collision(player->tilemap, MAP_LAYER, bounds, &tile_col))
            collide_x(player, tile_col);
        tmp_elapse -= 100;
    }
}

void collide_y(player_t *player, sfFloatRect tile_col)
{
    if (player->y_vel > 0) {
        player->y = (tile_col.top - player->height / 2) / (float)player->tilemap->tilesize;
    }
    else {
        player->y = (tile_col.top + tile_col.height + player->height / 2) / (float)player->tilemap->tilesize;
    }
}

void update_y(player_t *player)
{
    sfInt64 tmp_elapse = clock_get_ms(player->clock) - player->last_time_update;
    sfFloatRect tile_col;
    float d_acc;
    sfFloatRect bounds = {player->x * player->tilemap->tilesize - player->width / 2, 0, player->width, player->height};

    while (tmp_elapse >= 0) {
        d_acc = VEL_ACC * (tmp_elapse % 100) / 1000.0;
        player->y_vel += d_acc * player->vertical_move;
        if (player->vertical_move == 0)
            player->y_vel *= 0.3;
        if (player->y_vel > VEL_MAX && player->y_vel > 0)
            player->y_vel = VEL_MAX;
        if (player->y_vel < -VEL_MAX && player->y_vel < 0)
            player->y_vel = -VEL_MAX;
        player->y += player->y_vel * (tmp_elapse % 100) / 1000.0;
        bounds.top = player->y * player->tilemap->tilesize - player->height / 2;
        if (tilemap_map_collision(player->tilemap, MAP_LAYER, bounds, &tile_col))
            collide_y(player, tile_col);
        tmp_elapse -= 100;
    }
}

void player_update(player_t *player)
{
    amination_update(player->animation, player->clock);
    update_x(player);
    update_y(player);
    player->last_time_update = clock_get_ms(player->clock);
}