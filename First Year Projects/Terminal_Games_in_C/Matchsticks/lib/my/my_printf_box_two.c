/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf_nbrs
*/

#include "my.h"

void my_put_octal_nbr(unsigned int src)
{
    my_put_base_nbrs(src, "01234567");
}

void my_put_hexa_nbr(unsigned int src)
{
    my_put_base_nbrs(src, "0123456789abcdef");
}

void my_put_s_hexa_nbr(unsigned int src)
{
    my_put_base_nbrs(src, "0123456789ABCDEF");
}

void my_put_bin_nbr(unsigned int src)
{
    my_put_base_nbrs(src, "01");
}

void my_put_ptr(unsigned int src)
{
    write(1, "0x", 2);
    my_put_hexa_nbr(src);
}