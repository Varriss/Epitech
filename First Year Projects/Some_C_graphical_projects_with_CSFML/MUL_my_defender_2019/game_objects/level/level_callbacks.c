/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** level_callbacks
*/

#include <stdlib.h>
#include "my_defender.h"

void destroy_level(prog_stat_t *prog_stat, struct level *level)
{
    free(level->l_info);
    free(level->p_info);
    free(level);
}