/*
** EPITECH PROJECT, 2020
** Model main
** File description:
** main
*/

#include "generator.h"
#include <time.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    char **maze = NULL;

    srand(time(NULL));
    if (((ac != 3) && (ac != 4)) || my_str_isnum(av[1]) || (my_atoi(av[1]) == 0)
    || my_str_isnum(av[2]) || (my_atoi(av[2]) == 0))
        return (my_write(FAILURE_CODE
        , "Error: use './generator [x > 0] [y > 0] [perfect]'.\n", 2));
    if ((ac == 4) && (!my_streq(av[3], "perfect")))
        return (my_write(FAILURE_CODE, "Error: Did you mean 'perfect' ?\n", 2));
    maze = init_tab_with(my_atoi(av[1]), my_atoi(av[2]), 'X');
    if (ac == 4)
        return (create_perfect_maze(maze, 1));
    else
        return (create_perfect_maze(maze, 0));
}

