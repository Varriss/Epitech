/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** create_ants
*/

#include <stdlib.h>
#include "lemin.h"


static list_data_t *create_ant(int id, node_t *room)
{
    list_data_t *ant_elem = malloc(sizeof(list_data_t));

    ant_elem->ant = malloc(sizeof(ant_t));
    ant_elem->ant->id = id + 1;
    ant_elem->ant->room = room;
    return (ant_elem);
}

list_t *create_ants(list_t *node_list)
{
    list_t *cursor = NULL;
    list_t *ants = create_list();
    static int ant_id = 0;

    if (!node_list)
        return (NULL);
    for (cursor = node_list->next; cursor != node_list;
    cursor = cursor->next) {
        for (int i = 0; i < cursor->data->node->ants; i++) {
            add_to_queue(ants,
            create_ant(ant_id++, cursor->data->node));
        }
    }
    return (ants);
}

void destroy_ants(list_t *ant_list)
{
    list_t *cursor = ant_list->next;

    for (; cursor != ant_list; cursor = cursor->next)
        free(cursor->data->ant);
    delete_list(ant_list);
}