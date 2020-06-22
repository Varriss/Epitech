/*
** EPITECH PROJECT, 2020
** new_ls
** File description:
** parsing_tools
*/

#include "./include/proj.h"

char *storeflags(char **av)
{
    char *stored = NULL;
    int len = 0;

    for (int i = 0; av[i] != 0; i++)
        if (av[i][0] == '-')
            len += my_strlen(av[i]) - 1;
    if (len == 0)
        return (NULL);
    stored = malloc(len + 1);
    stored[len] = '\0';
    len = 0;
    for (int i = 0; av[i] != 0; i++)
        if (av[i][0] == '-')
            for (int j = 1; av[i][j] != '\0'; j++, len++)
                stored[len] = av[i][j];
    return (stored);
}

char **get_targets(char **av)
{
    char **targets = NULL;
    int nbr = 0;

    for (int i = 1; av[i] != 0; i++)
        if (av[i][0] != '-')
            nbr++;
    if (nbr == 0)
        return (NULL);
    targets = malloc(sizeof(char *) * (nbr + 1));
    targets[nbr] = 0;
    nbr = 0;
    for (int i = 1; av[i] != 0; i++)
        if (av[i][0] != '-') {
            targets[nbr] = av[i];
            nbr++;
        }
    return (targets);
}