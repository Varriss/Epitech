/*
** EPITECH PROJECT, 2019
** MY_STR_ISNUM
** File description:
** Return 1 if only digits and else 0
*/

#include "my_str.h"
#include "my_math.h"

int no_int_overflow(char const *str)
{
    int is_neg = 0;
    int i = 0;

    for (; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-')
            is_neg = (is_neg + 1) % 2;
    }
    if (my_strlen(&str[i]) > my_strlen(STR_INT_MAX))
        return (0);
    else if (my_strlen(&str[i]) < my_strlen(STR_INT_MAX))
        return (1);
    if (is_neg && my_strcmp(&str[i], &STR_INT_MIN[1]) != -1)
        return (0);
    else if (!is_neg && my_strcmp(&str[i], STR_INT_MAX) != -1)
        return (0);
    return (1);
}

int my_str_isint(char const *str)
{
    int k = 0;

    if (!str || !str[0])
        return (0);
    if (str[0] == '+' || str[0] == '-') {
        if (!str[1])
            return (1);
        k++;
    }
    for (; str[k] != '\0'; k++) {
        if (!(str[k] >= '0' && str[k] <= '9'))
            return (0);
    }
    return (no_int_overflow(str));
}

int no_llint_overflow(char const *str)
{
    int is_neg = 0;
    int i = 0;

    for (; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-')
            is_neg = (is_neg + 1) % 2;
    }
    if (my_strlen(&str[i]) > my_strlen(STR_LLINT_MAX))
        return (0);
    else if (my_strlen(&str[i]) < my_strlen(STR_LLINT_MAX))
        return (1);
    if (is_neg && my_strcmp(&str[i], &STR_LLINT_MIN[1]) != -1)
        return (0);
    else if (!is_neg && my_strcmp(&str[i], STR_LLINT_MAX) != -1)
        return (0);
    return (1);
}

int my_str_isllint(char const *str)
{
    int k = 0;

    if (!str || !str[0])
        return (0);
    if (str[0] == '+' || str[0] == '-') {
        if (!str[1])
            return (1);
        k++;
    }
    for (; str[k] != '\0'; k++) {
        if (!(str[k] >= '0' && str[k] <= '9'))
            return (0);
    }
    return (no_llint_overflow(str));
}