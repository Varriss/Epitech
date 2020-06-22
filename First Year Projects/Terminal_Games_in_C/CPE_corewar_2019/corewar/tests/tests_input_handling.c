/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** tests_input_handling
*/

#include "corewar.h"
#include "op.h"
#include "stddef.h"
#include <criterion/criterion.h>

Test(tests_input_handling, simple_everything_is_ok)
{
    vm_data_t data = {0};
    char *args[] = {"./corewar", "-dump", "F1"
    , "-n", "1", "prog_ok", 0};

    cr_assert_eq(input_handling(&data, args), 0);
    cr_assert_eq(data.nbr_cycle, 241);
    cr_assert_neq(data.mem, NULL);
    cr_assert_neq(data.prog, NULL);
}

Test(tests_input_handling, help_flag)
{
    vm_data_t data = {0};
    char *help_flag[] = {"./corewar", "-h", 0};

    cr_assert_eq(input_handling(&data, help_flag), 0);
}