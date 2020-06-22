/*
** EPITECH PROJECT, 2019
** MY_REVSTR
** File description:
** Rev str
*/

#include "my_str.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char tmp[len];

    for (int c = 0; c < len; c++) {
        tmp[c] = str[len - c - 1];
    }
    for (int c = 0; c < len; c++) {
        str[c] = tmp[c];
    }
    return str;
}