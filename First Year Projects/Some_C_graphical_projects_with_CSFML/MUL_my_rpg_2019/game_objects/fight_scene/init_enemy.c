/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_enemy
*/

#include <stdlib.h>
#include "my_rpg.h"

list_t *find_me_in_list(list_t *list, enemy_t *me)
{
    list_t *res = list->next;

    for (; (res->data != NULL) && (res->data->enemy != me);
    res = res->next);
    if (res->data == NULL)
        return (NULL);
    return (res);
}

void update_enemy(prog_stat_t *prog_stat, enemy_t *enemy, list_t *scene)
{
    list_t *to_kill = find_me_in_list(scene, enemy);
    sfInt64 time = sfClock_getElapsedTime(enemy->clock).microseconds;
    float seconds = time / 1000000.0;

    if (enemy->animated == 0 && enemy->turn == 1 && seconds > 1)
        engage_player(prog_stat, scene, enemy);
    if (enemy->animated >= 1)
        attack_anim(enemy, seconds);
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
    enemy->update = &update_enemy;
    enemy->destroy = &enemy_destroy;
    enemy->render = &render_enemy;
    enemy->turn = 0;
    enemy->animated = 0;
}

void set_scale_and_color(enemy_t *enemy, int count)
{
    sfSprite_setTexture(enemy->sprite, enemy->textu, sfTrue);
    sfSprite_setScale(enemy->sprite, place_enemy(count, 2));
    sfSprite_setPosition(enemy->sprite, enemy->pos);
    sfSprite_setColor(enemy->sprite, (sfColor){(enemy->life * 40)
    , 255 - (enemy->life * 32), 255 - (enemy->life * 32), 255});
}

void init_enemy(list_t *fight_scene)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    list_data_t *data = malloc(sizeof(list_data_t));
    int count = count_enemy(fight_scene);
    sfVector2f pos = place_enemy(count, 1);

    init(enemy);
    enemy->rect = (sfIntRect){0, 0, 237, 180};
    enemy->life = rand() % 5 + 1;
    enemy->clock = sfClock_create();
    enemy->pos = pos;
    enemy->textu =
    sfTexture_createFromFile("ressources/fight/dragonfire.png", NULL);
    enemy->type = enemy_type;
    enemy->sprite = sfSprite_create();
    set_scale_and_color(enemy, count);
    data->enemy = enemy;
    init_barlife_enemy(enemy, count);
    add_to_queue(fight_scene, data);
}