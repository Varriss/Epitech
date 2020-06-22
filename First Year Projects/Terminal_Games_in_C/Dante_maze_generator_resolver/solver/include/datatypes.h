/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** datatypes
*/

#ifndef DATATYPES_H_
#define DATATYPES_H_

typedef struct vector_i
{
    int x;
    int y;
} vector_i_t;

typedef struct node
{
    char is_obstacle;
    char was_visited;
    int g_cost;
    int h_cost;
    int f_cost;
    vector_i_t pos;
    struct node *prev;
} node_t;

typedef struct active_list_s
{
    int type;
    int x;
    int y;
} active_list_t;

typedef union list_data
{
    node_t *node;
    active_list_t *active;
} list_data_t;

#endif /* !DATATYPES_H_ */
