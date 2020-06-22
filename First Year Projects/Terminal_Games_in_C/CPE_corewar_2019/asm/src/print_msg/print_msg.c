/*
** EPITECH PROJECT, 2020
** PRINT_MSG
** File description:
** Print_msg function
*/

#include <stddef.h>
#include "my_print.h"
#include "strings.h"
#include "asm.h"
#include "op.h"

void print_empty_file(void)
{
    char name[1000];

    get_file_name(name);
    my_putstr_error(EMPTY_FILE_1);
    my_putstr_error(name);
    my_putstr_error(EMPTY_FILE_2);
}

void print_warning(int line, char const *warning)
{
    char name[1000];

    get_file_name(name);
    my_putstr_error(MSG_WARNING_1);
    my_putstr_error(name);
    my_putstr_error(MSG_WARNING_2);
    my_put_nbr_error(line);
    my_putstr_error(MSG_WARNING_3);
    my_putstr_error(warning);
    my_putstr_error(MSG_WARNING_4);
}

void print_error(int line, char const *error)
{
    char name[1000];

    get_file_name(name);
    my_putstr_error(MSG_ERROR_1);
    my_putstr_error(name);
    my_putstr_error(MSG_ERROR_2);
    my_put_nbr_error(line);
    my_putstr_error(MSG_ERROR_3);
    my_putstr_error(error);
    my_putstr_error(MSG_ERROR_4);
}

void print_inv_nb_args(int line, int op_id, int nb_args)
{
    if (nb_args <= op_tab[op_id].nbr_args)
        print_error(line, INVALID_ARGS);
    else
        print_error(line, TOO_MANY_ARGS);
}