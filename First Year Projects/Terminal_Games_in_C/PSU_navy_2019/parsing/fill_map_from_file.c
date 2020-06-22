/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** fill_map_from_file
*/

#include <unistd.h>
#include "../include/navy.h"

static void check_boat_direction(char *file_line, int *posx, int *posy, int j)
{
    if (file_line[2] == file_line[5])
        (*posy) += j;
    else if (file_line[3] == file_line[6])
        (*posx) += (2 * j);
    else
        my_write(FAILURE_CODE, "Watch out I'm being stupid.\n", 2);
}

static int quit(void)
{
    write(2, "Error: Invalid input file, boats are crossing.\n", 48);
    return (0);
}

int fill_map_from_file(char ***res, char **file)
{
    int posx = 0;
    int posy = 0;

    for (int i = 0; file[i]; i++) {
        for (int j = 0; j < (file[i][0] - '0'); j++) {
            posx = 2 + (2 * (file[i][2] - 'A'));
            posy = 2 + file[i][3] - '1';
            check_boat_direction(file[i], &posx, &posy, j);
            if ((*res)[posy][posx] == '.')
                (*res)[posy][posx] = file[i][0];
            else
                return (quit());
        }
    }
    return (1);
}