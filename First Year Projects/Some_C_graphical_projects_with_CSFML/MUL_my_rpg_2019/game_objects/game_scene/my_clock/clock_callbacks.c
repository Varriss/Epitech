/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** clock_callbacks
*/

#include <stdlib.h>
#include "my_rpg.h"

void create_clock_text(my_clock_t *clock)
{
    char *display = NULL;
    int seconds_left = 0;

    seconds_left = TOTAL_TIME - clock_get_s(clock);
    display = my_strcat(my_strdup("Time left\t")
    , int_to_str(seconds_left / 60));
    display = my_strcat(display, my_strdup(" min "));
    display = my_strcat(display, int_to_str(seconds_left % 60));
    if (display && clock->text)
        sfText_setString(clock->text, display);
    free(display);
}

void update_my_clock(prog_stat_t *prog_stat, my_clock_t *clock, list_t *scene)
{
    list_t *player_c = find_object(scene, player_cursor_type);
    sfVector2f actual_pos = (sfVector2f){0, 20};

    if (prog_stat)
        clock->pos.x = actual_pos.x;
    clock->pos.y = actual_pos.y;
    if (player_c) {
        clock->pos.x = player_c->data->player_c->pos.x - 130;
        clock->pos.y = player_c->data->player_c->pos.y
        - (WINDOW_HEIGHT / 2) + actual_pos.y;
    }
    create_clock_text(clock);
    sfText_setPosition(clock->text, clock->pos);
}