/*
** EPITECH PROJECT, 2020
** create_reg
** File description:
** create_reg
*/

#include "corewar.h"
#include "op.h"
#include <stdlib.h>

int create_reg(vm_data_t *data)
{
    if (!data->prog)
        return (ERROR);
    for (int i = 0; data->prog[i]; i++) {
        data->prog[i]->cycle = 0;
        data->prog[i]->reg = malloc(sizeof(uint32_t) * REG_NUMBER);
        if (data->prog[i]->reg == NULL)
            return (ERROR);
        data->prog[i]->reg[0] = data->prog[i]->prog_nb;
        for (int k = 1; k < REG_NUMBER; k++)
            data->prog[i]->reg[k] = 0;
    }
    return (0);
}
