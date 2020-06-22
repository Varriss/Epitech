/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** heal_effect
*/

#include "my_rpg.h"

void update_heal_effect(prog_stat_t *prog_stat, explosion_t *explode,
list_t *own_scene)
{
    sfInt64 time = sfClock_getElapsedTime(explode->clock).microseconds;
    float seconds = time / 1000000.0;
    list_t *particles = explode->particles;
    particle_t *particle = NULL;

    if (seconds > 0.05) {
        for (list_t *cursor = particles->next; cursor != particles
        ; cursor = cursor->next)
            if (cursor->data != NULL) {
                particle = cursor->data->particle;
                particle->pos.x += (particle->traj.x / 10);
                particle->pos.y += (particle->traj.y / 10);
                particle->traj.y /= 1.1;
                particle->traj.x /= 1.3;
            }
        if (explode->life_time > 10) {
            destroy_explode(prog_stat, explode, own_scene);
            rm_elem(find_particle_in_list(own_scene, explode));
        } else
            explode->life_time++;
        if (explode)
            sfClock_restart(explode->clock);
    }
}

void create_heal_effect(list_t *scene, sfVector2f origin)
{
    explosion_t *explode = malloc(sizeof(explosion_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    explode->destroy = &destroy_explode;
    explode->render = &render_explode;
    explode->update = &update_heal_effect;
    explode->clock = sfClock_create();
    explode->texture = sfTexture_createFromFile(HEAL_PARTICLE, NULL);
    explode->particles = create_list();
    explode->sprite = sfSprite_create();
    sfSprite_setTexture(explode->sprite, explode->texture, sfTrue);
    explode->origin = origin;
    sfSprite_setColor(explode->sprite, (sfColor){255, 255, 255, 50});
    create_particles(explode);
    data->explode = explode;
    add_to_queue(scene, data);
}