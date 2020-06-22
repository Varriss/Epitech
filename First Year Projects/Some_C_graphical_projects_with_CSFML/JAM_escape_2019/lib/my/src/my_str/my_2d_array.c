/*
** EPITECH PROJECT, 2019
** MY_2D_ARRAY
** File description:
** 2d array functon
*/

#include <stdlib.h>
#include <stddef.h>

void *free_2d_str(char **str)
{
    if (!str)
        return (NULL);
    for (int k = 0; str[k]; k++)
        free(str[k]);
    free(str);
    return (NULL);
}

int str_array_len(char **str)
{
    int len = 0;

    if (!str)
        return (0);
    for (; str[len]; len++);
    return (len);
}