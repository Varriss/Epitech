/*
** EPITECH PROJECT, 2020
** Model
** File description:
** get_next_line
*/

#include "my.h"

static int stop_tool(char *buff, int stop)
{
    free(buff);
    if (stop == 0)
        return (1);
    else
        return (0);
}

static char *re_roll(char prev[static READ_SIZE], char *buff, int split)
{
    prev = get_pre_aft(prev, 1, split, find_char_pos(prev, '\0'));
    free(buff);
    return (get_pre_aft(prev, -1, split, find_char_pos(prev, '\0')));
}

static char *do_split_z(char prev[static READ_SIZE], char *buff, int split
, int re)
{
    prev = get_pre_aft(buff, 1, split, re);
    free(buff);
    return ("");
}

static char *do_split_a(char prev[static READ_SIZE], char *buff, int split
, int re)
{
    char *line = NULL;

    line = my_strcat(prev, get_pre_aft(buff, -1, split, re));
    prev = get_pre_aft(buff, 1, split, re);
    free(buff);
    return (line);
}

char *get_next_line(int fd)
{
    char static *prev = NULL;
    int static stop = 0;
    char *buff = malloc(sizeof(char) * READ_SIZE);
    int read_ret = 0;
    int split = 0;

    if ((split = find_char_pos(prev, '\n')) != -1)
        return (re_roll(prev, buff, split));
    do {
        read_ret = read(fd, buff, READ_SIZE);
        if (read_ret == 0)
            return ((stop = stop_tool(buff, stop)) == 1 ? prev : NULL);
        if ((split = find_char_pos(buff, '\n')) != -1)
            return (do_split_a(prev, buff, split, read_ret));
        if (split == 0)
            return (do_split_z(prev, buff, split, read_ret));
        prev = my_strcat(prev, get_pre_aft(buff, -1, read_ret, read_ret));
    } while (read_ret == READ_SIZE);
    free(buff);
    return (my_strcat(prev, NULL));
}