/*
** EPITECH PROJECT, 2019
** MY_STRCHR
** File description:
** My_strchr function
*/

#include <stddef.h>
#include "my_str.h"

char *my_strchr(char const *str, char c)
{
    if (!str)
        return (NULL);
    for (int k = 0; str[k]; k++)
        if (str[k] == c)
            return ((char *)&str[k]);
    return (NULL);
}

int my_strchr_index(char const *str, char c)
{
    char *tmp = my_strchr(str, c);

    if (!tmp)
        return -1;
    return (my_strlen(str) - my_strlen(tmp));
}

int my_strchr_nindex(char const *str, char c, int n)
{
    int k = -1;

    if (!str || n < 0)
        return (-1);
    do {
        k++;
        if (str[k] == c)
            n--;
    }
    while (str[k] && n >= 0);
    if (!str[k])
        return (-1);
    return (my_strlen(str) - my_strlen(&str[k]));
}