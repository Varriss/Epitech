/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** builtins_two
*/

#include "include/proj.h"

static char **dup_plus(char **env, char *env_nam, char *env_valu)
{
    char **new_env = NULL;
    int len = 0;
    char *split = "=";

    for (; env[len] != 0; len++);
    new_env = malloc(sizeof(char *) * (len + 1));
    for (int i = 0; i < len - 1; i++, new_env[i] = env[i]);
    new_env[len] = 0;
    new_env[len] = my_strcat(env_nam, split);
    new_env[len] = my_strcat(new_env[len], env_valu);
    return (new_env);
}

int my_setenv(char **argv, char **env)
{
    char **new_env = NULL;

    if ((argv[2]) && (argv[2] != NULL) && ((!argv[3]) || (argv[3] == 0))) {
        new_env = dup_plus(env, argv[1], argv[2]);
        env = new_env;
        return (0);
    }
    return (84);
}// use access for check /path/"the prog"

char *get_str_in_tab(char **tab, char *to_find)
{
    int i = 0;

    for (; !str_ncmp(tab[i], to_find, my_strlen(to_find) - 1); i++);
    return (tab[i]);
}