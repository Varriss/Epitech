/*
** EPITECH PROJECT, 2019
** MY_STR_ISNUM
** File description:
** Return 1 if only digits and else 0
*/

#include "my_str.h"
#include "my_math.h"

int no_overflow(char const *str)
{
    int is_neg = 0;
    int i = 0;

    for (; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-')
            is_neg = (is_neg + 1) % 2;
    }
    if (my_strlen(&str[i]) > 10)
        return (0);
    else if (my_strlen(&str[i]) < 10)
        return (1);
    if (is_neg && my_strcmp(&str[i], &STR_INT_MIN[1]) != -1)
        return (0);
    else if (!is_neg && my_strcmp(&str[i], STR_INT_MAX) != -1)
        return (0);
    return (1);
}

int my_str_isint(char const *str)
{
    char ch;
    int is_sign;

    if (!str)
        return (0);
    ch = str[0];
    is_sign = ch == '+' || ch == '-';
    for (int c = 0; str[c] != '\0'; c++) {
        ch = str[c];
        if (!((ch >= '0' && ch <= '9') || (ch == '+' || ch == '-')))
            return (0);
        if (!(ch == '+' || ch == '-') && is_sign)
            is_sign = 0;
        else if ((ch == '+' || ch == '-') && !is_sign)
            return (0);
    }
    if (is_sign)
        return (0);
    return (no_overflow(str));
}