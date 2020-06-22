/*
** EPITECH PROJECT, 2020
** fc_list
** File description:
** fc_list
*/

#ifndef FC_LIST_H
#define FC_LIST_H

#include "corewar.h"

struct inst_s
{
    uint8_t code;
    void (*f)(vm_data_t *, int, uint8_t);
    int cycle;
};

void fc_live(vm_data_t *, int, uint8_t);
void fc_load(vm_data_t *, int, uint8_t);
void fc_store(vm_data_t *, int, uint8_t);
void fc_add_sub(vm_data_t *, int, uint8_t);
void fc_and_or_xor(vm_data_t *, int, uint8_t);
void fc_zjump(vm_data_t *, int, uint8_t);
void fc_load_index(vm_data_t *, int, uint8_t);
void fc_store_index(vm_data_t *, int, uint8_t);
void fc_fork(vm_data_t *, int, uint8_t);
void fc_long_load(vm_data_t *, int, uint8_t);
void fc_long_load_index(vm_data_t *, int, uint8_t);
void fc_long_fork(vm_data_t *, int, uint8_t);
void fc_display(vm_data_t *, int, uint8_t);

static inst_t fc_list[16] = {
    {1, &fc_live, 10},
    {2, &fc_load, 5},
    {3, &fc_store, 5},
    {4, &fc_add_sub, 10},
    {5, &fc_add_sub, 10},
    {6, &fc_and_or_xor, 6},
    {7, &fc_and_or_xor, 6},
    {8, &fc_and_or_xor, 6},
    {9, &fc_zjump, 20},
    {10, &fc_load_index, 25},
    {11, &fc_store_index, 25},
    {12, &fc_fork, 800},
    {13, &fc_long_load, 10},
    {14, &fc_long_load_index, 50},
    {15, &fc_long_fork, 1000},
    {16, &fc_display, 2}
};

void add_new_cycle(vm_data_t *, int);

#endif
