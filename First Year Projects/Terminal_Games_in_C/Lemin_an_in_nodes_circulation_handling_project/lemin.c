/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** lemin
*/

#include "lemin.h"
#include <stdio.h>

static void reset_nodes(list_t *nodes)
{
    list_t *cursor = nodes->next;

    for (; cursor != nodes; cursor = cursor->next) {
        cursor->data->node->g_cost = -1;
        cursor->data->node->was_visited = 0;
        cursor->data->node->prev = NULL;
    }
}

static void add_paths(list_t *node_list)
{
    list_t *cursor = node_list->next;
    list_t *to_test = NULL;

    for (; cursor != node_list; cursor = cursor->next) {
        cursor->data->node->g_cost = 0;
        cursor->data->node->prev = NULL;
        to_test = create_list();
        add_node_to_list(to_test, cursor->data->node);
        pathfinding(to_test, node_list);
        delete_list(to_test);
        reset_nodes(node_list);
    }
}

int check_path_validity(char id, list_t *root)
{
    list_t *cursor = root->next;
    list_t *to_test = create_list();
    int return_val = FAILURE_CODE;

    for (; cursor->data->node->special_id != id; cursor = cursor->next) {
        if (cursor->data == NULL)
            return (my_write(FAILURE_CODE, "No path found.\n", 2));
    }
    add_node_to_list(to_test, cursor->data->node);
    return_val = pathfinding(to_test, root);
    delete_list(to_test);
    reset_nodes(root);
    if (return_val == FAILURE_CODE)
        my_write(1, "No path found.\n", 2);
    return (return_val);
}

static void print_file(char **file)
{
    int tunnels = 0;

    my_printf("#number_of_ants\n");
    my_printf("%s\n#rooms\n", file[0]);
    for (int i = 1; file[i]; i++) {
        if (my_findchar(' ', file[i]) == -1 && (file[i][0] != '#')
        && (tunnels == 0)) {
            tunnels = 1;
            my_putstr("#tunnels\n");
        }
        my_printf("%s\n", file[i]);
    }
}

int lemin(void)
{
    char **file = parser();
    list_t *node_list = NULL;
    list_t *ant_list = NULL;

    if (!file)
        return (FAILURE_CODE);
    node_list = create_anthill(file);
    ant_list = create_ants(node_list);
    print_file(file);
    if (ant_list == NULL)
        return (FAILURE_CODE);
    add_paths(node_list);
    if (check_path_validity('S', node_list) == SUCCESS_CODE)
        move_ants(ant_list);
    destroy_node_list(node_list);
    destroy_ants(ant_list);
    free_my_str_arr(file);
    return (SUCCESS_CODE);
}