/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** initialize_str
*/

#include "my.h"

void initialize_str(char *src, int size)
{
    for (int i = 0; i < size; i++)
        src[i] = '0';
    src[size - 1] = '\0';
}