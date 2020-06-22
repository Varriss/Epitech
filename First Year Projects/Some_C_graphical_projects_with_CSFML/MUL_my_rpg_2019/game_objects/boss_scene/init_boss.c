/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_enemy
*/

#include <stdlib.h>
#include "my_rpg.h"

void set_scale_and_pos(enemy_t *enemy, int count)
{
    sfSprite_setTexture(enemy->sprite, enemy->textu, sfTrue);
    sfSprite_setScale(enemy->sprite, place_enemy(count, 2));
    sfSprite_setPosition(enemy->sprite, enemy->pos);
}

void update_boss(prog_stat_t *prog_stat, enemy_t *enemy, list_t *scene)
{
    list_t *to_kill = find_me_in_list(scene, enemy);
    sfInt64 time = sfClock_getElapsedTime(enemy->clock).microseconds;
    float seconds = time / 1000000.0;

    if (enemy->animated == 0 && enemy->turn == 1 && seconds > 1)
        engage_player(prog_stat, scene, enemy);
    if (enemy->animated >= 1)
        boss_anim(enemy, seconds);
    if (enemy->turn == 2 && enemy->animated == 0)
        set_next_turn(to_kill);
    if (enemy && scene && prog_stat && enemy->life > 0)
        enemy->life_bar->rect.top = (enemy->life - 1) *
        (enemy->life_bar->rect.height + 7);
    else {
        create_explosion(scene, enemy->pos);
        enemy_destroy(prog_stat, enemy);
        rm_elem(to_kill);
    }
}

static void init(enemy_t *enemy)
{
    enemy->update = &update_boss;
    enemy->destroy = &enemy_destroy;
    enemy->render = &render_enemy;
    enemy->turn = 0;
    enemy->animated = 0;
}

void init_boss(list_t *boss_scene)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    list_data_t *data = malloc(sizeof(list_data_t));
    sfVector2f pos = {1000, 500};

    init(enemy);
    enemy->rect = (sfIntRect){0, 0, 130, 100};
    enemy->life = 6;
    enemy->clock = sfClock_create();
    enemy->pos = pos;
    enemy->textu =
    sfTexture_createFromFile(BOSS_SPRITE, NULL);
    enemy->type = enemy_type;
    enemy->sprite = sfSprite_create();
    set_scale_and_pos(enemy, 1);
    data->enemy = enemy;
    init_barlife_enemy(enemy, 1);
    add_to_queue(boss_scene, data);
}