/*
** EPITECH PROJECT, 2020
** MAIN
** File description:
** Main function
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_print.h"
#include "my_str.h"
#include "jam.h"
#include "strings.h"

int has_display_env(char const **envp)
{
    for (int env = 0; envp[env]; env++)
        if (my_strncmp(envp[env], "DISPLAY=", 8))
            return (EXIT_SUCCESS);
    my_putstr_error(MISS_DISPLAY_ENV);
    return (EXIT_FAILURE);
}

int main(int ac, char const **av, char const **envp)
{
    if (ac > 1 && my_str_eq(av[1], "-h")) {
        my_putstr(HELP);
        return (EXIT_SUCCESS);
    }
    if (has_display_env(envp) == EXIT_FAILURE)
        return (84);
    return (jam());
}