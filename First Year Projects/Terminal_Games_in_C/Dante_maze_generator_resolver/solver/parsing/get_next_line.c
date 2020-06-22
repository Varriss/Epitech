/*
** EPITECH PROJECT, 2020
** CPE_duostumper_1_2019
** File description:
** Reads a line from a file.
*/

#include <stdlib.h>
#include <unistd.h>
#include "solver.h"

static char *is_done(char *res, int *done)
{
    if (*done == 0) {
        *done = 1;
        return (res);
    }
    free(res);
    return (NULL);
}

char *get_next_line(int fd)
{
    char *buffer = malloc(sizeof(char) * (READ_SIZE + 1));
    char *res = malloc(sizeof(char));
    static int done = 0;

    if (!buffer || !res)
        return (NULL);
    buffer[0] = '\0';
    buffer[1] = '\0';
    res[0] = '\0';
    while (done == 0 && (read(fd, buffer, READ_SIZE) > 0)) {
        if (buffer[0] == '\n') {
            free(buffer);
            return (res);
        }
        else
            res = my_strcat(res, my_strdup(buffer));
    }
    free(buffer);
    return (is_done(res, &done));
}
