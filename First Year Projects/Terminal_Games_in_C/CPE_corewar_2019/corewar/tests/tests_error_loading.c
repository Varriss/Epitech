/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** tests_error_loading
*/

#include "corewar.h"
#include "op.h"
#include "stddef.h"
#include <criterion/criterion.h>

Test(tests_error_loading_champ, bad_prog_name)
{
    vm_data_t data = {0};
    char *args[] = {"./corewar", "-dump", "F1"
    , "-n", "1", "prog_ok", 0};

    data.mem = create_memory();
    if (!data.mem || input_handling(&data, args) == ERROR
    || create_reg(&data) == ERROR)
        cr_assert_eq(load_files(&data), ERROR);
}