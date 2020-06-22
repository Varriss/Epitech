/*
** EPITECH PROJECT, 2020
** fc_and
** File description:
** fc_and
*/

#include "corewar.h"
#include "op.h"

static uint32_t define_first_param(vm_data_t *data, int i, uint8_t desc)
{
    uint32_t first_p = 0;

    if (desc >= 192) {
        first_p = take_data(data, data->prog[i]->pc, IND_SIZE);
        first_p += data->prog[i]->pc - 2;
        first_p = data->mem[first_p];
        data->prog[i]->pc += IND_SIZE;
    } else if (desc >= 128) {
        first_p = take_data(data, data->prog[i]->pc, DIR_SIZE);
        data->prog[i]->pc += DIR_SIZE;
    } else {
        first_p = take_data(data, data->prog[i]->pc, 1);
        data->prog[i]->pc += 1;
        if (first_p > 0 && first_p <= REG_NUMBER)
            first_p = data->prog[i]->reg[first_p - 1];
    }
    return (first_p);
}

static uint32_t define_sec_param(vm_data_t *data, int i, uint8_t desc
, int inst_adress)
{
    uint32_t sec_p = inst_adress;

    desc = desc % 64;
    if (desc >= 48) {
        sec_p = take_data(data, data->prog[i]->pc, IND_SIZE);
        sec_p = data->mem[sec_p];
        data->prog[i]->pc += IND_SIZE;
    } else if (desc >= 32) {
        sec_p = take_data(data, data->prog[i]->pc, DIR_SIZE);
        data->prog[i]->pc += DIR_SIZE;
    } else {
        sec_p = take_data(data, data->prog[i]->pc, 1);
        data->prog[i]->pc += 1;
        if (sec_p > 0 && sec_p <= REG_NUMBER)
            sec_p = data->prog[i]->reg[sec_p - 1];
    }
    return (sec_p);
}

static int32_t do_op(uint32_t first_p, uint32_t sec_p, uint8_t inst)
{
    if (inst == 6)
        return (first_p & sec_p);
    else if (inst == 7)
        return (first_p | sec_p);
    return (first_p ^ sec_p);
}

void fc_and_or_xor(vm_data_t *data, int i, uint8_t desc)
{
    uint8_t inst = take_data(data, data->prog[i]->pc - 2, 1);
    int inst_adress = data->prog[i]->pc - 2;
    uint32_t first_p = define_first_param(data, i, desc);
    uint32_t sec_p = define_sec_param(data, i, desc, inst_adress);
    int reg_nb = take_data(data, data->prog[i]->pc, 1);
    int32_t result = 0;

    data->prog[i]->pc += 1;
    result = do_op(first_p, sec_p, inst);
    data->prog[i]->carry = 0;
    if (reg_nb > 0 && reg_nb <=  REG_NUMBER) {
        data->prog[i]->reg[reg_nb - 1] = result;
        data->prog[i]->carry = (result == 0 ? 1 : 0);
    }
}