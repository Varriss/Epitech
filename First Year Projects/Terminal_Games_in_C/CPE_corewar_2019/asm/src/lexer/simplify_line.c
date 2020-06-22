/*
** EPITECH PROJECT, 2020
** SIMPLIFY_LINE
** File description:
** Simplify_line function
*/

#include <stdlib.h>
#include "my_str.h"
#include "asm.h"
#include "op.h"

char *lexe_line(char *line)
{
    char *lexed_line = simplify_line(line);

    if (line)
        free(line);
    return (lexed_line);
}

void remove_comment(char *line)
{
    int in_quotes = 0;

    if (!line)
        return;
    for (int k = 0; line[k]; k++) {
        if (line[k] == STRING_DELIMITER)
            in_quotes = !in_quotes;
        if (!in_quotes && line[k] == COMMENT_CHAR) {
            line[k] = '\0';
            return;
        }
    }
}

char *simplify_line(char const *line)
{
    char *simplified = line ? my_strclone(line) : NULL;

    if (!simplified)
        return (NULL);
    remove_comment(simplified);
    remove_multi_spaces(simplified);
    remove_spaces_between_args(simplified);
    return (simplified);
}