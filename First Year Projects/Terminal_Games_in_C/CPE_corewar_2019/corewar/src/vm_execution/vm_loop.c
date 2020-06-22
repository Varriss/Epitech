/*
** EPITECH PROJECT, 2020
** vm_loop
** File description:
** vm_loop
*/

#include "fc_list.h"
#include "op.h"
#include <stdlib.h>

static uint8_t define_desc(vm_data_t *data, int i, uint8_t inst)
{
    uint8_t desc = 0;

    if (inst == 1 || inst == 9 || inst == 12 || inst == 15)
        return (0);
    desc = data->mem[data->prog[i]->pc];
    data->prog[i]->pc = (data->prog[i]->pc + 1) % MEM_SIZE;
    return (desc);
}

static void exec_inst(vm_data_t *data, int i)
{
    uint8_t inst = data->mem[data->prog[i]->pc];
    uint8_t desc = 0;
    void (*funct)(vm_data_t *, int, uint8_t);

    if (data->prog[i]->cycle >= 1)
        data->prog[i]->cycle -= 1;
    if (data->prog[i]->cycle > 0)
        return;
    data->prog[i]->pc = (data->prog[i]->pc + 1) % MEM_SIZE;
    for (int k = 0; k < 16; k++)
        if (inst == fc_list[k].code) {
            desc = define_desc(data, i, inst);
            funct = fc_list[k].f;
            funct(data, i, desc);
            add_new_cycle(data, i);
            return;
        }
}

void vm_loop(vm_data_t *data)
{
    for (int i = 0; data->prog[i]; i++)
        add_new_cycle(data, i);
    while (data->nbr_cycle == -1 || data->cycle_actl < data->nbr_cycle) {
        data->cycle_actl += 1;
        if (data->cycle_to_die <= 0 || (data->cycle_actl
        % data->cycle_to_die == 0 && check_dead(data) == 1))
            return;
        for (int i = 0; data->prog[i]; i++)
            exec_inst(data, i);
        if (data->nbr_live <= 0) {
            data->nbr_live = NBR_LIVE;
            data->cycle_to_die -= CYCLE_DELTA;
        }
    }
}
