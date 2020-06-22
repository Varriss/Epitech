/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** builtins_one
*/

#include "include/proj.h"

int my_cd(char *buffer)
{
    int ret = 0;
    char **argv = NULL;

    for (ret = 0; buffer[ret] != '\n'; ret++);
    buffer[ret] = '\0';
    argv = str_to_tab(buffer);
    (ret = chdir(argv[1]));
    free_tab(argv);
    free(buffer);
    return (ret);
}

int my_env(char *buffer, char **env)
{
    char **argv = NULL;

    for (int i = 0; buffer[i + 1] != '\0'; i++)
        buffer[i + 1] == '\n' ? buffer[i + 1] = '\0' : 0;
    argv = str_to_tab(buffer);
    if (str_ncmp(argv[0], "env", 3))
        for (int i = 0; env[i] != 0; i++)
            my_printf("%s\n", env[i]);
    if (str_ncmp(argv[0], "setenv", 6))
        return (my_setenv(argv, env));
    free(buffer);
    free_tab(argv);
    return (0);
}

int my_exit(char *buffer)
{
    char **argv = str_to_tab(buffer);
    int retu = 0;

    free(buffer);
    if (!argv[1]) {
        free_tab(argv);
        my_printf("exit\n");
        exit(0);
    }
    for (int i = 0; argv[1][i] != '\0'; i++)
        if (argv[1][i + 1] == '\n')
            argv[1][i + 1] = '\0';
    for (int i = 1; argv[i] != 0; i++)
        if ((i > 1) || (my_str_isnum(argv[i])))
            return (84);
    retu = my_getnbr(argv[1]);
    my_printf("exit\n");
    exit(retu);
}