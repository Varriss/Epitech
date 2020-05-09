/*
** EPITECH PROJECT, 2019
** MY_ATOI
** File description:
** Converts a string to a positive integer
*/

#include "./my.h"
#include <stdlib.h>

int my_atoi(char *src)
{
    int res = 0;

    for (int j = 0, i = my_strlen(src) - 1; i >= 0; i--, j++) {
        if (src[j] != '-')
            res += (src[j] - '0') * my_compute_power_rec(10, i);
    }
    return (src[0] == '-' ? -res : res);
}

char *my_itoa(int nb)
{
    char *str = malloc(sizeof(char) * (12));
    int is_neg = (nb < 0);
    int i = 0;

    if (nb == 0) {
        str[i] = '0';
        i++;
    }
    for (; nb != 0; i++) {
        str[i] = (1 - is_neg * 2) * (nb % 10) + '0';
        nb /= 10;
    }
    if (is_neg) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    return (my_revstr(str));
}