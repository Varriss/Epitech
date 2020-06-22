/*
** EPITECH PROJECT, 2020
** check_dead
** File description:
** check_dead
*/

#include "corewar.h"
#include "op.h"
#include <stdlib.h>

static int check_end(vm_data_t *data)
{
    int first_nb = data->prog[0]->prog_nb;

    free(data->alive_prog);
    data->alive_prog = 0;
    for (int i = 1; data->prog[i]; i++)
        if (data->prog[i]->prog_nb != first_nb)
            return (0);
    return (1);
}

static int is_alive(vm_data_t *data, int k)
{
    for (int i = 0; data->alive_prog && data->alive_prog[i]; i++)
        if (data->alive_prog[i] == data->prog[k]->prog_nb)
            return (1);
    return (0);
}

static int count_prog(vm_data_t *data)
{
    int i = 0;

    for (int k = 0; data->prog[k]; k++)
        if (is_alive(data, k) == 1)
            i++;
    return (i);
}

int check_dead(vm_data_t *data)
{
    int i = count_prog(data);
    prog_t **new_list = NULL;

    new_list = malloc(sizeof(prog_t *) * (i + 1));
    if (!new_list)
        return (1);
    for (int k = 0, l = 0; data->prog[k]; k++)
        if (is_alive(data, k) == 1) {
            new_list[l] = data->prog[k];
            new_list[l + 1] = NULL;
            l++;
        }
    free(data->prog);
    data->prog = new_list;
    if (i <= 1 || check_end(data) == 1)
        return (1);
    return (0);
}
