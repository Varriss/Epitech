/*
** EPITECH PROJECT, 2020
** fc_add_sub
** File description:
** fc_add_sub
*/

#include "corewar.h"
#include "op.h"

void fc_add_sub(vm_data_t *data, int i, uint8_t desc)
{
    uint8_t reg1 = take_data(data, data->prog[i]->pc, 1);
    uint8_t reg2 = take_data(data, (data->prog[i]->pc + 1) % MEM_SIZE, 1);
    int reg3 = 0;

    UNUSED(desc);
    data->prog[i]->pc += 2;
    reg3 = take_data(data, data->prog[i]->pc, 1);
    data->prog[i]->pc += 1;
    data->prog[i]->carry = 0;
    if (reg1 > 0 && reg2 > 0 && reg3 > 0 && reg1 <= REG_NUMBER
    && reg2 <= REG_NUMBER && reg3 <= REG_NUMBER) {
        reg1 = data->prog[i]->reg[reg1 - 1];
        reg2 = data->prog[i]->reg[reg2 - 1];
        data->prog[i]->carry = 1;
    } else
        return;
    if (take_data(data, data->prog[i]->pc - 5, 1) == 4)
        data->prog[i]->reg[reg3 - 1] = reg1 + reg2;
    else
        data->prog[i]->reg[reg3 - 1] = reg1 - reg2;
}
