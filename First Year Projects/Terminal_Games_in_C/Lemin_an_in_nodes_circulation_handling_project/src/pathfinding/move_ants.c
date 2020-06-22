/*
** EPITECH PROJECT, 2020
** move_ants
** File description:
** move_ants
*/

#include "lemin.h"

static node_t *choose_other_room(ant_t *ant, int disp)
{
    list_t *node_list = ant->room->linked_nodes;

    for (list_t *cursor = node_list->next; cursor != node_list
    ; cursor = cursor->next) {
        if ((cursor->data->node->ants == 0)
        || (cursor->data->node->special_id == 'E')) {
            ant->room->ants--;
            cursor->data->node->ants++;
            my_printf("%s", (disp ? " " : ""));
            my_printf("P%d-%s", ant->id, cursor->data->node->descriptor);
            return (cursor->data->node);
        }
    }
    return (ant->room);
}

static list_t *move_ant(ant_t *ant, list_t *cursor, int disp)
{
    list_t *cursor_prev = cursor->prev;

    if (ant->room->best_path && (((ant->room->best_path->ants == 0)
    || (ant->room->best_path->special_id == 'S'))
    || (ant->room->best_path->special_id == 'E'))) {
        my_printf("%sP%d-%s", (disp ? " " : ""), ant->id
        , ant->room->best_path->descriptor);
        ant->room->ants--;
        ant->room->best_path->ants++;
        ant->room = ant->room->best_path;
    } else
        ant->room = choose_other_room(ant, disp);
    if (ant->room->special_id == 'E') {
        rm_elem(cursor);
        my_printf("%s", (cursor->next->data != NULL ? " " : ""));
        return (cursor_prev);
    }
    return (cursor);
}

void move_ants(list_t *ant_list)
{
    list_t *cursor = NULL;

    my_putstr("#moves\n");
    while (ant_list->next != ant_list) {
        for (cursor = ant_list->next; cursor != ant_list;
        cursor = cursor->next)
            cursor = move_ant(cursor->data->ant, cursor
            , (cursor->prev != ant_list ? 1 : 0));
        my_putchar('\n');
    }
}