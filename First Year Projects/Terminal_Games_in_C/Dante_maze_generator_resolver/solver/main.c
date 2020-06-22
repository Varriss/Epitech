/*
** EPITECH PROJECT, 2020
** Model main
** File description:
** main
*/

#include "solver.h"

int main(int ac, char **av)
{
    if (ac == 2)
        return (solver(parser(av[1])));
    return (my_write(FAILURE_CODE,
            "Error: Invalid nubmer of arguments.\n", 2));
}