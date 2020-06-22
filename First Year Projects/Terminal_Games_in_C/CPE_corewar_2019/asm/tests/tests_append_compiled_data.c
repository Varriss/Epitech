/*
** EPITECH PROJECT, 2020
** TESTS_APPEND_COMPILED_DATA
** File description:
** Test append_compiled_data
*/

#include <criterion/criterion.h>
#include "my_str.h"
#include "asm.h"

Test(append_compiled_data, null_null)
{
    compiled_data_t data = {NULL, 0};
    compiled_data_t to_add = {NULL, 0};

    cr_assert_eq(append_compiled_data(&data, to_add), EXIT_SUCCESS);
    cr_assert_not_null(data.data);
    cr_assert_str_eq(data.data, "");
    cr_assert_eq(data.len, 0);
    free(data.data);
}

Test(append_compiled_data, ok_null)
{
    compiled_data_t data = {my_strclone("ok"), 2};
    compiled_data_t to_add = {NULL, 0};

    cr_assert_eq(append_compiled_data(&data, to_add), EXIT_SUCCESS);
    cr_assert_not_null(data.data);
    cr_assert_str_eq(data.data, "ok");
    cr_assert_eq(data.len, 2);
    free(data.data);
}

Test(append_compiled_data, null_ok)
{
    compiled_data_t data = {NULL, 0};
    compiled_data_t to_add = {my_strclone("ok"), 2};

    cr_assert_eq(append_compiled_data(&data, to_add), EXIT_SUCCESS);
    cr_assert_not_null(data.data);
    cr_assert_str_eq(data.data, "ok");
    cr_assert_eq(data.len, 2);
    free(data.data);
}

Test(append_compiled_data, ok_1)
{
    compiled_data_t data = {my_strclone("ok1"), 3};
    compiled_data_t to_add = {my_strclone("ok2"), 3};

    cr_assert_eq(append_compiled_data(&data, to_add), EXIT_SUCCESS);
    cr_assert_not_null(data.data);
    cr_assert_str_eq(data.data, "ok1ok2");
    cr_assert_eq(data.len, 6);
    free(data.data);
}

Test(append_compiled_data, ok_2)
{
    compiled_data_t data = {my_strclone(""), 0};
    compiled_data_t to_add = {my_strclone(""), 0};

    cr_assert_eq(append_compiled_data(&data, to_add), EXIT_SUCCESS);
    cr_assert_not_null(data.data);
    cr_assert_str_eq(data.data, "");
    cr_assert_eq(data.len, 0);
    free(data.data);
}

Test(append_compiled_data, ok_3)
{
    compiled_data_t data = {my_strclone("nothing"), 0};
    compiled_data_t to_add = {my_strclone("error"), 0};

    cr_assert_eq(append_compiled_data(&data, to_add), EXIT_SUCCESS);
    cr_assert_not_null(data.data);
    cr_assert_str_eq(data.data, "");
    cr_assert_eq(data.len, 0);
    free(data.data);
}

Test(append_compiled_data, null_bytes)
{
    char *expected = "ok\0\0 1\0\0\0\0 2";
    compiled_data_t data = {NULL, 6};
    compiled_data_t to_add = {NULL, 6};

    data.data = malloc(sizeof(char) * 7);
    for (int k = 0; k < 7; k++)
        data.data[k] = "ok\0\0 1"[k];
    to_add.data = malloc(sizeof(char) * 7);
    for (int k = 0; k < 7; k++)
        to_add.data[k] = "\0\0\0\0 2"[k];
    cr_assert_eq(append_compiled_data(&data, to_add), EXIT_SUCCESS);
    cr_assert_not_null(data.data);
    for (int k = 0; k < 12; k++)
        cr_assert_eq((int)data.data[k], (int)expected[k]);
    cr_assert_eq(data.len, 12);
    free(data.data);
}