/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** datatypes
*/

#ifndef DATATYPES_H_
#define DATATYPES_H_

typedef struct list list_t;

typedef enum g_o_type
{
    node,
    ant,
    str
} g_o_type_t;

////////////////////////////////////////////////////////////////////////////////
//                         Linked list Datastructure                          //
////////////////////////////////////////////////////////////////////////////////


typedef struct node_s
{
    int g_cost;
    int was_visited;
    struct node_s *prev;
    struct node_s *best_path;
    char special_id;
    char *descriptor;
    int ants;
    list_t *linked_nodes;
} node_t;

typedef struct ant
{
    int id;
    node_t *room;
} ant_t;

typedef struct line
{
    char *str;
} line_t;


typedef union list_data
{
    node_t *node;
    ant_t *ant;
    line_t *line;
} list_data_t;

#endif /* !DATATYPES_H_ */