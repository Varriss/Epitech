/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_printf_box_one
*/

#include "my.h"

void my_super_putstr(char *src)
{
    char c = 92;

    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] <= 31 ^ src[i] >= 127) {
            write(1, &c, 1);
            if (src[i] < 100)
                write(1, "0", 1);
            if (src[i] < 10)
                write(1, "0", 1);
            my_put_octal_nbr(src[i]);
        } else
            write(1, &src[i], 1);
    }
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(1 , &str[i], 1);
    return (0);
}

int my_put_nbr(int nb)
{
    int display;
    char neg = '-';

    if (nb < 0) {
        nb *= -1;
        write(1, &neg, 1);
    }
    if (nb >= 10) {
        display = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        display += '0';
        write(1, &display, 1);
    } else if (nb < 10) {
        nb += '0';
        write(1, &nb, 1);
    }
    return (0);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_base_nbrs(unsigned int src, char *base)
{
    int base_len = my_strlen(base);
    int rank = src;
    char c = '\0';

    if (src >= base_len) {
        rank = src % base_len;
        src /= base_len;
        my_put_base_nbrs(src, base);
    }
    c = base[rank];
    write(1, &c, 1);
}