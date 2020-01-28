/*
** EPITECH PROJECT, 2020
** Model
** File description:
** my_free
*/

#include "my.h"

void free_tab(char **tab)
{
    int i = 0;

    while (tab[i] != 0) {
        free(tab[i]);
        i++;
    }
    free(tab[i]);
    free(tab);
}