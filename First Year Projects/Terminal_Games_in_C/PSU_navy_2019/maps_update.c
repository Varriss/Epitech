/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** maps_update
*/

#include "./include/navy.h"

int update_own_map(char **map, char *pos)
{
    int y = (pos[0] - 64) * 2;
    int x = pos[1] - 48;

    if (my_isnumber(map[x + 1][y])) {
        map[x + 1][y] = 'x';
        my_printf("%s: hit\n\n", pos);
        return (1);
    } else if (map[x + 1][y] == '.') {
        map[x + 1][y] = 'o';
        my_printf("%s: missed\n\n", pos);
        return (0);
    }
    return (0);
}

int update_radar(char **radar, char *pos, int hitted)
{
    int y = (pos[0] - 64) * 2;
    int x = pos[1] - 48;

    if (hitted) {
        radar[x + 1][y] = 'x';
        return (1);
    } else {
        radar[x + 1][y] = 'o';
        return (0);
    }
}

void print_maps(char **own_map, char **radar)
{
    my_printf("my positions:\n");
    for (int i = 0; own_map[i]; i++)
        my_printf("%s\n", own_map[i]);
    my_printf("\nenemy's positions:\n");
    for (int i = 0; radar[i]; i++)
        my_printf("%s\n", radar[i]);
    my_putchar('\n');
}