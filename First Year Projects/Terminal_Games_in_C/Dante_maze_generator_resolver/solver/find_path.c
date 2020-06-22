/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** find_path
*/


#include "solver.h"

node_t *find_smallest_node(list_t *to_test)
{
    list_t *cursor = to_test->next;
    node_t *res = NULL;


    if (to_test->next == to_test)
        return (NULL);
    res = cursor->data->node;

    for (; cursor != to_test; cursor = cursor->next) {
        if (cursor->data->node->f_cost == res->f_cost) {
            if (cursor->data->node->h_cost < res->h_cost)
                res = cursor->data->node;
        } else if (cursor->data->node->f_cost < res->f_cost)
            res = cursor->data->node;
    }
    return (res);
}

int is_in_bounds(int x, int y, char **maze)
{
    if (x < 0 || (x >= my_strlen(maze[0])))
        return (0);
    if (y < 0 || (y >= my_str_arr_len(maze)))
        return (0);
    return (1);
}

void update_node(node_t *node, node_t *cursor, char **maze, list_t *to_test)
{
    vector_i_t pos_goal = {my_strlen(maze[0]), my_str_arr_len(maze)};
    node_t *tmp_prev = cursor;
    int tmp_g_cost = tmp_prev->g_cost + 1;
    int tmp_h_cost = get_distance(node->pos, pos_goal);

    if (node->is_obstacle == 0 && node->was_visited == 0) {
        node->prev = cursor;
        node->g_cost = tmp_g_cost;
        node->h_cost = tmp_h_cost;
        node->f_cost = tmp_g_cost + tmp_h_cost;
        add_node_to_list(to_test, node);
    } else if (node->was_visited == 1 && node->is_obstacle == 0
    && (node->f_cost > tmp_g_cost + tmp_h_cost)) {
        node->prev = cursor;
        node->g_cost = tmp_g_cost;
        node->h_cost = tmp_h_cost;
        node->f_cost = tmp_g_cost + tmp_h_cost;
        add_node_to_list(to_test, node);
    }
}

void update_adjacent_nodes(node_t *cursor, char **maze, node_t ***node_arr,
list_t *to_test)
{
    list_t *cursor_cop = to_test;
    int x = cursor->pos.x;
    int y = cursor->pos.y;

    if (is_in_bounds(x + 1, y, maze))
        update_node(node_arr[y][x + 1], cursor, maze, to_test);
    if (is_in_bounds(x, y + 1, maze))
        update_node(node_arr[y + 1][x], cursor, maze, to_test);
    if (is_in_bounds(x - 1, y, maze))
        update_node(node_arr[y][x - 1], cursor, maze, to_test);
    if (is_in_bounds(x, y - 1, maze))
        update_node(node_arr[y - 1][x], cursor, maze, to_test);
    for (list_t *l_cursor = to_test->next; l_cursor != to_test;
    l_cursor = l_cursor->next, cursor_cop = cursor_cop->next) {
        if (l_cursor->data->node == cursor)
            rm_elem(l_cursor);
        if (l_cursor != cursor_cop->next)
            l_cursor = cursor_cop->next;
    }
}

int find_path(char ***maze, node_t ***node_arr, list_t *to_test)
{
    node_t *cursor = NULL;
    node_t *goal =
    node_arr[my_str_arr_len(*maze) - 1][my_strlen((*maze)[0]) - 1];

    for (cursor = find_smallest_node(to_test); cursor && cursor != goal;
    cursor = find_smallest_node(to_test)) {
        cursor->was_visited = 1;
        update_adjacent_nodes(cursor, *maze, node_arr, to_test);
    }
    if (cursor == goal) {
        trace_path(cursor, maze);
        return (SUCCESS_CODE);
    }
    return (FAILURE_CODE);
}