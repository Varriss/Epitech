/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** main
*/

#include "include/proj.h"

int fork_proce(int ret, char *buffer, char **env)
{
    int status = 0;
    int retu = 0;

    if ((fork() == 0)) {
        if (ret == -1)
            exit(1);
        else {
            retu = prog_exe(buffer, env);
            free(buffer);
            exit(retu);
        }
    } else {
        wait(&status);
        free(buffer);
        return (WEXITSTATUS(status));
    }
}

static int builtins_process(char *buffer, char **env)
{
    if (str_ncmp(buffer, "exit", 4))
        return (my_exit(buffer));
    if (str_ncmp(buffer, "cd", 2))
        return (my_cd(buffer));
    if ((str_ncmp(buffer, "env", 3)) || (str_ncmp(buffer, "setenv", 6))
    || (str_ncmp(buffer, "unsetenv", 8)))
        return (my_env(buffer, env));
    return (84);
}

// return 1 to stop the prog

int prompt(char **env, int ret, size_t *n)
{
    char *buffer = NULL;

    ret = getline(&buffer, n, stdin);
    if ((ret != -1) && (str_ncmp(buffer, "\n", 1)))
        return (0);
    if ((ret == -1) || str_ncmp(buffer, "./", 2) || str_ncmp(buffer, "/", 1)
    || (str_ncmp(buffer, "ls", 2)))
        return (fork_proce(ret, buffer, env));
    else if ((str_ncmp(buffer, "exit", 4)) || (str_ncmp(buffer, "cd", 2))
    || (str_ncmp(buffer, "env", 3)) || (str_ncmp(buffer, "setenv", 6))
    || (str_ncmp(buffer, "unsetenv", 8))) {
        return (builtins_process(buffer, env));
    } else {
        my_printf("Command not found : %s", buffer);
        free(buffer);
    }
    return (0);
}

int floor_zero(int argc, char **env)
{
    int ret = 0;
    size_t n = 0;

    if (argc != 1)
        return (84);
    my_printf("%s $> ", getcwd(NULL, 0));
    while ((ret = prompt(env, ret, &n)) != 1)
        if (ret != 0)
            my_printf("%s $ Last return : %d > ", getcwd(NULL, 0), ret);
        else
            my_printf("%s $> ", getcwd(NULL, 0));
    my_printf("\nexit\n");
    return (0);
}