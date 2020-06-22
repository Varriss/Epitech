/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019_2
** File description:
** my_defender
*/

#include <stdlib.h>
#include "my_defender.h"

static prog_stat_t *init_program_status(void)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BYTES};
    prog_stat_t *prog = malloc(sizeof(prog_stat_t));

    prog->window = sfRenderWindow_create(mode, WINDOW_TITLE, sfClose, NULL);
    prog->running = 1;
    prog->scene_index = 0;
    prog->last_window = sfTexture_create(WINDOW_WIDTH, WINDOW_HEIGHT);
    sfRenderWindow_setFramerateLimit(prog->window, FRAMERATE);
    return (prog);
}

static void update_scene(prog_stat_t *prog_stat, list_t *scene)
{
    list_t *cursor = scene->next;
    list_t *cursor_cop = scene;

    for (; cursor != scene; cursor = cursor->next,
    cursor_cop = cursor_cop->next) {
        if ((cursor->data != NULL)
        && (cursor->data->enemy->update != NULL)) {
            cursor->data->enemy->update(prog_stat, cursor->data->enemy, scene);
            if (cursor != cursor_cop->next)
                cursor = cursor_cop->next;
        }
    }
}

static void cleaner(prog_stat_t *stat,
list_t **scene)
{
    for (int i = 0; i < NB_SCENES; i++)
        for (list_t *cursor = scene[i]->next;
        cursor != scene[i]; cursor = cursor->next) {
            if (cursor->data->enemy->destroy != NULL)
                cursor->data->enemy->destroy(stat, cursor->data->enemy);
        }
    for (int i = 0; i < NB_SCENES; i++)
        delete_list(scene[i]);
    sfRenderWindow_destroy(stat->window);
    free(stat);
}

int my_defender(void)
{
    list_t **scene = init_scenes();
    prog_stat_t *prog_stat = init_program_status();

    while (prog_stat->running && sfRenderWindow_isOpen(prog_stat->window)) {
        analyse_events(prog_stat, scene[prog_stat->scene_index]);
        update_scene(prog_stat, scene[prog_stat->scene_index]);
        render_scene(prog_stat, scene[prog_stat->scene_index]);
    }
    cleaner(prog_stat, scene);
    return (SUCCESS_CODE);
}