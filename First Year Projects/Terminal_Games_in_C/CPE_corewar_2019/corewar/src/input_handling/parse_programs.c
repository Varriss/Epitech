/*
** EPITECH PROJECT, 2020
** parse_programs
** File description:
** parse_programs
*/

#include "corewar.h"
#include "op.h"
#include "my_str.h"
#include "my_str_is.h"
#include "my_math.h"
#include <stddef.h>
#include <stdlib.h>

static int check_prog_nb(vm_data_t *data, int *nb_prog)
{
    if (!data->prog) {
        if (nb_prog[0] < 1)
            nb_prog[0] = 1;
        return (0);
    }
    for (int i = 0; data->prog[i]; i++)
        if (nb_prog[0] < 1 || nb_prog[0] == data->prog[i]->prog_nb)
            nb_prog[0] = 1;
    for (int i = 0; data->prog[i]; i++)
        if (nb_prog[0] == data->prog[i]->prog_nb) {
            i = 0;
            nb_prog[0] += 1;
        }
    return (0);
}

static int add_prog(vm_data_t *data, prog_t *new_prog, int *i)
{
    prog_t **new_prog_list = NULL;
    int c = 0;

    if (!new_prog->name)
        i[0] -= 1;
    if (!new_prog->name || new_prog->name[0] == '-')
        return (ERROR);
    if (data->prog)
        for (; data->prog[c]; c++);
    new_prog_list = malloc(sizeof(prog_t *) * (c + 2));
    for (int k = 0; new_prog_list && k < c; k++)
        new_prog_list[k] = data->prog[k];
    if (new_prog_list) {
        new_prog_list[c] = new_prog;
        new_prog_list[c + 1] = NULL;
        free(data->prog);
        data->prog = new_prog_list;
    }
    return (0);
}

static int new_program_name(vm_data_t *data, prog_t *new_prog, int *i
, char **arg)
{
    new_prog->name = my_strclone(arg[i[0]]);
    if (add_prog(data, new_prog, i) == ERROR)
        return (ERROR);
    return (0);
}

static int new_program(vm_data_t *data, char **arg, int *i)
{
    prog_t *new_prog = malloc(sizeof(prog_t));

    if (!new_prog)
        return (0);
    if (my_strcmp("-dump", arg[i[0]]) == 0)
        i[0] += 2;
    new_prog->prog_nb = 1;
    if (my_strcmp("-n", arg[i[0]]) == 0 && my_str_isint(arg[i[0] + 1]) == 1) {
        new_prog->prog_nb = my_get_nbr(arg[i[0] + 1]);
        i[0] += 2;
    }
    check_prog_nb(data, &new_prog->prog_nb);
    new_prog->origin = -1;
    if (my_strcmp("-a", arg[i[0]]) == 0 && my_str_ishex(arg[i[0] + 1]) == 1) {
        new_prog->origin = hex_to_int(arg[i[0] + 1]);
        i[0] += 2;
    }
    if (new_program_name(data, new_prog, i, arg) == ERROR)
        return (ERROR);
    return (0);
}

int parse_programs(vm_data_t *data, char **arg)
{
    for (int i = 1; arg[i]; i++) {
        if (my_strcmp("-dump", arg[i]) == 0 && my_str_isint(arg[i + 1]) == 1)
            i++;
        else if (new_program(data, arg, &i) == ERROR)
            return (ERROR);
    }
    return (0);
}
