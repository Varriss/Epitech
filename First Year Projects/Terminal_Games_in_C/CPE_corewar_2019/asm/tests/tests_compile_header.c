/*
** EPITECH PROJECT, 2020
** TESTS_COMPILE_HEADER
** File description:
** Test compile_header
*/

#include <criterion/criterion.h>
#include "my_str.h"
#include "asm.h"
#include "op.h"

Test(add_header_name, not_string_insctuction)
{
    char *line = lexe_line(my_strclone("add r1, r2, r3"));
    data_t data = EMPTY_DATA;

    cr_assert_eq(add_header_name(&data, line), EXIT_FAILURE);
    free(line);
}

Test(add_header_name, invalid_string_instruction)
{
    char *line = lexe_line(my_strclone(".name name"));
    data_t data = EMPTY_DATA;

    cr_assert_eq(add_header_name(&data, line), EXIT_FAILURE);
    free(line);
}

Test(add_header_name, invalid_string_name)
{
    char *line = lexe_line(my_strclone(".nam \"Abel\""));
    data_t data = EMPTY_DATA;

    cr_assert_eq(add_header_name(&data, line), EXIT_FAILURE);
    free(line);
}

Test(add_header_name, valid_empty)
{
    char *line = lexe_line(my_strclone(".name \"\""));
    char *expected = "\x00\xea\x83\xf3\x00\x00\x00\x00\x00\x00";
    int len_expected = 4 + MAX_NAME_LEN;
    data_t data = EMPTY_DATA;

    cr_assert_eq(add_header_name(&data, line), EXIT_SUCCESS);
    cr_assert_not_null(data.compiled.data);
    cr_assert_eq(data.compiled.len, len_expected);
    for (int k = 0; k < 10; k++)
        cr_assert_eq(data.compiled.data[k], expected[k]);
    for (int k = 10; k <= len_expected; k++)
        cr_assert_eq(data.compiled.data[k], 0);
    free(data.compiled.data);
    free(line);
}

Test(add_header_name, valid_name)
{
    char *line = lexe_line(my_strclone(".name \"Abel\""));
    char *expected = "\x00\xea\x83\xf3\x41\x62\x65\x6c\x00\x00";
    int len_expected = 4 + MAX_NAME_LEN;
    data_t data = EMPTY_DATA;

    cr_assert_eq(add_header_name(&data, line), EXIT_SUCCESS);
    cr_assert_not_null(data.compiled.data);
    cr_assert_eq(data.compiled.len, len_expected);
    for (int k = 0; k < 10; k++)
        cr_assert_eq(data.compiled.data[k], expected[k]);
    for (int k = 10; k <= len_expected; k++)
        cr_assert_eq(data.compiled.data[k], 0);
    free(data.compiled.data);
    free(line);
}

Test(add_header_name, invalid_too_long_name_129)
{
    char *line = lexe_line(my_strclone(".name \"aaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\""));
    data_t data = EMPTY_DATA;

    cr_assert_eq(add_header_name(&data, line), EXIT_FAILURE);
    free(line);
}

Test(add_header_name, valid_too_long_name_128)
{
    char *line = lexe_line(my_strclone(".name \"aaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\""));
    data_t data = EMPTY_DATA;

    cr_assert_eq(add_header_name(&data, line), EXIT_SUCCESS);
    free(line);
    free(data.compiled.data);
}

Test(add_header_comment, not_string_insctuction)
{
    char *line = lexe_line(my_strclone("add r1, r2, r3"));
    data_t data = EMPTY_DATA;

    cr_assert_eq(add_header_comment(&data, line), EXIT_SUCCESS);
    cr_assert_not_null(data.last_line);
    cr_assert_str_eq(data.last_line, line);
    free(data.last_line);
    free(line);
}

Test(add_header_comment, invalid_string_name)
{
    char *line = lexe_line(my_strclone(".random \"comment\""));
    data_t data = EMPTY_DATA;

    cr_assert_eq(add_header_comment(&data, line), EXIT_FAILURE);
    free(line);
}


Test(add_header_comment, valid_empty)
{
    char *line = lexe_line(my_strclone(".comment \"\""));
    int len_expected = 8 + MAX_COMMENT_LEN + 4;
    data_t data = EMPTY_DATA;

    cr_assert_eq(add_header_comment(&data, line), EXIT_SUCCESS);
    cr_assert_not_null(data.compiled.data);
    cr_assert_eq(data.compiled.len, len_expected);
    for (int k = 0; k <= len_expected; k++)
        cr_assert_eq(data.compiled.data[k], 0);
    free(data.compiled.data);
    free(line);
}

Test(add_header_comment, valid_name)
{
    char *line = lexe_line(my_strclone(".comment \"L'amer noir.\""));
    char *expected = "\x00\x00\x00\x00\x00\x00\x00\x00L'amer noir.\x00";
    int len_expected = 8 + MAX_COMMENT_LEN + 4;
    data_t data = EMPTY_DATA;

    cr_assert_eq(add_header_comment(&data, line), EXIT_SUCCESS);
    cr_assert_not_null(data.compiled.data);
    cr_assert_eq(data.compiled.len, len_expected);
    for (int k = 0; k < 20; k++)
        cr_assert_eq(data.compiled.data[k], expected[k]);
    for (int k = 20; k <= len_expected; k++)
        cr_assert_eq(data.compiled.data[k], 0);
    free(data.compiled.data);
    free(line);
}
