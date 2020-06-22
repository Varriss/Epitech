/*
** EPITECH PROJECT, 2020
** GET_STRING
** File description:
** Get_string function
*/

#include <stdlib.h>
#include "my_str.h"
#include "asm.h"
#include "op.h"

static int is_valid_string_line(char const *line, char const *name)
{
    int char_id = 0;

    if (!line || !name)
        return (EXIT_FAILURE);
    if (my_strncmp(name, line, my_strlen(name)) != 0)
        return (EXIT_FAILURE);
    char_id = my_strlen(name);
    if (line[char_id] != DEFAULT_SPACE || line[char_id + 1] != STRING_DELIMITER)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

char *get_string(char const *line, char const *name)
{
    int char_id = 0;
    char *string = NULL;

    if (is_valid_string_line(line, name))
        return (NULL);
    string = malloc(sizeof(char) * (my_strlen(line) + 1));
    if (!string)
        return (NULL);
    char_id = my_strlen(name) + 2;
    for (int k = 0; line[char_id]; k++, char_id++) {
        string[k] = line[char_id];
        if (line[char_id] == STRING_DELIMITER && line[char_id + 1] == '\0') {
            string[k] = '\0';
            return (string);
        }
        else if (line[char_id] == STRING_DELIMITER)
            return (multi_free(1, string));
    }
    return (multi_free(1, string));
}

int is_string_line(char const *line)
{
    return (my_strchr(line, STRING_DELIMITER) != NULL);
}