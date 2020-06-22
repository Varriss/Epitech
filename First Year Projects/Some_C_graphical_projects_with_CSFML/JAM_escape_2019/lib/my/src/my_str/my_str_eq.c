/*
** EPITECH PROJECT, 2019
** MY_STR_EQ
** File description:
** Return 1 if equal or 0 else
*/

#include "my_str.h"

int my_str_eq(char const *s1, char const *s2)
{
    return (my_strcmp(s1, s2) == 0);
}