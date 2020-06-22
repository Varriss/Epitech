/*
** EPITECH PROJECT, 2019
** CLOCK
** File description:
** Clock function
*/

#include <stdlib.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "my_rpg.h"

char *int_to_str(int nb)
{
    char *str = malloc(sizeof(char) * (12));
    int is_neg = (nb < 0);
    int i = 0;

    if (nb == 0) {
        str[i] = '0';
        i++;
    }
    for (; nb != 0; i++) {
        str[i] = (1 - is_neg * 2) * (nb % 10) + '0';
        nb /= 10;
    }
    if (is_neg) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    return (my_revstr(str));
}

void win_draw_time(prog_stat_t *prog_stat, my_clock_t *clock)
{
    sfRenderWindow_drawText(prog_stat->window, clock->text, NULL);
}

my_clock_t *clock_create(void)
{
    my_clock_t *clock = malloc(sizeof(my_clock_t));

    if (!clock)
        return (NULL);
    clock->clock = sfClock_create();
    clock->is_paused = 0;
    clock->text = init_text(clock->pos, 30);
    clock->paused_at = -1;
    clock->to_add = 0;
    clock->speed_at = -1;
    clock->pos = (sfVector2f){WINDOW_WIDTH / 2, 10};
    clock->speed = 1.0;
    clock->pause_speed = 1.0;
    clock->destroy = &clock_destroy;
    clock->render = &win_draw_time;
    clock->update = &update_my_clock;
    clock->type = clock_type;
    return (clock);
}

my_clock_t *get_my_clock(list_t *scene)
{
    for (list_t *cursor = scene->next; cursor != scene
    ; cursor = cursor->next) {
        if (cursor->data->clock->type == clock_type)
            return (cursor->data->clock);
    }
    return (NULL);
}

void clock_destroy(prog_stat_t *prog_stat, my_clock_t *clock)
{
    if (clock && prog_stat) {
        if (clock->clock)
            sfClock_destroy(clock->clock);
        free(clock);
    }
}