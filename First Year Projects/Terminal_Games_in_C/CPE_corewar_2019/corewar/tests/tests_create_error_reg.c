/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** tests_create_teg
*/

#include "corewar.h"
#include "op.h"
#include "stddef.h"
#include <criterion/criterion.h>

Test(tests_errors_create_reg, null_data_handling)
{
    cr_assert_eq(create_reg(NULL), ERROR);
}

Test(tests_errors_create_reg, empty_data_handling)
{
    vm_data_t test_data = {0, NULL, NULL};

    cr_assert_eq(create_reg(&test_data), ERROR);
}