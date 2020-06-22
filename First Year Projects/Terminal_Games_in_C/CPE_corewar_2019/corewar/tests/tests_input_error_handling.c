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

Test(tests_error_input_handling, dump_arg_tests)
{
    vm_data_t data = {0};
    char *args[] = {"./corewar", "-dump", "¤", "-n", "1", "error_prog", 0};

    cr_assert_eq(input_handling(&data, args), ERROR);
}

Test(tests_error_input_handling, n_arg_tests)
{
    vm_data_t data = {0};
    char *args[] = {"./corewar", "-dump", "F1"
    , "-n", "L", "error_prog", 0};

    cr_assert_eq(input_handling(&data, args), ERROR);
}

Test(tests_error_input_handling, multi_same_n_prog_arg_tests)
{
    vm_data_t data = {0};
    char *args[] = {"./corewar", "-dump", "F1"
    , "-n", "1", "error_prog"
    , "-n", "1", "error_prog_two"
    , "-n", "1", "error_prog_three", 0};

    cr_assert_eq(input_handling(&data, args), ERROR);
}

Test(tests_error_input_handling, multi_same_name_prog_arg_tests)
{
    vm_data_t data = {0};
    char *args[] = {"./corewar", "-dump", "F1"
    , "-n", "1", "error_prog"
    , "-n", "2", "error_prog"
    , "-n", "3", "error_prog", 0};

    cr_assert_eq(input_handling(&data, args), ERROR);
}

Test(tests_error_input_handling, name_prog_arg_tests)
{
    vm_data_t data = {0};
    char *args[] = {"./corewar", "-dump", "F1"
    , "-n", "1", "-error_prog_name", 0};

    cr_assert_eq(input_handling(&data, args), ERROR);
}

Test(tests_error_input_handling, bad_flag_tests)
{
    vm_data_t data = {0};
    char *fake_flag[] = {"./corewar", "-bad_flag", 0};

    cr_assert_eq(input_handling(&data, fake_flag), ERROR);
}