/*
** EPITECH PROJECT, 2020
** add_new_cycle
** File description:
** add_new_cycle
*/

#include "fc_list.h"
#include "op.h"

void add_new_cycle(vm_data_t *data, int i)
{
    uint8_t new_inst = take_data(data, data->prog[i]->pc, 1);

    for (int k = 0; k < 16; k++)
        if (new_inst == fc_list[k].code) {
            data->prog[i]->cycle += fc_list[k].cycle;
            return;
        }
}
