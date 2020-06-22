/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_exec
*/

#include "include/proj.h"

static char *cat_it(char *first, char *secon)
{
    int i = 0;
    int first_len = (!first ? 0 : my_strlen(first) - 1);
    int secon_len = (!secon ? 0 : my_strlen(secon) - 1);
    char *concated = malloc(sizeof(char) * ((first_len + secon_len) + 1));

    if (first)
        for (; i < first_len; i++)
            concated[i] = first[i];
    if (secon)
        for (; i < (first_len + secon_len); i++)
            concated[i] = secon[i - first_len];
    concated[(first_len + secon_len)] = '\0';
    return (concated);
}

static int ls_use(char **argv, char **env)
{
    char *path = get_str_in_tab(env, "PATH=");
    char *tmp_path = NULL;

    path += 5;
    tmp_path = get_next_split(path, ':');
    tmp_path = cat_it(tmp_path, "/ls");
    while (access(tmp_path, F_OK) != 0) {
        free(tmp_path);
        tmp_path = get_next_split(path, ':');
        tmp_path = cat_it(tmp_path, "/ls");
    }
    if (tmp_path != NULL) {
        path -= 5;
        return (execve(tmp_path, argv, env));
    } else {
        free_tab(argv);
        free(path);
        free(tmp_path);
        my_printf("'ls' isn't in the environnement path's");
        return (0);
    }
}

int prog_exe(char *filepath, char **env)
{
    char **argv = NULL;
    int i = 0;

    for (; filepath[i] != '\n'; i++);
    filepath[i] = '\0';
    argv = str_to_tab(filepath);
    if (str_cmp(argv[0], "ls"))
        return (ls_use(argv, env));
    if (!(access(argv[0], F_OK)) || !(access(argv[0], X_OK)))
        my_printf("%s : No file or acces denied.", argv[0]);
    else if (execve(argv[0], argv, env) == -1) {
        free_tab(argv);
        return (84);
    }
    free_tab(argv);
    return (0);
}