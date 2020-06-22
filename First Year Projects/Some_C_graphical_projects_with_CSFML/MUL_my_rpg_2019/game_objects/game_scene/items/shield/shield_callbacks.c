/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** shield_callbacks
*/

#include <stdlib.h>
#include "my_rpg.h"

void update_shield_lvl(shield_t *shield)
{
    static int last_shield_lvl = 0;

    if (shield->quest_completion >= shield->quest
    && shield->lvl < MAX_BLADE_LVL) {
        shield->lvl++;
        shield->quest_completion = 0;
        shield->quest = 5 + (shield->lvl * 3);
    }
    if (shield->lvl != last_shield_lvl) {
        last_shield_lvl = shield->lvl;
        sfSprite_setTexture(shield->sprite
        , shield->texture[shield->lvl], sfTrue);
    }
}

void update_shield(prog_stat_t *prog_stat, shield_t *potion,
list_t *scene)
{
    list_t *player_c = find_object(scene, player_cursor_type);
    sfVector2f actual_pos = {10 * (shield_type + 1) + 160, 810};

    if (player_c && prog_stat) {
        potion->pos.x = player_c->data->player_c->sprite_pos.x
        - (WINDOW_WIDTH / 2) + actual_pos.x;
        potion->pos.y = player_c->data->player_c->sprite_pos.y
        - (WINDOW_HEIGHT / 2) + actual_pos.y;
    } else {
        potion->pos.x = actual_pos.x;
        potion->pos.y = actual_pos.y;
    }
    sfSprite_setPosition(potion->sprite, potion->pos);
    update_shield_lvl(potion);
}

void render_shield(prog_stat_t *prog_stat, shield_t *potion,
list_t *scene)
{
    if (potion->display == sfTrue && prog_stat && scene) {
        sfRenderWindow_drawSprite(prog_stat->window, potion->sprite, NULL);
    }
}

void destroy_shield(prog_stat_t *prog_stat, shield_t *potion,
list_t *scene)
{
    if (prog_stat && scene)
        for (int i = 0; potion->texture[i] != NULL; i++)
            sfTexture_destroy(potion->texture[i]);
    free(potion->texture);
    sfSprite_destroy(potion->sprite);
    free(potion);
    potion = NULL;
}