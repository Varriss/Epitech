/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** real_tower_init
*/

#include <stdlib.h>
#include <math.h>
#include "my_defender.h"

// as, damage, range
static float tower_stats[4][3] = 
{
    {1, 10, 250},
    {0.5, 50, 400},
    {3, 15, 200},
    {0.2, 100, 300}
};

static void render_turret(prog_stat_t *prog_stat, tower_t *tower)
{
    sfRenderWindow_drawSprite(prog_stat->window, tower->sprite, NULL);
}

static sfTexture *get_tower_textur(int tower)
{
    if (tower == 2)
        return (sfTexture_createFromFile(TURRET_ONE, NULL));
    if (tower == 3)
        return (sfTexture_createFromFile(TURRET_TWO, NULL));
    if (tower == 4)
        return (sfTexture_createFromFile(TURRET_THREE, NULL));
    else
        return (sfTexture_createFromFile(TURRET_FOUR, NULL));
}

void hit_enemy(list_t *cursor, tower_t *tow, list_t *scene)
{
    player_info_t *player = find_object(scene, level_type)->data->level->p_info;

    cursor->data->enemy->life -= tow->damage;
    player->money += cursor->data->enemy->bounty;
    player->score += cursor->data->enemy->bounty;
}

void update_turret(prog_stat_t *prog_stat, struct tower *tow,
list_t *game_scene)
{
    list_t *cursor = game_scene;
    sfVector2i pos = {0, 0};
    float distance = 0;
    int time = sfClock_getElapsedTime(tow->clock).microseconds / 1000000;

    if (time >= tow->ats) {
        do {
            cursor = find_object(cursor, enemy_type);
            if (cursor != NULL) {
                pos.x = cursor->data->enemy->pos.x;
                pos.y = cursor->data->enemy->pos.y;
                distance = sqrt(pow((pos.x - (tow->pos.x + 50)), 2)
                + pow((pos.y - (tow->pos.y + 50)), 2));
            }
        } while ((cursor != NULL) && (distance > tow->range));
        if (cursor != NULL) {
            hit_enemy(cursor, tow, game_scene);
            sfClock_restart(tow->clock);
        }
    }
}

list_data_t *init_tower(int tower, int x, int y)
{
    tower_t *tow = malloc(sizeof(tower_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    data->tower = tow;
    tow->type = tower_type;
    tow->texture = get_tower_textur(tower);
    tow->ats = tower_stats[tower - 2][0];
    tow->damage = tower_stats[tower - 2][1];
    tow->range = tower_stats[tower - 2][2];
    tow->destroy = NULL;
    tow->render = &render_turret;
    tow->update = &update_turret;
    tow->pos.x = x;
    tow->pos.y = y;
    tow->sprite = sfSprite_create();
    sfSprite_setTexture(tow->sprite, tow->texture, sfTrue);
    sfSprite_setPosition(tow->sprite, tow->pos);
    tow->clock = sfClock_create();
    return (data);
}