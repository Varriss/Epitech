/*
** EPITECH PROJECT, 2019
** MY_STRCLONE
** File description:
** My_strclone function
*/

#include <stddef.h>
#include <stdlib.h>
#include "my_str.h"

char *my_strclone(char const *str)
{
    char *clone;
    int len;

    if (!str)
        return (NULL);
    len = my_strlen(str);
    clone = malloc(sizeof(char) * (len + 1));
    for (int k = 0; str[k] != '\0'; k++)
        clone[k] = str[k];
    clone[len] = '\0';
    return (clone);
}