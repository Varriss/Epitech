/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** destroy_node_list
*/

#include "lemin.h"
#include <stdio.h>
#include <stdlib.h>

// delete_list(cursor->data->node->linked_nodes);
void destroy_node_list(list_t *node_list)
{
    list_t *cursor = node_list->next;

    while (cursor != node_list) {
        free (cursor->data->node->descriptor);
        free(cursor->data->node);
        cursor = cursor->next;
    }
    delete_list(node_list);
}