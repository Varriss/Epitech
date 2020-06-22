/*
** EPITECH PROJECT, 2020
** MAIN
** File description:
** Main function
*/

#include <stddef.h>
#include "my_str.h"
#include "my_print.h"
#include "strings.h"
#include "asm.h"

int main(int ac, char const *av[])
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        my_putstr(HELP);
        return (0);
    }
    if (ac != 2) {
        try_help(av[0], INVALID_ARG_COUNT);
        return (84);
    }
    return (parse_file(av[1]));
}