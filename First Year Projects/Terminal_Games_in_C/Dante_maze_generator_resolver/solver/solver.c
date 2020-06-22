/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** solver
*/

#include <stdlib.h>
#include "solver.h"

int solver(char **maze)
{
    node_t ***node_arr = NULL;
    list_t *to_test = create_list();

    if (!maze)
        return (my_write(FAILURE_CODE, "Error : Invalid maze.\n", 2));
    node_arr = create_node_arr(maze);

    node_arr[0][0]->g_cost = 0;
    node_arr[0][0]->f_cost = node_arr[0][0]->g_cost + node_arr[0][0]->h_cost;
    add_node_to_list(to_test, node_arr[0][0]);
    if (find_path(&maze, node_arr, to_test) != SUCCESS_CODE)
        my_putstr("no solution found\n");
    else
        my_str_arr_print(maze, '\n');
    free_my_str_arr(maze);
    free_node_arr(node_arr);
    delete_list(to_test);
    return (SUCCESS_CODE);
}

int get_distance(vector_i_t x1, vector_i_t x2)
{
    return ((x2.x - x1.x) + (x2.y - x1.y));
}

void trace_path(node_t *node, char ***maze)
{
    node_t *cursor = NULL;

    for (cursor = node; cursor; cursor = cursor->prev) {
        (*maze)[cursor->pos.y][cursor->pos.x] = PATH_CHAR;
    }
}