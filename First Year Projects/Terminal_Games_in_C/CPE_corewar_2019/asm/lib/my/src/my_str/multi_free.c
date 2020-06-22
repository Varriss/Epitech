/*
** EPITECH PROJECT, 2020
** MULTI_FREE
** File description:
** Multi_free function
*/

#include <stdlib.h>
#include <stdarg.h>

void *multi_free(int nb, ...)
{
    void *tmp = NULL;
    va_list ap;

    va_start(ap, nb);
    for (int k = 0; k < nb; k++) {
        tmp = va_arg(ap, void *);
        free(tmp);
    }
    va_end(ap);
    return (NULL);
}