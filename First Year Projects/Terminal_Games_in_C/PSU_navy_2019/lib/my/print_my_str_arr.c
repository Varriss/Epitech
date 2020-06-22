/*
** EPITECH PROJECT, 2020
** PRINT_MY_STR_ARR
** File description:
** Prints an str array with sep as a separator
*/

#include "my.h"

void print_my_str_arr(char **src, char sep)
{
    for (int i = 0; src[i]; i++) {
        my_putstr(src[i]);
        my_putchar(sep);
    }
}