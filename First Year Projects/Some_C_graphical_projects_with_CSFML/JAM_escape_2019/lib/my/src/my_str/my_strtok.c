/*
** EPITECH PROJECT, 2019
** MY_STRTOK
** File description:
** Strtok function
*/

#include <stdlib.h>
#include <stddef.h>
#include "my_str.h"

int my_token_len(char const *str, char delim)
{
    int len = 0;

    if (!str)
        return (-1);
    for (; str[len] && str[len] != delim; len++);
    return (len);
}

int tokenize(char **tokens, int nb_token, char const *str, char delim)
{
    char const *tmp = str;
    int str_len;

    for (int k = 0; k < nb_token; k++) {
        str_len = my_token_len(tmp, delim);
        tokens[k] = malloc(sizeof(char) * (str_len + 1));
        if (!tokens[k])
            return (0);
        for (int c = 0; c < str_len; c++)
            tokens[k][c] = tmp[c];
        tokens[k][str_len] = '\0';
        tmp = &tmp[str_len + 1];
    }
    return (1);
}

char **my_strtok(char const *str, char delim)
{
    int nb_token = my_str_count_char(str, delim) + 1;
    char **tokens;

    if (!str)
        return (NULL);
    tokens = malloc(sizeof(char *) * (nb_token + 1));
    if (!tokens)
        return (NULL);
    for (int k = 0; k < nb_token + 1; k++)
        tokens[k] = NULL;
    if (!tokenize(tokens, nb_token, str, delim)) {
        free_2d_str(tokens);
        return (NULL);
    }
    return (tokens);
}