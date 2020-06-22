/*
** EPITECH PROJECT, 2020
** fc_store_index
** File description:
** fc_store_index
*/

#include "corewar.h"
#include "op.h"

static int32_t define_sec_param(vm_data_t *data, int i, uint8_t desc
, int inst_adress)
{
    int32_t sec_p = 0;

    desc = desc % 64;
    if (desc >= 48) {
        sec_p = take_data(data, data->prog[i]->pc, IND_SIZE);
        sec_p += inst_adress;
        data->prog[i]->pc += IND_SIZE;
        sec_p = data->mem[sec_p];
    } else if (desc >= 32) {
        sec_p = take_data(data, data->prog[i]->pc, IND_SIZE);
        data->prog[i]->pc += IND_SIZE;
    } else {
        sec_p = take_data(data, data->prog[i]->pc, 1);
        if (sec_p > 0 && sec_p <= REG_NUMBER)
            sec_p = data->prog[i]->reg[sec_p - 1];
        data->prog[i]->pc += 1;
    }
    return (sec_p);
}

static int32_t define_third_param(vm_data_t *data, int i, uint8_t desc
, int inst_adress)
{
    int32_t third_p = 0;

    desc = desc % 64;
    if (desc >= 48) {
        third_p = take_data(data, data->prog[i]->pc, IND_SIZE);
        third_p += inst_adress;
        data->prog[i]->pc += IND_SIZE;
        third_p = data->mem[third_p];
    } else if (desc >= 32) {
        third_p = take_data(data, data->prog[i]->pc, IND_SIZE);
        data->prog[i]->pc += IND_SIZE;
    } else {
        third_p = take_data(data, data->prog[i]->pc, 1);
        if (third_p > 0 && third_p <= REG_NUMBER)
            third_p = data->prog[i]->reg[third_p - 1];
        data->prog[i]->pc += 1;
    }
    return (third_p);
}

void fc_store_index(vm_data_t *data, int i, uint8_t desc)
{
    int inst_adress = data->prog[i]->pc - 2;
    uint8_t reg_nb = take_data(data, data->prog[i]->pc, 1);
    int32_t sec_p = 0;
    int32_t third_p = 0;
    int32_t val = 0;
    int nb = 0;

    data->prog[i]->pc += 1;
    sec_p = define_sec_param(data, i, desc, inst_adress);
    third_p = define_third_param(data, i, desc, inst_adress);
    if (reg_nb > 0 && reg_nb <= REG_NUMBER)
        val = data->prog[i]->reg[reg_nb - 1];
    for (int k = REG_SIZE - 1; k >= 0; k--) {
        nb = val >> ((REG_SIZE - 1 - k) * 8) & 0b11111111;
        data->mem[inst_adress + (sec_p + third_p) % IDX_MOD + k] = nb;
    }
}
