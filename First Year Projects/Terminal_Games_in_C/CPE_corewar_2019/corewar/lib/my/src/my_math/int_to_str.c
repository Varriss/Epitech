/*
** EPITECH PROJECT, 2020
** INT_TO_STR
** File description:
** Int_to_str function
*/

#include <stddef.h>
#include <stdlib.h>
#include "my_str.h"

char *int_to_str(int nb)
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