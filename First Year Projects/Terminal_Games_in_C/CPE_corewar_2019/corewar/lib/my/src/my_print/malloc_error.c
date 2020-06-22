/*
** EPITECH PROJECT, 2019
** MALLOC_ERROR
** File description:
** Print "malloc error" and return NULL
*/

#include <stddef.h>
#include "my_print.h"

void *malloc_error_null(void)
{
    my_putstr("malloc error\n");
    return (NULL);
}

int malloc_error_zero(void)
{
    my_putstr("malloc error\n");
    return (0);
}