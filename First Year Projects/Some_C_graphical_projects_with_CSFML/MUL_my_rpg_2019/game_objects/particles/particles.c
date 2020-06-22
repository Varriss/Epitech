/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** particles
*/

#include "my_rpg.h"

list_t *find_particle_in_list(list_t *list, explosion_t *me)
{
    list_t *res = list->next;

    for (; (res->data != NULL) && (res->data->explode != me);
    res = res->next);
    if (res->data == NULL)
        return (NULL);
    return (res);
}

void destroy_explode(prog_stat_t *prog_stat, explosion_t *explode,
list_t *own_scene)
{
    list_t *particles = explode->particles;

    sfSprite_destroy(explode->sprite);
    sfTexture_destroy(explode->texture);
    for (list_t *cursor = particles->next; cursor != particles
    ; cursor = cursor->next)
        if (cursor->data != NULL && prog_stat && own_scene) {
            free(cursor->data->particle);
            cursor = rm_elem(cursor);
        }
    delete_list(particles);
    free(explode);
    explode = NULL;
}

void render_explode(prog_stat_t *prog_stat, explosion_t *explode,
list_t *own_scene)
{
    list_t *particles = NULL;

    if (own_scene)
        particles = explode->particles;
    for (list_t *cursor = particles->next; cursor != particles
    ; cursor = cursor->next) {
        sfSprite_setPosition(explode->sprite, cursor->data->particle->pos);
        sfRenderWindow_drawSprite(prog_stat->window, explode->sprite, NULL);
    }
}

void create_explosion(list_t *scene, sfVector2f origin)
{
    explosion_t *explode = malloc(sizeof(explosion_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    explode->destroy = &destroy_explode;
    explode->render = &render_explode;
    explode->update = &update_particle_pos;
    explode->clock = sfClock_create();
    explode->texture = sfTexture_createFromFile(PARTICLE, NULL);
    explode->particles = create_list();
    explode->sprite = sfSprite_create();
    explode->life_time = 0;
    sfSprite_setTexture(explode->sprite, explode->texture, sfTrue);
    explode->origin = origin;
    create_particles(explode);
    data->explode = explode;
    add_to_queue(scene, data);
}