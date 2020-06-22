/*
** EPITECH PROJECT, 2020
** fc_live
** File description:
** fc_live
*/

#include "corewar.h"
#include "op.h"
#include "my_print.h"
#include <stddef.h>
#include <stdlib.h>

static void add_prog_nb(vm_data_t *data)
{
    int len = 0;
    int *new_list = NULL;
    int k = 0;

    for (int i = 0; data->alive_prog && data->alive_prog[i]; i++)
        if (data->alive_prog[i] == data->nb_win)
            return;
    if (data->alive_prog)
        for (; data->alive_prog[len]; len++);
    new_list = malloc(sizeof(int) * (len + 2));
    if (!new_list)
        return;
    for (; k < len; k++)
        new_list[k] = data->alive_prog[k];
    new_list[k] = data->nb_win;
    new_list[k + 1] = 0;
    free(data->alive_prog);
    data->alive_prog = new_list;
}

void fc_live(vm_data_t *data, int i, uint8_t desc)
{
    my_putstr("The player ");
    my_put_nbr(take_data(data, data->prog[i]->pc, 4));
    my_putstr(" (");
    my_putstr(data->prog[i]->name);
    my_putstr(") is alive.\n");
    UNUSED(desc);
    data->nb_win = take_data(data, data->prog[i]->pc, 4);
    data->name_win = data->prog[i]->name;
    data->prog[i]->pc += 4;
    data->nbr_live -= 1;
    add_prog_nb(data);
}
