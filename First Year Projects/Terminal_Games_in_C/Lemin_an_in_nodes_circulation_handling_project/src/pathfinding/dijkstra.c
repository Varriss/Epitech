/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** dijkstra
*/

#include "lemin.h"

static void update_node(node_t *prev_node, node_t *node, list_t *to_test)
{
    if (node->was_visited == 0 || (node->g_cost > (prev_node->g_cost + 1))) {
        node->g_cost = prev_node->g_cost + 1;
        node->prev = prev_node;
        add_node_to_list(to_test, node);
    }
}

static void update_adjacent_nodes(node_t *current, list_t *to_test)
{
    list_t *cursor = NULL;

    if (current->linked_nodes) {
        for (cursor = current->linked_nodes->next;
        cursor != current->linked_nodes; cursor = cursor->next) {
            update_node(current, cursor->data->node, to_test);
        }
    }
    remove_from_list(to_test, current);
}

void solution(node_t *start, node_t *end)
{
    node_t *cursor = end;

    if (end == start)
        start->best_path = NULL;
    else {
        while (cursor->prev != start)
            cursor = cursor->prev;
        start->best_path = cursor;
    }
}

int pathfinding(list_t *to_test, list_t *nodes)
{
    node_t *start = to_test->next->data->node;
    node_t *cursor = find_smallest_node(to_test);
    node_t *goal = find_node(nodes, 'E');

    for (; (cursor && goal) && cursor != goal ;
    cursor = find_smallest_node(to_test)) {
        cursor->was_visited = 1;
        update_adjacent_nodes(cursor, to_test);
    }
    if (cursor == goal) {
        solution(start, cursor);
        return (SUCCESS_CODE);
    }
    return (FAILURE_CODE);
}