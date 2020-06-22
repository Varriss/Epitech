/*
** EPITECH PROJECT, 2019
** MY_GET_NBR
** File description:
** Convert char * to int
*/

#include "../../include/my_str.h"

int my_get_nbr(char const *str)
{
    int number = 0;
    int is_neg = 0;
    int k = 0;

    if (!str || !str[0])
        return (0);
    if (str[0] == '+' || str[0] == '-') {
        if (!str[1])
            return (0);
        is_neg = str[0] == '-';
        k++;
    }
    for (; str[k]; k++) {
        number *= 10;
        if (is_neg)
            number -= str[k] - 48;
        else
            number += str[k] - 48;
    }
    return (number);
}

long long int my_get_llint(char const *str)
{
    long long int number = 0;
    int is_neg = 0;
    int k = 0;

    if (!str || !str[0])
        return (0);
    if (str[0] == '+' || str[0] == '-') {
        if (!str[1])
            return (0);
        is_neg = str[0] == '-';
        k++;
    }
    for (; str[k]; k++) {
        number *= 10;
        if (is_neg)
            number -= str[k] - 48;
        else
            number += str[k] - 48;
    }
    return (number);
}

