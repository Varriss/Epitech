/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** particles
*/

#include "my_rpg.h"

void define_trajectory(particle_t *particle)
{
    int x = rand() % 3 - 1;
    int y = rand() % 3 - 1;

    particle->traj.x = (rand() % 100) * (x > 0 ? 1 : -1);
    particle->traj.y = (rand() % 100) * (y > 0 ? 1 : -1);
}

void create_particles(explosion_t *explode)
{
    list_t *particles = explode->particles;
    list_data_t *data = NULL;
    particle_t *particle = NULL;

    for (int i = rand() % MAX_PARTICLES + 100; i > 0; i--) {
        data = malloc(sizeof(list_data_t));
        particle = malloc(sizeof(particle_t));
        data->particle = particle;
        particle->pos = explode->origin;
        define_trajectory(particle);
        add_to_front(particles, data);
    }
}