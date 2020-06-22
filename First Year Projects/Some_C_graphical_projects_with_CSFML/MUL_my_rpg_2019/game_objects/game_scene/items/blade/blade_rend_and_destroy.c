/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** blade_texture_handling
*/

#include "my_rpg.h"

void render_blade(prog_stat_t *prog_stat, blade_t *potion,
list_t *scene)
{
    if (potion->display == sfTrue && prog_stat && scene) {
        sfRenderWindow_drawSprite(prog_stat->window, potion->sprite, NULL);
    }
}

void destroy_blade(prog_stat_t *prog_stat, blade_t *potion,
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