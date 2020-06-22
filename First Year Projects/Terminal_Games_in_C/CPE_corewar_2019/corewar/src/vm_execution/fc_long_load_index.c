/*
** EPITECH PROJECT, 2020
** fc_long_load_index
** File description:
** fc_long_load_index
*/

#include "corewar.h"
#include "op.h"

static int32_t define_first_param(vm_data_t *data, int i, uint8_t desc)
{
    int32_t first_p = 0;

    if (desc >= 192) {
        first_p = take_data(data, data->prog[i]->pc, IND_SIZE);
        first_p += data->prog[i]->pc - 2;
        first_p = take_data(data, first_p, IND_SIZE);
        data->prog[i]->pc += IND_SIZE;
    } else if (desc >= 128) {
        first_p = take_data(data, data->prog[i]->pc, IND_SIZE);
        data->prog[i]->pc += IND_SIZE;
    }
    return (first_p);
}

static int32_t define_sec_param(vm_data_t *data, int i, uint8_t desc
, int inst_adress)
{
    int32_t sec_p = 0;

    desc = desc % 64;
    if (desc >= 48) {
        sec_p = take_data(data, data->prog[i]->pc, IND_SIZE);
        sec_p += inst_adress;
        sec_p = take_data(data, sec_p, IND_SIZE);
        data->prog[i]->pc += IND_SIZE;
    } else if (desc >= 32) {
        sec_p = take_data(data, data->prog[i]->pc, IND_SIZE);
        data->prog[i]->pc += IND_SIZE;
    }
    return (sec_p);
}

void fc_long_load_index(vm_data_t *data, int i, uint8_t desc)
{
    int inst_adress = data->prog[i]->pc - 2;
    int32_t first_p = define_first_param(data, i, desc);
    int32_t sec_p = define_sec_param(data, i, desc, inst_adress);
    uint8_t reg_nb = take_data(data, data->prog[i]->pc, 1);
    int val = (first_p + sec_p) + inst_adress;

    data->prog[i]->pc += 1;
    data->prog[i]->carry = 0;
    if (reg_nb > 0 && reg_nb <= REG_NUMBER && val < MEM_SIZE) {
        data->prog[i]->reg[reg_nb - 1] = take_data(data, val, REG_SIZE);
        data->prog[i]->carry = 1;
    }
}
