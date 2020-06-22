/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** convert_input_file
*/

#include <stdlib.h>
#include "../include/navy.h"

#define MAP_HEIGHT 10
#define MAP_WIDTH 18

static char layout[MAP_HEIGHT][MAP_WIDTH] = {
    " |A B C D E F G H",
    "-+---------------",
    "1|. . . . . . . .",
    "2|. . . . . . . .",
    "3|. . . . . . . .",
    "4|. . . . . . . .",
    "5|. . . . . . . .",
    "6|. . . . . . . .",
    "7|. . . . . . . .",
    "8|. . . . . . . ."
};

char **generate_layout(void)
{
    char **res = malloc(sizeof(char *) * (MAP_HEIGHT + 1));

    if (!res)
        return (NULL);
    res[MAP_HEIGHT] = NULL;
    for (int i = 0; i < MAP_HEIGHT; i++)
        res[i] = my_strdup(layout[i]);
    return (res);
}

char **convert_input_file(char **file)
{
    char **res = NULL;
    int valid_map = 1;

    if (!file)
        return (NULL);
    res = generate_layout();
    valid_map = fill_map_from_file(&res, file);
    free_my_str_arr(file);
    return (valid_map == 1 ? res : NULL);
}