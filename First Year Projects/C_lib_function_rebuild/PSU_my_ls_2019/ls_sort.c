OB/*
** EPITECH PROJECT, 2020
** new_ls
** File description:
** ls_sort
*/

#include "./include/proj.h"

// swap index and index -1
static void tab_swap(struct dirent **tab, int index)
{
    struct dirent *tmp = NULL;

    tmp = tab[index - 1];
    tab[index - 1] = tab[index];
    tab[index] = tmp;
}

static int sort_tool(struct dirent **tab, int index, int rank)
{
    if ((tab[index]->d_name[rank] == '\0')
    && (tab[index - 1]->d_name[rank] == '\0'))
        return (0);
    if ((tab[index]->d_name[rank] == '\0')) {
        tab_swap(tab, index);
        return (1);
    } else
        return (0);
}

// between index and index -1
static int sort_between_two(struct dirent **tab, int index, int rank)
{
    char one = tab[index]->d_name[rank];
    char two = tab[index - 1]->d_name[rank];

    if ((one == '\0')
    | (two == '\0')) {
        return (sort_tool(tab, index, rank));
    }
    one = ((one >= 'A') && (one <= 'Z') ? one + 32 : one);
    two = ((two >= 'A') && (two <= 'Z') ? two + 32 : two);
    if (one < two) {
        tab_swap(tab, index);
        return (1);
    } else if (one == two)
        return (sort_between_two(tab, index, rank + 1));
    else
        return (0);
}

// just gave him a zero rank
void sort(struct dirent **tab, int rank)
{
    int continu = 0;
    char one = 0;
    char two = 0;

    for (int index = 1; tab[index] != NULL; index++) {
        one = tab[index]->d_name[rank];
        two = tab[index - 1]->d_name[rank];
        one = ((one >= 'A') && (one <= 'Z') ? one + 32 : one);
        two = ((two >= 'A') && (two <= 'Z') ? two + 32 : two);
        if (two == one)
            continu = sort_between_two(tab, index, 0);
        if (two > one) {
            tab_swap(tab, index);
            continu = 1;
        }
        if (continu == 1)
            sort(tab, rank);
    }
}
