/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** list_manipulation
*/

#include <stdlib.h>
#include "lemin.h"

void add_node_to_list(list_t *list, node_t *node)
{
    list_data_t *node_elem = malloc(sizeof(list_data_t));

    node_elem->node = node;
    add_to_front(list, node_elem);
}

void remove_from_list(list_t *list, node_t *node)
{
    list_t *cursor = list->next;
    list_t *next = NULL;

    for (; cursor != list; cursor = next) {
        next = cursor->next;
        if (cursor->data->node == node)
            rm_elem(cursor);
    }
}