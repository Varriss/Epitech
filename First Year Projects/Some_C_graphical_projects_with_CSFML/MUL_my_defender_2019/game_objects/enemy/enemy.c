/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** enemy
*/

#include <SFML/System.h>
#include <stdlib.h>
#include "my_defender.h"

static enemy_info_t enemy_info[ENEMY_TYPES] = {
    {
        80,
        10,
        "Ressources/enemies/enemy1.png",
        2.0f,
        {SPAWN_X, SPAWN_Y},
        {0.85, 0.85},
    },
    {
        100,
        15,
        "Ressources/enemies/enemy2.png",
        2.0f,
        {SPAWN_X, SPAWN_Y},
        {1, 1},
    },
    {
        50,
        10,
        "Ressources/enemies/enemy3.png",
        4.0f,
        {SPAWN_X, SPAWN_Y},
        {0.5, 0.5}
    }
};

static sfIntRect *fill_enemy_rect(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->height = TILE_HEIGHT;
    rect->width = TILE_WIDTH;
    rect->left = 0;
    rect->top = 0;
    return (rect);
}

static void fill_positions(enemy_t *enemy, sfVector2f spawn_pos)
{
    enemy->prev_pos.x = -1000;
    enemy->prev_pos.y = -1000;
    enemy->pos.x = spawn_pos.x;
    enemy->pos.y = spawn_pos.y;
    enemy->next_pos.x = 0;
    enemy->next_pos.y = 0;
}

void add_enemy(list_t *g_o_list, enemy_info_t enemy_info)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    list_data_t *enemy_elem = malloc(sizeof(list_data_t));
    sfVector2f origin = {TILE_WIDTH / 2, TILE_HEIGHT / 2};

    enemy->type = enemy_type;
    enemy->life = enemy_info.life_val;
    enemy->state = 1;
    enemy->bounty = enemy_info.bounty;
    enemy->speed = enemy_info.speed;
    enemy->texture = sfTexture_createFromFile(enemy_info.sprite_path, NULL);
    enemy->sprite = sfSprite_create();
    enemy->clock = sfClock_create();
    fill_positions(enemy, enemy_info.spawn_pos);
    enemy->rect = fill_enemy_rect();
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfTrue);
    sfSprite_setOrigin(enemy->sprite, origin);
    sfSprite_setScale(enemy->sprite, enemy_info.scale);
    enemy->update = &update_enemy;
    enemy->render = &render_enemy;
    enemy->destroy = &destroy_enemy;
    enemy_elem->enemy = enemy;
    add_to_queue(g_o_list, enemy_elem);
}

void add_enemies(prog_stat_t *prog_stat, button_t *button,
list_t *game_scene, sfEvent *eve)
{
    int *nb_enemies = find_object(game_scene,
    level_type)->data->level->l_info->enemies_to_spawn;

    for (int i = 0; i < ENEMY_TYPES; i++) {
        for (int j = 0; j < nb_enemies[i]; j++) {
            add_enemy(game_scene, enemy_info[i]);
            for (int k = 0; k < ENEMY_TYPES; k++)
                enemy_info[k].spawn_pos.x -= SPAWN_OFFSET;
        }
    }
    for (int k = 0; k < ENEMY_TYPES; k++)
        enemy_info[k].spawn_pos.x = SPAWN_X;
}