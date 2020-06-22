/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** print_ants
*/

#include "lemin.h"

void print_ants(list_t *ant_list)
{
    list_t *cursor = ant_list->next;

    my_printf("\n\tAnts creation check :\n\t");
    for (; cursor != ant_list; cursor = cursor->next) {
        my_printf("P%d in %s ", cursor->data->ant->id,
        cursor->data->ant->room->descriptor);
    }
    my_printf("\n\n");
}