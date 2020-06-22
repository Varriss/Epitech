/*
** EPITECH PROJECT, 2020
** COREWAR
** File description:
** Corewar header
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include <stdint.h>

//////////////////////// VAR ////////////////////////

// const

#define UNUSED(x) (void)(x)
#define ERROR 84

// def struct

typedef struct vm_data_s vm_data_t;
typedef struct prog_s prog_t;
typedef struct inst_s inst_t;

// struct

struct vm_data_s
{
    int nbr_cycle;
    int cycle_actl;
    int cycle_to_die;
    int nbr_live;
    int nb_win;
    int *alive_prog;
    char *name_win;
    uint8_t *mem;
    prog_t **prog;
};

struct prog_s
{
    char *name;
    int origin;
    int prog_nb;
    uint32_t *reg;
    int pc;
    int carry;
    int cycle;
};
/*
struct inst_s
{
    uint8_t code;
    void (*f)(vm_data_t *, int, uint8_t);
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
    {1, &fc_live},
    {2, &fc_load},
    {3, &fc_store},
    {4, &fc_add_sub},
    {5, &fc_add_sub},
    {6, &fc_and_or_xor},
    {7, &fc_and_or_xor},
    {8, &fc_and_or_xor},
    {9, &fc_zjump},
    {10, &fc_load_index},
    {11, &fc_store_index},
    {12, &fc_fork},
    {13, &fc_long_load},
    {14, &fc_long_load_index},
    {15, &fc_long_fork},
    {16, &fc_display}
};
*/
///////////////////// PROTOTYPE /////////////////////

// input handling
int input_handling(vm_data_t *, char **);
int parse_programs(vm_data_t *, char **);
int create_reg(vm_data_t *);

// load files
int load_files(vm_data_t *);

// vm execution
void vm_loop(vm_data_t *);
int check_dead(vm_data_t *);
int32_t take_data(vm_data_t *, int , int);

// dump memory
void dump_memory(vm_data_t);

#endif /* !COREWAR_H_ */
