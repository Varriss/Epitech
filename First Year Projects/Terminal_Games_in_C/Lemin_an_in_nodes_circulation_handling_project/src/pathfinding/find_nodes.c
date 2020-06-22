/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** find_nodes
*/

#include "lemin.h"

node_t *find_smallest_node(list_t *node_list)
{
    list_t *cursor = node_list->next;
    list_t *cursor_min = cursor;

    if (node_list->next == node_list)
        return (NULL);
    for (; cursor != node_list; cursor = cursor->next) {
        if (cursor->data->node->g_cost < cursor_min->data->node->g_cost
        || ((cursor_min->data->node->g_cost == -1)
        && (cursor->data->node->g_cost > -1)))
            cursor_min = cursor;
    }
    return (cursor_min->data->node);
}

node_t *find_node(list_t *node_list, char special_id)
{
    list_t *cursor = node_list->next;

    for (; cursor != node_list; cursor = cursor->next) {
        if (cursor->data->node->special_id == special_id)
            return (cursor->data->node);
    }
    my_write(2, "No node found.\n", 2);
    return (NULL);
}