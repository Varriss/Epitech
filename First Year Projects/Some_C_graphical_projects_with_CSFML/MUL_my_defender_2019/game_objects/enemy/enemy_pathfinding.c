/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** enemy_pathfinding
*/

#include <stdlib.h>
#include "my_defender.h"

static sfVector2i *get_map_equivalent(sfVector2f pos)
{
    sfVector2i *res = malloc(sizeof(sfVector2i));

    if ((pos.x < 0 || pos.x > MAP_WIDTH * TILE_WIDTH) ||
    (pos.y < 0 || pos.y > MAP_HEIGHT * TILE_HEIGHT)) {
        res->x = -1;
        res->y = -1;
    } else {
        res->x = pos.x / TILE_WIDTH;
        res->y = pos.y / TILE_HEIGHT;
    }
    return (res);
}

static void get_next_pos_y(enemy_t *enemy, sfVector2i *current, char **map)
{
    if (my_findchar(map[current->y + 1][current->x], "1E") != -1
    && ((ENEMY_SIZE / 2) + (current->y + 1) * TILE_HEIGHT)
    != enemy->prev_pos.y) {
        enemy->next_pos.x = enemy->pos.x;
        enemy->next_pos.y = enemy->pos.y + TILE_HEIGHT;
        sfSprite_setRotation(enemy->sprite, 90);
    }
    else if (current->y > 0 && my_findchar(map[current->y - 1][current->x],
    "1E") != -1 && ((ENEMY_SIZE / 2) + (current->y - 1) * TILE_HEIGHT)
    != enemy->prev_pos.y) {
        enemy->next_pos.x = enemy->pos.x;
        enemy->next_pos.y = enemy->pos.y - TILE_HEIGHT;
        sfSprite_setRotation(enemy->sprite, -90);
    }
}

static void get_next_pos(enemy_t *enemy, char **map)
{
    sfVector2i *current = NULL;

    current = get_map_equivalent(enemy->pos);
    if (my_findchar(map[current->y][current->x + 1], "1E") != -1
    && ((ENEMY_SIZE / 2) + (current->x + 1) * TILE_WIDTH)
    != enemy->prev_pos.x) {
        enemy->next_pos.x = enemy->pos.x + TILE_WIDTH;
        enemy->next_pos.y = enemy->pos.y;
        sfSprite_setRotation(enemy->sprite, 0);
    }
    else if (current->x > 0 && my_findchar(map[current->y][current->x - 1],
    "1E") != -1 && ((ENEMY_SIZE / 2) + (current->x - 1) * TILE_WIDTH)
    != enemy->prev_pos.x) {
        enemy->next_pos.x = enemy->pos.x - TILE_WIDTH;
        enemy->next_pos.y = enemy->pos.y;
        sfSprite_setRotation(enemy->sprite, 180);
    }
    get_next_pos_y(enemy, current, map);
    free(current);
}

static void enemy_pathfinding(enemy_t *enemy, char **map)
{
    sfVector2i *cursor = NULL;

    if (enemy->prev_pos.x < 0 || enemy->prev_pos.y < 0) {
        enemy->next_pos.x = FIRST_TILE_X;
        enemy->next_pos.y = FIRST_TILE_Y;
    }
    if (enemy->pos.x == enemy->next_pos.x
    && enemy->pos.y == enemy->next_pos.y) {
            get_next_pos(enemy, map);
            enemy->prev_pos.x = enemy->pos.x;
            enemy->prev_pos.y = enemy->pos.y;
    }
}

void move_enemy(enemy_t *enemy, char **map)
{
    enemy_pathfinding(enemy, map);
    if (enemy->pos.x == enemy->next_pos.x
    && enemy->pos.y != enemy->next_pos.y) {
        if (enemy->pos.y < enemy->next_pos.y)
            enemy->pos.y += enemy->speed;
        else
            enemy->pos.y -= enemy->speed;
    } else if (enemy->pos.y == enemy->next_pos.y
    && enemy->pos.x != enemy->next_pos.x) {
        if (enemy->pos.x < enemy->next_pos.x)
            enemy->pos.x += enemy->speed;
        else
            enemy->pos.x -= enemy->speed;
    }
    sfSprite_setPosition(enemy->sprite, enemy->pos);
}