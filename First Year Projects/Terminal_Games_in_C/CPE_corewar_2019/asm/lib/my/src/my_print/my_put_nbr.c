/*
** EPITECH PROJECT, 2019
** INT_TO_STR
** File description:
** Print int
*/

#include <stdlib.h>
#include "my_print.h"
#include "my_str.h"

void my_put_nbr(int nb)
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
    my_putstr(my_revstr(str));
    free(str);
}

void my_put_nbr_error(int nb)
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
    my_putstr_error(my_revstr(str));
    free(str);
}
