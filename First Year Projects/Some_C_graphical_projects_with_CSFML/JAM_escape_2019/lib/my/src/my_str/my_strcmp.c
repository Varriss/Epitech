/*
** EPITECH PROJECT, 2019
** MY_STRCMP
** File description:
** Reproduce the behavior of the str_cmp function
*/

#include <stddef.h>

int my_strcmp(char const *s1, char const *s2)
{
    int c;

    if (!s1 || !s2)
        return (-1);
    for (c = 0; s1[c] == s2[c]; c++) {
        if (s1[c] == '\0' || s2[c] == '\0' )
            return (s1[c] - s2[c]);
    }
    return (s1[c] - s2[c]);
}