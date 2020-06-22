/*
** EPITECH PROJECT, 2019
** MY_MALLOC
** File description:
** Malloc all types
*/

#include <stddef.h>
#include <stdlib.h>

char *fill_of(char c, int size)
{
    char *str = malloc(sizeof(char) * (size + 1));

    if (!str)
        return (NULL);
    for (int i = 0; i < size; i++)
        str[i] = c;
    str[size] = '\0';
    return (str);
}