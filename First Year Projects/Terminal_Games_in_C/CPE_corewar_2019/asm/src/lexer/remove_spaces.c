/*
** EPITECH PROJECT, 2020
** REMOVE_SPACES
** File description:
** Remove_spaces function
*/

#include <stdlib.h>
#include "my_str.h"
#include "asm.h"
#include "op.h"

static int is_space(char c)
{
    return (my_strchr(SPACE_CHARS, c) != NULL);
}

static char get_char(char c, int in_quote)
{
    if (in_quote)
        return (c);
    if (is_space(c))
        return (DEFAULT_SPACE);
    return (c);
}

static void remove_end_space(char *line)
{
    if (line && my_strlen(line) > 0
        && line[my_strlen(line) - 1] == DEFAULT_SPACE)
        line[my_strlen(line) - 1] = '\0';
}

void remove_multi_spaces(char *line)
{
    int in_quote = 0;
    int char_id = 0;
    char *tmp = line ? malloc(sizeof(char) * (my_strlen(line) + 1)) : NULL;

    if (!tmp)
        return;
    for (int k = 0; line[k]; k++) {
        if (line[k] == STRING_DELIMITER)
            in_quote = !in_quote;
        if (!in_quote && ((k == 0 && is_space(line[k]))
            || (k != 0 && is_space(line[k - 1]) && is_space(line[k]))))
            continue;
        tmp[char_id++] = get_char(line[k], in_quote);
    }
    tmp[char_id] = '\0';
    for (int k = 0; k < my_strlen(tmp) + 1; k++)
        line[k] = tmp[k];
    remove_end_space(line);
    free(tmp);
}

void remove_spaces_between_args(char *line)
{
    int in_quote = 0;
    int char_id = 0;
    char *tmp = line ? malloc(sizeof(char) * (my_strlen(line) + 1)) : NULL;

    if (!tmp)
        return;
    for (int k = 0; line[k]; k++) {
        if (line[k] == STRING_DELIMITER)
            in_quote = !in_quote;
        if (!in_quote && ((is_space(line[k]) && line[k + 1] == SEPARATOR_CHAR)
            || (k > 0 && is_space(line[k]) && line[k - 1] == SEPARATOR_CHAR)))
            continue;
        tmp[char_id++] = get_char(line[k], in_quote);
    }
    tmp[char_id] = '\0';
    for (int k = 0; k < my_strlen(tmp) + 1; k++)
        line[k] = tmp[k];
    free(tmp);
}