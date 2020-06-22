/*
** EPITECH PROJECT, 2020
** new_ls
** File description:
** flags_handle
*/

#include "./include/proj.h"

static char list[] = {'a', 'l', 'R', 't', 'r', 'd'};

static int basic_case_handle(char *dir_name, int solo)
{
    struct dirent **tab = NULL;

    tab = list_dir(dir_name);
    if (tab == NULL)
        return (84);
    sort(tab, 0);
    if (!solo)
        my_printf("%s:\n", dir_name);
    for (int i = 0; tab[i] != NULL; i++)
        if ((tab[i]->d_name[0] != '.'))
            my_printf("%s  ", tab[i]->d_name);
    my_printf("\n");
    free(tab);
    return (0);
}

static int no_flags_handle(char **targ)
{
    int fail = 0;

    for (int i = 0; targ[i] != 0; i++) {
        if (basic_case_handle(targ[i], (targ[1] == NULL ? 1 : 0)) != 0) {
            my_printf("ls: cannot access '%s': No such file or directory\n"
            , targ[i]);
            fail = 1;
        }
        if (targ[i + 1] != 0)
            my_printf ("\n");
    }
    free(targ);
    return (fail);
}

static int is_flags(char c)
{
    for (int i = 0; list[i] != '\0'; i++)
        if (list[i] == c)
            return (1);
    return (0);
}

static int flags_only_handle(char *flags)
{
    struct dirent **tab = NULL;

    for (int i = 0; flags[i] != '\0'; i++)
        for (int j = 0; flags[i] != list[j]; j++)
            if (list[j] == '\0') {
                my_printf("ls: invalid option -- '%c'\n", flags[i]);
                return (84);
            }
    tab = list_dir(".");
    for (int i = 0; tab[i] != NULL; i++)
        if (tab[i]->d_name[0] != '.')
            my_printf("%s  ", tab[i]->d_name);
        else if (is_flags('a'))
            my_printf("%s  ", tab[i]->d_name);
    free(flags);
    return (0);
}

int args_handle(int ac, char **av)
{
    char *flags = storeflags(av);
    char **targets = get_targets(av);
    t_f_t *f_t = NULL;

    if ((flags == NULL) && (targets == NULL) && (ac == 1))
        return (basic_case_handle(".", 1));
    else if ((flags == NULL) ^ (targets == NULL)) {
        if (flags == NULL)
            return (no_flags_handle(targets));
        if (targets == NULL)
            return (flags_only_handle(flags));
    }
    f_t = malloc(sizeof(t_f_t));
    f_t->flags = flags;
    f_t->targets = targets;
    return (0);
}
