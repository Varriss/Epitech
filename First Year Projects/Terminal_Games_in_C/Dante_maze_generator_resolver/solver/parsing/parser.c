/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** parser
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "solver.h"


static char **quit(char *log)
{
    my_write(1, log, 2);
    return (NULL);
}

char **parser(char *path)
{
    char **res = NULL;
    char *line = NULL;
    int fd = -1;
    int line_count = 0;

    if (access(path, F_OK) != 0)
        return (quit("Error: Could not find file.\n"));
    if (access(path, R_OK) != 0)
        return (quit("Error: Permission to read file denied.\n"));
    fd = open(path, O_RDONLY);
    for (line = get_next_line(fd); line; line = get_next_line(fd)) {
        line_count++;
        res = realloc(res, sizeof(char *) * (line_count + 1));
        res[line_count] = NULL;
        res[line_count - 1] = my_strdup(line);
        free(line);
    }
    if (line)
        free(line);
    return (res);
}