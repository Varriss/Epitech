/*
** EPITECH PROJECT, 2020
** Model
** File description:
** SOLVER
*/

#ifndef SOLVER_H_
#define SOLVER_H_

#include "../lib/my/my.h"
#include "../lib/lists/lists.h"

#define SUCCESS_CODE 0
#define FAILURE_CODE 84

#define OBSTACLE_CHAR 'X'
#define PATH_CHAR 'o'

#define READ_SIZE 1

#include "datatypes.h"

char **parser(char *path);
char *get_next_line(int fd);

int solver(char **maze);
int is_in_bounds(int x, int y, char **maze);
int get_distance(vector_i_t x1, vector_i_t x2);
void trace_path(node_t *node, char ***maze);

void print_list_nodes(list_t *nodes);

node_t ***create_node_arr(char **maze);
void free_node_arr(node_t ***node_arr);
void add_node_to_list(list_t *list, node_t *node);

int find_path(char ***maze, node_t ***node_arr, list_t *to_test);

#endif /* !SOLVER_H_ */