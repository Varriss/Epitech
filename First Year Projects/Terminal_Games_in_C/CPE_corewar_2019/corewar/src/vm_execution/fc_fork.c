/*
** EPITECH PROJECT, 2020
** fc_fork
** File description:
** fc_fork
*/

#include "corewar.h"
#include "op.h"
#include <stddef.h>
#include <stdlib.h>

static void add_new_prog(vm_data_t *data, prog_t *new_prog)
{
    prog_t **new_prog_list = NULL;
    int i = 0;

    for (; data->prog[i]; i++);
    new_prog_list = malloc(sizeof(prog_t *) * (i + 2));
    if (!new_prog_list)
        return;
    for (int k = 0; k < i; k++)
        new_prog_list[k] = data->prog[k];
    new_prog_list[i] = new_prog;
    new_prog_list[i + 1] = NULL;
    free(data->prog);
    data->prog = new_prog_list;
}

static void create_new_prog(vm_data_t *data, int i, int32_t first_p)
{
    prog_t *new_prog = malloc(sizeof(prog_t));

    if (!new_prog)
        return;
    new_prog->name = data->prog[i]->name;
    new_prog->origin = data->prog[i]->origin;
    new_prog->prog_nb = data->prog[i]->prog_nb;
    new_prog->pc = first_p;
    new_prog->carry = data->prog[i]->carry;
    new_prog->cycle = data->prog[i]->cycle;
    new_prog->reg = malloc(sizeof(uint32_t) * REG_NUMBER);
    if (!new_prog->reg)
        return;
    for (int k = 0; k < REG_NUMBER; k++)
        new_prog->reg[k] = data->prog[i]->reg[k];
    add_new_prog(data, new_prog);
}

void fc_fork(vm_data_t *data, int i, uint8_t desc)
{
    int32_t first_p = data->prog[i]->pc - 1;

    UNUSED(desc);
    first_p += take_data(data, data->prog[i]->pc, IND_SIZE) % IDX_MOD;
    data->prog[i]->pc += IND_SIZE;
    create_new_prog(data, i, first_p);
}
