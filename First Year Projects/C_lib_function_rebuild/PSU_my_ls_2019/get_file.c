/*
** EPITECH PROJECT, 2020
** new_ls
** File description:
** get_file
*/

#include "./include/duo_stumper.h"

static int get_dir_nbr(char *fpath)
{
    int nbr = 0;
    DIR *dir = opendir(fpath);
    struct dirent *info = readdir(dir);

    while (info != NULL) {
        nbr++;
        info = readdir(dir);
    }
    closedir(dir);
    return (nbr);
}

struct dirent **list_dir(char *fpath)
{
    DIR *dir = opendir(fpath);
    struct dirent *info = NULL;
    int dir_nbr = 0;
    struct dirent **tab = NULL;

    if (dir == NULL)
        return (NULL);
    info = readdir(dir);
    dir_nbr = get_dir_nbr(fpath);
    tab = malloc(sizeof(struct dirent *) * dir_nbr + 1);
    for (int i = 0; info != NULL; i++) {
        tab[i] = info;
        info = readdir(dir);
    }
    tab[dir_nbr] = NULL;
    closedir(dir);
    return (tab);
}
