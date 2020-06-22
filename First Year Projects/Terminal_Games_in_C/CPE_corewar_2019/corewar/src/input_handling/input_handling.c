/*
** EPITECH PROJECT, 2020
** input_handling
** File description:
** input_handling
*/

#include "corewar.h"
#include "op.h"
#include "my_str.h"
#include "my_str_is.h"
#include "my_math.h"

static int check_dump(char *arg)
{
    if (!arg)
        return (0);
    if (my_str_isint(arg) == 1)
        return (1);
    if (my_str_ishex(arg) == 1)
        return (1);
    return (0);
}

static int stock_cycle(char *arg)
{
    if (my_str_isint(arg) == 1)
        return (my_get_nbr(arg));
    return (hex_to_int(arg));
}

static int found_nbr_cycle(vm_data_t *data, char **arg)
{
    int nb_cycle = 0;

    for (int i = 1; arg[i]; i++) {
        if (my_strcmp("-dump", arg[i]) == 0 && check_dump(arg[i + 1]) == 1)
            nb_cycle = stock_cycle(arg[2]);
        else if (my_strcmp("-dump", arg[i]) == 0 && check_dump(arg[i + 1]) == 0)
            return (ERROR);
    }
    if (nb_cycle > 0)
        data->nbr_cycle = nb_cycle;
    else
        data->nbr_cycle = -1;
    for (int i = 1; arg[i]; i++)
        if (arg[i][0] == '-' && my_strcmp("-dump", arg[i]) != 0
        && my_strcmp("-n", arg[i]) != 0 && my_strcmp("-a", arg[i]) != 0)
            return (ERROR);
    return (0);
}

int input_handling(vm_data_t *data, char **arg)
{
    if (found_nbr_cycle(data, arg) == ERROR)
        return (ERROR);
    if (parse_programs(data, arg) == ERROR)
        return (ERROR);
    return (0);
}
