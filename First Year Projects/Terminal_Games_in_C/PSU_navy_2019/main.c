/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** main
*/

#include "./include/navy.h"

int main(int argc, char *const *argv)
{
    char **map = NULL;

    if ((argc > 3) ^ (argc == 1))
        return (my_write(FAILURE_CODE, "Error: Invalid number of args.\n", 2));
    map = check_input_file(argv[argc - 1]);
    map = convert_input_file(map);
    if (!map)
        return (FAILURE_CODE);
    return (link_then_start(argc, argv, map));
}