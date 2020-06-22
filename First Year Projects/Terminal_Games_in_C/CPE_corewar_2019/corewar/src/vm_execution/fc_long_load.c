/*
** EPITECH PROJECT, 2020
** fc_long_load
** File description:
** fc_long_load
*/

#include "corewar.h"
#include "op.h"

static int32_t define_first_param(vm_data_t *data, int i, uint8_t desc)
{
    int32_t first_p = 0;

    if (desc >= 192) {
        first_p = take_data(data, data->prog[i]->pc, IND_SIZE);
        first_p += data->prog[i]->pc - 2;
        data->prog[i]->pc += IND_SIZE;
        first_p = take_data(data, first_p, REG_SIZE);
    } else if (desc >= 128) {
        first_p = take_data(data, data->prog[i]->pc, DIR_SIZE);
        data->prog[i]->pc += DIR_SIZE;
    } else {
        first_p = take_data(data, data->prog[i]->pc, 1);
        data->prog[i]->pc += 1;
        if (first_p > 0 && first_p - 1 < REG_NUMBER)
            first_p = data->prog[i]->reg[first_p - 1];
    }
    return (first_p);
}

void fc_long_load(vm_data_t *data, int i, uint8_t desc)
{
    int32_t first_p = define_first_param(data, i, desc);
    uint8_t reg_nb = take_data(data, data->prog[i]->pc, 1);

    data->prog[i]->pc += 1;
    data->prog[i]->carry = 0;
    if (reg_nb > 0 && reg_nb - 1 < REG_NUMBER) {
        data->prog[i]->reg[reg_nb - 1] = first_p;
        data->prog[i]->carry = 1;
    }
}
