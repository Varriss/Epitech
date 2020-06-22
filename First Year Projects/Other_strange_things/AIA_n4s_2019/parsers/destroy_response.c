/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** destroy_responce
*/

#include <stdlib.h>
#include "ai.h"

void destroy_response(response_t *to_destroy)
{
    if (to_destroy->status)
        free(to_destroy->status);
    if (to_destroy->code_str)
        free(to_destroy->code_str);
    if (to_destroy->add_infos)
        free(to_destroy->add_infos);
    if (to_destroy->distances)
        free(to_destroy->distances);
    free(to_destroy);
    to_destroy = NULL;
}