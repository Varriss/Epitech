/*
** EPITECH PROJECT, 2019
** MY_STR_ISNUM
** File description:
** No clue either
*/

#include "my.h"

// return (84) if no str and (1) if not a nbr

int my_str_isnum(char *str)
{
    int i = 0;

    if (!str)
        return (84);
    if (str[0] == '-')
        i++;
    for (; str[i] != '\0'; i++) {
        if (!(('0' <= str[i] && str[i] <= '9'))) {
            return (1);
        }
    }
    return (0);
}