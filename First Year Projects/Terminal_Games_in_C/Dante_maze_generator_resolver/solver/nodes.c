/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** nodes
*/

#include <stdlib.h>
#include "solver.h"

static node_t *create_node(int x, int y, char **maze)
{
    node_t *node = malloc(sizeof(node_t));
    vector_i_t pos_goal = {my_strlen(maze[0]) - 1, my_str_arr_len(maze) - 1};

    if (is_in_bounds(x, y, maze) && maze[y][x] == OBSTACLE_CHAR)
        node->is_obstacle = 1;
    else
        node->is_obstacle = 0;
    node->was_visited = 0;
    node->pos.x = x;
    node->pos.y = y;
    node->g_cost = -1;
    node->h_cost = get_distance(node->pos, pos_goal);
    node->f_cost = -1;
    node->prev = NULL;
    return (node);
}

void free_node_arr(node_t ***node_arr)
{
    for (int i = 0; node_arr && node_arr[i]; i++) {
        for (int j = 0; node_arr[i][j]; j++)
            free(node_arr[i][j]);
        free(node_arr[i]);
    }
    free(node_arr);
}

node_t ***create_node_arr(char **maze)
{
    int res_len = my_str_arr_len(maze);

    node_t ***node_arr = malloc(sizeof(node_t **) * (res_len + 1));

    node_arr[res_len] = NULL;
    for (int i = 0; i < res_len; i++) {
        node_arr[i] = malloc(sizeof(node_t *) * (my_strlen(maze[0]) + 1));
        node_arr[i][my_strlen(maze[0])] = NULL;
        for (int j = 0; j < my_strlen(maze[0]); j++)
            node_arr[i][j] = create_node(j, i, maze);
    }
    return (node_arr);
}

void add_node_to_list(list_t *list, node_t *node)
{
    list_data_t *node_elem = malloc(sizeof(list_data_t));

    node_elem->node = node;
    add_to_front(list, node_elem);
}