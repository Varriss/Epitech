/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** enemy_attack
*/

#include "my_rpg.h"

void attack_anim(enemy_t *enemy, float seconds)
{
    if (seconds > 0.15) {
        if (enemy->rect.left < (948 - 237))
            enemy->rect.left += 237;
        else {
            enemy->animated = 0;
            enemy->rect.left = 0;
        }
        sfClock_restart(enemy->clock);
    }
}

void engage_player(prog_stat_t *prog_stat, list_t *scene, enemy_t *me)
{
    list_t *player = find_object(scene, player_type);
    inventory_t *inventory = NULL;

    if (player) {
        inventory = player->data->player->inventory;
        me->animated = 1;
        if (player->data->player->defense == 0) {
            player->data->player->inventory->life -=
            (prog_stat->scene_index == boss_scene ?
            BOSS_DAMAGE : ENEMY_DAMAGE);
        } else {
            me->life -= (inventory->items[shield_type]->shield->lvl == 0 ?
            1 : 2 * inventory->items[shield_type]->shield->lvl);
            if (me->life <= 0)
                me->life = 1;
        }
        me->turn = 2;
        play_sound(dragon_roar, prog_stat);
        play_sound(male_pain, prog_stat);
    }
}