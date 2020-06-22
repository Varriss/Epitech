/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fc_display
*/

#include "corewar.h"
#include "op.h"
#include "my_print.h"

void fc_display(vm_data_t *data, int i, uint8_t desc)
{
    uint8_t regnum = data->mem[data->prog[i]->pc];
    uint32_t bin;
    char c = 0;

    UNUSED(desc);
    if ((regnum > 0) && (regnum <= REG_NUMBER)) {
        bin = data->prog[i]->reg[regnum - 1];
        c = bin % 256;
        my_putchar(c);
    }
    data->prog[i]->pc += T_REG;
}
