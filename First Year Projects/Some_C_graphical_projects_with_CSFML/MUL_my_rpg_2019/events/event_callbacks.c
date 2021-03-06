/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_callbacks
*/

#include "my_rpg.h"

static void clikked(sfEvent *event, prog_stat_t *prog_stat, list_t *cursor,
list_t *scene)
{
    button_t *button = cursor->data->button;
    int rect_x = button->pos.x;
    int rect_y = button->pos.y;
    int rect_sup_x = button->rect.width;
    int rect_sup_y = button->rect.height;
    int x = event->mouseButton.x;
    int y = event->mouseButton.y;

    if ((y < rect_y + rect_sup_y) && (y > rect_y))
        if ((x < rect_x + rect_sup_x) && (x > rect_x)) {
            play_sound(button_click, prog_stat);
            button->onclick(prog_stat, button, scene, event);
        }
}

void button_clicked(sfEvent *event, prog_stat_t *prog_stat, list_t *g_o_list)
{
    list_t *cursor = g_o_list->next;

    for (; cursor != g_o_list; cursor = cursor->next) {
        if (((cursor->data->button->type == button_type))
        && (cursor->data->button->onclick != NULL))
            clikked(event, prog_stat, cursor, g_o_list);
    }
}

void close_window(sfEvent *event, prog_stat_t *prog_stat, list_t *g_o_list)
{
    if ((event || !event) && (g_o_list || !g_o_list))
        sfRenderWindow_close(prog_stat->window);
}
