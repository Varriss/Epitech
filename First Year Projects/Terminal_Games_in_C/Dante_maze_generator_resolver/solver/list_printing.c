/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** list_printing
*/

#include "solver.h"

void print_list_nodes(list_t *nodes)
{

    for (list_t *cursor = nodes->next; cursor != nodes;
    cursor = cursor->next) {
        my_printf("Node at [%d, %d] g_cost = %d h_cost = %d f_cost = %d\n",
        cursor->data->node->pos.x, cursor->data->node->pos.y,
        cursor->data->node->g_cost, cursor->data->node->h_cost,
        cursor->data->node->f_cost);
    }
    my_putchar('\n');
}