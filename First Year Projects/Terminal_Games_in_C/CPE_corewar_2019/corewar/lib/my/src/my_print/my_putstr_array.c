/*
** EPITECH PROJECT, 2019
** MY_PUTSTR_ARRAY
** File description:
** Print str array
*/

#include "my_print.h"

void my_putstr_array(char **str, char separator)
{
    for (int k = 0; str[k]; k++) {
        my_putstr(str[k]);
        my_putchar(separator);
    }
}