/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** find_object
*/

#include "my_rpg.h"

list_t *find_object(list_t *go_list, g_o_type_t type)
{
    list_t *res = go_list->next;

    for (; res->data && (res->data->button->type != type);
    res = res->next);
    if (res && (res->data == NULL))
        return (NULL);
    return (res);
}

list_t *find_object_r(list_t *go_list, g_o_type_t type)
{
    list_t *res = go_list->prev;

    for (; (res->data != NULL) && (res->data->button->type != type);
    res = res->prev);
    if (res->data == NULL)
        return (NULL);
    return (res);
}