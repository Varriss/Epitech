/*
** EPITECH PROJECT, 2020
** TRY_HELP
** File description:
** Try_help function
*/

#include "my_print.h"

void try_help(char const *binary_name, char const *msg)
{
    my_putstr(binary_name);
    my_putstr(": ");
    my_putstr(msg);
    my_putstr("\n");
    my_putstr("Try '");
    my_putstr(binary_name);
    my_putstr(" -h' for more information.\n");
}