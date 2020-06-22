/*
** EPITECH PROJECT, 2020
** TESTS_GET_OUTPUT_PATH
** File description:
** Test get_output_path
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(get_output_path, null)
{
    cr_assert_null(get_output_path(NULL));
}

Test(get_output_path, valid_1)
{
    char *path = "dir/file.s";
    char *expected = "file.cor";
    char *output_path = get_output_path(path);

    cr_assert_not_null(output_path);
    cr_assert_str_eq(output_path, expected);
    free(output_path);
}

Test(get_output_path, valid_2)
{
    char *path = "dir/file.s.s";
    char *expected = "file.s.cor";
    char *output_path = get_output_path(path);

    cr_assert_not_null(output_path);
    cr_assert_str_eq(output_path, expected);
    free(output_path);
}

Test(get_output_path, valid_3)
{
    char *path = "dir/file";
    char *expected = "file.cor";
    char *output_path = get_output_path(path);

    cr_assert_not_null(output_path);
    cr_assert_str_eq(output_path, expected);
    free(output_path);
}

Test(get_output_path, valid_4)
{
    char *path = "dir/file.azerty";
    char *expected = "file.azerty.cor";
    char *output_path = get_output_path(path);

    cr_assert_not_null(output_path);
    cr_assert_str_eq(output_path, expected);
    free(output_path);
}

Test(get_output_path, valid_5)
{
    char *path = "file.azerty";
    char *expected = "file.azerty.cor";
    char *output_path = get_output_path(path);

    cr_assert_not_null(output_path);
    cr_assert_str_eq(output_path, expected);
    free(output_path);
}

Test(get_output_path, valid_6)
{
    char *path = "qscqsc/qscqs/c/qsc/qs/cqs///file.azerty";
    char *expected = "file.azerty.cor";
    char *output_path = get_output_path(path);

    cr_assert_not_null(output_path);
    cr_assert_str_eq(output_path, expected);
    free(output_path);
}

Test(get_output_path, valid_7)
{
    char *path = "./file.azerty";
    char *expected = "file.azerty.cor";
    char *output_path = get_output_path(path);

    cr_assert_not_null(output_path);
    cr_assert_str_eq(output_path, expected);
    free(output_path);
}

Test(get_output_path, valid_8)
{
    char *path = "file.s";
    char *expected = "file.cor";
    char *output_path = get_output_path(path);

    cr_assert_not_null(output_path);
    cr_assert_str_eq(output_path, expected);
    free(output_path);
}

Test(get_output_path, valid_9)
{
    char *path = ".s";
    char *expected = ".cor";
    char *output_path = get_output_path(path);

    cr_assert_not_null(output_path);
    cr_assert_str_eq(output_path, expected);
    free(output_path);
}

Test(get_output_path, valid_10)
{
    char *path = "./.s";
    char *expected = ".cor";
    char *output_path = get_output_path(path);

    cr_assert_not_null(output_path);
    cr_assert_str_eq(output_path, expected);
    free(output_path);
}