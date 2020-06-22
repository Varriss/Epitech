/*
** EPITECH PROJECT, 2019
** MY_GETNBR
** File description:
** returns a number, sent to the function as a string
*/

#include "my.h"

int is_negative(char const *str, int mk1)
{
    if ((!str) || (!mk1))
        return (0);
    if (str[mk1-1] == '-')
        return (-1);
    else
        return (1);
}

int my_char_int_conv(char c)
{
    if (!c)
        return (0);
    return ((int)(c - '0'));
}

int my_getnbr(char const *str)
{
    int result = 0;
    int pow = 0;
    int tmp = 0;
    int stop = 0;

    if (!str)
        return (0);
    stop = ((str[0] == '-') | (str[0] == '+')) ? 1 : 0;
    for (int i = my_strlen(str) - 1; i > stop; i--) {
        tmp = my_compute_power_rec(10, pow);
        tmp *= my_char_int_conv(str[i - 1]);
        pow++;
        result += tmp;
    }
    if (str[0] == '-')
        result *= -1;
    return (result);
}