/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_for_explode_bounce
*/

#include "my_rpg.h"

void update_particle_pos_and_bounce(list_t *cursor)
{
    particle_t *particle = NULL;

    if (cursor->data != NULL) {
        particle = cursor->data->particle;
        particle->pos.x += particle->traj.x;
        particle->pos.y += particle->traj.y;
        if (particle->pos.y > 700)
            particle->traj.y *= -1;
    }
}

void update_particle_pos(prog_stat_t *prog_stat, explosion_t *explode,
list_t *own_scene)
{
    sfInt64 time = sfClock_getElapsedTime(explode->clock).microseconds;
    float seconds = time / 1000000.0;
    list_t *particles = explode->particles;

    if (seconds > 0.05) {
        for (list_t *cursor = particles->next; cursor != particles
        ; cursor = cursor->next)
            update_particle_pos_and_bounce(cursor);
        if (explode->life_time > 4) {
            destroy_explode(prog_stat, explode, own_scene);
            rm_elem(find_particle_in_list(own_scene, explode));
        } else
            explode->life_time++;
        sfClock_restart(explode->clock);
    }
}