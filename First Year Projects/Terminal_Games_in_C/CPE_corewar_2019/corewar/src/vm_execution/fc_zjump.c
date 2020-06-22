/*
** EPITECH PROJECT, 2020
** fc_zjump
** File description:
** fc_zjump
*/

#include "corewar.h"
#include "op.h"

void fc_zjump(vm_data_t *data, int i, uint8_t desc)
{
    int32_t first_p = take_data(data, data->prog[i]->pc, IND_SIZE);

    UNUSED(desc);
    data->prog[i]->pc += IND_SIZE;
    if (data->prog[i]->carry == 1) {
        data->prog[i]->pc -= IND_SIZE + 1;
        data->prog[i]->pc += first_p % IDX_MOD;
        data->prog[i]->pc = data->prog[i]->pc % MEM_SIZE;
    }
}
