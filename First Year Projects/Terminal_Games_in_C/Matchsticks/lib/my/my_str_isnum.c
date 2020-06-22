/*
** EPITECH PROJECT, 2019
** MY_STR_ISNUM
** File description:
** No clue either
*/

#include "my.h"

// return (1) if not a number or no str

int my_str_isnum(char *str)
{
    int i = 0;

    if (!str)
        return (1);
    if (str[0] == '-')
        i++;
    for (; str[i] != '\0'; i++) {
        if (!(('0' <= str[i] && str[i] <= '9'))) {
            return (1);
        }
    }
    return (0);
}