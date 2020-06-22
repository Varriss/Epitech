/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** boss_attack
*/

#include "my_rpg.h"

void boss_anim(enemy_t *enemy, float seconds)
{
    if (seconds > 0.10)
        enemy->pos.x -= 100;
    if (seconds > 0.15) {
        if (enemy->rect.left < (1300 - 130))
            enemy->rect.left += 130;
        else {
            enemy->animated = 0;
            enemy->rect.left = 0;
            enemy->pos.x = 1000;
        }
        sfClock_restart(enemy->clock);
    }
}