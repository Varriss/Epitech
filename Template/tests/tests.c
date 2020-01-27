/*
** EPITECH PROJECT, 2019
** Project_tests_model
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "../include/proj.h"

Test(test_group, test_name)
{
    cr_assert_eq(call_int_return(), equal);
    cr_assert_str_eq(call_str_return(), equal);
}