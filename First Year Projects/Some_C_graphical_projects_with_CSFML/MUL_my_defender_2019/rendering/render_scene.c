/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** render_scene
*/

#include "my_defender.h"

void render_scene(prog_stat_t *prog_stat, list_t *scene)
{
    list_t *cursor = scene->next;

    sfRenderWindow_clear(prog_stat->window, sfBlack);
    for (; cursor != scene; cursor = cursor->next) {
        if (cursor->data->enemy->render != NULL)
            cursor->data->enemy->render(prog_stat, cursor->data->enemy);
    }
    sfRenderWindow_display(prog_stat->window);
}