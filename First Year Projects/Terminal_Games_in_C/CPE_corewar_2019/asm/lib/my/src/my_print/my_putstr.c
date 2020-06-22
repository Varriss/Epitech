/*
** EPITECH PROJECT, 2019
** MY_PUTSTR
** File description:
** Displays string
*/

#include <unistd.h>
#include "my_str.h"

int my_putstr_and_rtn(char const *str, int rtn_value)
{
    if (str)
        write(1, str, my_strlen(str));
    return (rtn_value);
}

void my_putstr_error(char const *str)
{
    if (str)
        write(2, str, my_strlen(str));
}

int my_putstr_error_and_rtn(char const *str, int rtn_value)
{
    if (str)
        write(2, str, my_strlen(str));
    return (rtn_value);
}

void my_putstr(char const *str)
{
    if (str)
        write(1, str, my_strlen(str));
}

void my_putstr_line(char const *str)
{
    if (str)
        write(1, str, my_strlen(str));
    write(1, "\n", 1);
}