/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_destroy
*/

#include "my_rpg.h"

void enemy_destroy(prog_stat_t *prog_stat, enemy_t *enemy)
{
    sfClock_destroy(enemy->clock);
    sfTexture_destroy(enemy->life_bar->textu);
    sfSprite_destroy(enemy->life_bar->sprite);
    sfTexture_destroy(enemy->textu);
    sfSprite_destroy(enemy->sprite);
    free(enemy->life_bar);
    if (prog_stat || !prog_stat)
        free(enemy);
}

void player_destroy(prog_stat_t *prog_stat, player_t *player, list_t *scene)
{
    sfClock_destroy(player->clock);
    sfTexture_destroy(player->life_bar->textu);
    sfSprite_destroy(player->life_bar->sprite);
    sfTexture_destroy(player->textu);
    sfSprite_destroy(player->sprite);
    sfView_destroy(player->view);
    free(player->life_bar);
    if (prog_stat || !prog_stat || scene)
        free(player);
}

void button_destroy(prog_stat_t *prog_stat, button_t *button)
{
    sfTexture_destroy(button->textu);
    sfSprite_destroy(button->sprite);
    button->destroy = NULL;
    button->sprite = NULL;
    button->textu = NULL;
    if (prog_stat || !prog_stat)
        free(button);
}

void backgr_destroy(prog_stat_t *prog_stat, backgr_t *backgr)
{
    sfTexture_destroy(backgr->textu);
    sfSprite_destroy(backgr->sprite);
    backgr->destroy = NULL;
    backgr->sprite = NULL;
    backgr->textu = NULL;
    if (prog_stat || !prog_stat)
        free(backgr);
}