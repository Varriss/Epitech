/*
** EPITECH PROJECT, 2019
** CLOCK
** File description:
** Clock function
*/

#include <stdlib.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "my_clock.h"

my_clock_t *clock_create(void)
{
    my_clock_t *clock = malloc(sizeof(my_clock_t));

    if (!clock)
        return (NULL);
    clock->clock = sfClock_create();
    if (!clock->clock)
        return (clock_destroy(clock));
    clock->is_paused = 0;
    clock->paused_at = -1;
    clock->to_add = 0;
    clock->speed_at = -1;
    clock->speed = 1.0;
    clock->pause_speed = 1.0;
    return (clock);
}

void *clock_destroy(my_clock_t *clock)
{
    if (!clock)
        return (NULL);
    if (clock->clock)
        sfClock_destroy(clock->clock);
    free(clock);
    return (NULL);
}