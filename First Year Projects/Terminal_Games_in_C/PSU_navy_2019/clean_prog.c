/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** clean_prog
*/

#include <stdlib.h>
#include "./include/navy.h"

int clean_all(int to_return, char **map, struct sigaction *sig)
{
    free_my_str_arr(map);
    free(sig);
    return (to_return);
}