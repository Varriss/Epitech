/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** find_object
*/

#include "my_defender.h"

list_t *find_object(list_t *go_list, g_o_type_t type)
{
    list_t *res = go_list->next;

    for(; (res->data != NULL) && (res->data->enemy->type != type);
    res = res->next);
    if (res->data == NULL)
        return (NULL);
    return (res);
}