/*
** EPITECH PROJECT, 2020
** fc_store
** File description:
** fc_store
*/

#include "corewar.h"
#include "op.h"

static int32_t define_sec_param(vm_data_t *data, int i, uint8_t desc)
{
    int32_t sec_p = 0;

    desc = desc % 64;
    if (desc >= 48) {
        sec_p = take_data(data, data->prog[i]->pc, IND_SIZE);
        sec_p += data->prog[i]->pc - 3;
        data->prog[i]->pc += IND_SIZE;
        sec_p = data->mem[sec_p];
    } else if (desc >= 32) {
        sec_p = take_data(data, data->prog[i]->pc, DIR_SIZE);
        data->prog[i]->pc += DIR_SIZE;
    } else {
        sec_p = take_data(data, data->prog[i]->pc, 1);
        data->prog[i]->pc += 1;
    }
    return (sec_p);
}

void fc_store(vm_data_t *data, int i, uint8_t desc)
{
    int inst_adress = data->prog[i]->pc - 2;
    uint32_t nb_reg = data->prog[i]->reg[take_data(data, data->prog[i]->pc, 1)];
    int32_t sec_p = 0;

    data->prog[i]->pc += 1;
    sec_p = define_sec_param(data, i, desc);
    if (nb_reg > 0 && nb_reg <= REG_NUMBER)
        nb_reg = data->prog[i]->reg[nb_reg - 1];
    else
        return;
    if (desc % 64 < 32) {
        if (sec_p > 0 && sec_p <= REG_NUMBER)
            data->prog[i]->reg[sec_p - 1] = nb_reg;
    } else {
        data->mem[(inst_adress + sec_p % IDX_MOD) % MEM_SIZE] = nb_reg;
    }
}
