/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** enemy_callbacks
*/

#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_defender.h"

static void animate_enemy(enemy_t *enemy)
{
    int seconds = sfClock_getElapsedTime(enemy->clock).microseconds * 1000000;

    if (seconds > 1) {
        if (enemy->rect->left < (TILE_WIDTH * 2))
            enemy->rect->left += TILE_WIDTH;
        else
            enemy->rect->left = 0;
        sfClock_restart(enemy->clock);
    }
    sfSprite_setTextureRect(enemy->sprite, *(enemy->rect));
}

void update_enemy(prog_stat_t *prog_stat, struct enemy *enemy, \
    list_t *game_scene)
{
    sfVector2f scale = {enemy->life / 100.0f, enemy->life / 100.0f};
    int state = check_enemy_state(enemy, game_scene, prog_stat);


    if (state == 1) {
        sfSprite_setScale(enemy->sprite, scale);
        move_enemy(enemy, find_object(game_scene, \
        tile_map_type)->data->tile_map->map);
        animate_enemy(enemy);
    }
}

void render_enemy(prog_stat_t *prog_stat, struct enemy *enemy)
{
    sfRenderWindow_drawSprite(prog_stat->window, enemy->sprite, NULL);
}

void destroy_enemy(prog_stat_t *prog_stat, struct enemy *enemy)
{
    sfTexture_destroy(enemy->texture);
    sfSprite_destroy(enemy->sprite);
    sfClock_destroy(enemy->clock);
    free(enemy->rect);
    free(enemy);
    enemy = NULL;
}