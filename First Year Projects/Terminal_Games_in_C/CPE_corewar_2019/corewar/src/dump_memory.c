/*
** EPITECH PROJECT, 2020
** dump_memory
** File description:
** dump_memory
*/

#include "corewar.h"
#include "op.h"
#include "my_print.h"

static void dump_one_line(vm_data_t data, int i)
{
    char hex[16] = "0123456789ABCDEF";
    int nb = 0;
    int pad = 0;

    for (int k = i; k != 0; k /= 16, pad += 1)
        my_putchar(hex[k % 16]);
    if (i < 16) {
        my_putchar(hex[i % 16]);
        pad += 1;
    }
    for (int k = 5; k > pad; k--)
        my_putchar(' ');
    my_putstr(":");
    for (int k = 0; k < 32 && k + i < MEM_SIZE; k++) {
        my_putchar(' ');
        nb = data.mem[i + k];
        my_putchar(hex[nb / 16]);
        my_putchar(hex[nb % 16]);
    }
    my_putchar('\n');
}

void dump_memory(vm_data_t data)
{
    for (int i = 0; i < MEM_SIZE; i += 32)
        dump_one_line(data, i);
}
