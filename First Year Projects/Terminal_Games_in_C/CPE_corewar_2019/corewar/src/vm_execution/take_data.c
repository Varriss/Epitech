/*
** EPITECH PROJECT, 2020
** take_data
** File description:
** take_data
*/

#include "corewar.h"
#include "op.h"

static int32_t handle_neg_nb(int nb_bytes, int32_t nb)
{
    int64_t i = 256;

    for (int k = 1; k < nb_bytes; k++)
        i *= 256;
    if (nb < i / 2)
        return (nb);
    return (nb - i);
}

int32_t take_data(vm_data_t *data, int adress, int nb_bytes)
{
    int32_t nb = data->mem[adress + nb_bytes - 1];

    if (adress < 0)
        adress += MEM_SIZE;
    adress %= MEM_SIZE;
    for (int i = 1, k = 256; i < nb_bytes; i++, k *= 256)
        nb += data->mem[adress + nb_bytes - i - 1] * k;
    nb = handle_neg_nb(nb_bytes, nb);
    return (nb);
}
