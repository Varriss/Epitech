/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** check_input_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/navy.h"

#define SHIP_NB 4
#define CONFIG_LINE_SIZE 8

static char format_comp[8][8] = {
    "2345",
    ":",
    "ABCDEFGH",
    "12345678",
    ":",
    "ABCDEFGH",
    "12345678",
};

static char **quit(char *src)
{
    my_write(1, src, 2);
    return (NULL);
}

static char **get_input_file(char *path)
{
    size_t n = 10000;
    char *line = NULL;
    char **res = malloc(sizeof(char *) * (SHIP_NB + 1));
    FILE *fd = fopen(path, "r");
    int counter = 0;
    ssize_t i;

    if (!res || !fd)
        return (quit("Error: Could not open file.\n"));
    res[SHIP_NB] = NULL;
    for (i = getline(&line, &n, fd); i >= 0 && counter < 10; counter++) {
        if (counter < SHIP_NB)
            res[counter] = my_strdup(line);
        i = getline(&line, &n, fd);
    }
    if (counter != 4)
        free_my_str_arr(res);
    free(line);
    fclose(fd);
    return ((counter != 4) ? quit("Error: Invalid file length.\n") : res);
}

static int check_if_valid_sizes(char **file)
{
    int len = my_str_arr_len(file);

    for (int i = 0; i < len; i++) {
        if (!(((i == len - 1) && (my_strlen(file[i]) == CONFIG_LINE_SIZE - 1))
            || my_strlen(file[i]) == CONFIG_LINE_SIZE))
            return (0);
    }
    return (1);
}

static int check_if_valid_values(char **file)
{

    for (int i = 0; file[i]; i++) {
        for (int j = 0; j < (CONFIG_LINE_SIZE - 1); j++) {
            if (my_findchar(file[i][j], format_comp[j]) == -1)
                return (0);
        }
        if (!((file[i][2] == file[i][5]) ^ (file[i][3] == file[i][6])))
            return (0);
        if (file[i][2] == file[i][5])
            if ((file[i][6] - file[i][3]) != (file[i][0] - '1'))
                return (0);
        if (file[i][3] == file[i][6])
            if ((file[i][5] - file[i][2]) != (file[i][0] - '1'))
                return (0);
    }
    return (1);
}

char **check_input_file(char *path)
{
    char **file = get_input_file(path);

    if (!file)
        return (NULL);
    if (check_if_valid_sizes(file) != 1 || check_if_valid_values(file) != 1) {
        free_my_str_arr(file);
        return (quit("Error: Incorrect input file format.\n"));
    }
    return (file);
}