/*
** EPITECH PROJECT, 2020
** MAIN
** File description:
** Main function
*/

#include "my_print.h"
#include "corewar.h"
#include "op.h"
#include <stdlib.h>

static uint8_t *create_memory(void)
{
    uint8_t *mem = malloc(sizeof(uint8_t) * MEM_SIZE);

    if (!mem)
        return (mem);
    for (int i = 0; i < MEM_SIZE; i++)
        mem[i] = 0;
    return (mem);
}

static void display_winner(vm_data_t data)
{
    my_putstr("The player ");
    my_put_nbr(data.nb_win);
    my_putstr(" (");
    my_putstr(data.name_win);
    my_putstr(") has won.\n");
}

int main(int argc, char **argv)
{
    vm_data_t data = {0};

    UNUSED(argc);
    data.cycle_to_die = CYCLE_TO_DIE;
    data.nbr_live = NBR_LIVE;
    data.mem = create_memory();
    if (!data.mem || input_handling(&data, argv) == ERROR
    || create_reg(&data) == ERROR)
        return (ERROR);
    if (load_files(&data) == ERROR)
        return (ERROR);
    vm_loop(&data);
    if (data.nbr_cycle != -1)
        dump_memory(data);
    if (data.name_win)
        display_winner(data);
    return (0);
}
