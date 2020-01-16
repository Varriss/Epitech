/*
** EPITECH PROJECT, 2019
** Errors_
** File description:
** tests_check_errors
*/

#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include "../include/proj.h"

Test(Test_group, test_name, .init = cr_redirect_stdout)
{
    cr_assert_stdout_eq_str("syntax error");
}