/*
** EPITECH PROJECT, 2020
** TESTS_COMPILER
** File description:
** Test compiler
*/

#include <criterion/criterion.h>
#include "my_str.h"
#include "asm.h"

Test(compile_line, invalid_instruction_1)
{
    char *line = lexe_line(my_strclone("not_exist r6, r7, r7"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_FAILURE);
    free(line);
}

Test(compile_line, invalid_instruction_2)
{
    char *line = lexe_line(my_strclone("add2 r6, r7, r7"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_FAILURE);
    free(line);
}

Test(compile_line, invalid_nb_args_1)
{
    char *line = lexe_line(my_strclone("add r6, r7, r7, r2"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_FAILURE);
    free(line);
}

Test(compile_line, invalid_nb_args_2)
{
    char *line = lexe_line(my_strclone("add r6, r7"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_FAILURE);
    free(line);
}

Test(compile_line, sub_1)
{
    char *expected = "\x04\x54\x06\x07\x07";
    int expected_size = 5;
    char *line = lexe_line(my_strclone("add r6, r7, r7"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_SUCCESS);
    cr_assert_not_null(compiled.data);
    cr_assert_eq(compiled.len, expected_size);
    for (int k = 0; k <= expected_size; k++)
        cr_assert_eq(compiled.data[k], expected[k]);
    free(compiled.data);
    free(line);
}

Test(compile_line, add_1)
{
    char *expected = "\x05\x54\x04\x05\x03";
    int expected_size = 5;
    char *line = lexe_line(my_strclone("sub r4, r5, r3"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_SUCCESS);
    cr_assert_not_null(compiled.data);
    cr_assert_eq(compiled.len, expected_size);
    for (int k = 0; k <= expected_size; k++)
        cr_assert_eq(compiled.data[k], expected[k]);
    free(compiled.data);
    free(line);
}

Test(compile_line, test_compile_1)
{
    char *expected = "\x02\x90\x00\x00\x00\x0f\x04";
    int expected_size = 7;
    char *line = lexe_line(my_strclone("ld  %15, r4"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_SUCCESS);
    cr_assert_not_null(compiled.data);
    cr_assert_eq(compiled.len, expected_size);
    for (int k = 0; k <= expected_size; k++)
        cr_assert_eq(compiled.data[k], expected[k]);
    free(compiled.data);
    free(line);
}

Test(compile_line, test_compile_2)
{
    char *expected = "\x03\x70\x08\x00\x64";
    int expected_size = 5;
    char *line = lexe_line(my_strclone("st  r8, 100"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_SUCCESS);
    cr_assert_not_null(compiled.data);
    cr_assert_eq(compiled.len, expected_size);
    for (int k = 0; k <= expected_size; k++)
        cr_assert_eq(compiled.data[k], expected[k]);
    free(compiled.data);
    free(line);
}

Test(compile_line, test_compile_3)
{
    char *expected = "\x10\x40\x01";
    int expected_size = 3;
    char *line = lexe_line(my_strclone("aff r1"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_SUCCESS);
    cr_assert_not_null(compiled.data);
    cr_assert_eq(compiled.len, expected_size);
    for (int k = 0; k <= expected_size; k++)
        cr_assert_eq(compiled.data[k], expected[k]);
    free(compiled.data);
    free(line);
}

Test(compile_line, test_compile_4)
{
    char *expected = "\x0b\x54\x07\x07\x01";
    int expected_size = 5;
    char *line = lexe_line(my_strclone("sti r7, r7, r1"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_SUCCESS);
    cr_assert_not_null(compiled.data);
    cr_assert_eq(compiled.len, expected_size);
    for (int k = 0; k <= expected_size; k++)
        cr_assert_eq(compiled.data[k], expected[k]);
    free(compiled.data);
    free(line);
}

Test(compile_line, test_compile_5)
{
    char *expected = "\x01\x00\x00\x00\x05";
    int expected_size = 5;
    char *line = lexe_line(my_strclone("live    %5"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_SUCCESS);
    cr_assert_not_null(compiled.data);
    cr_assert_eq(compiled.len, expected_size);
    for (int k = 0; k <= expected_size; k++)
        cr_assert_eq(compiled.data[k], expected[k]);
    free(compiled.data);
    free(line);
}

Test(compile_line, test_compile_6)
{
    char *expected = "\x0c\x01\xf4";
    int expected_size = 3;
    char *line = lexe_line(my_strclone("fork %500"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_SUCCESS);
    cr_assert_not_null(compiled.data);
    cr_assert_eq(compiled.len, expected_size);
    for (int k = 0; k <= expected_size; k++)
        cr_assert_eq(compiled.data[k], expected[k]);
    free(compiled.data);
    free(line);
}

Test(compile_line, test_compile_7)
{
    char *expected = "\x0f\xfe\x0c";
    int expected_size = 3;
    char *line = lexe_line(my_strclone("lfork %-500"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_SUCCESS);
    cr_assert_not_null(compiled.data);
    cr_assert_eq(compiled.len, expected_size);
    for (int k = 0; k <= expected_size; k++)
        cr_assert_eq(compiled.data[k], expected[k]);
    free(compiled.data);
    free(line);
}

Test(compile_line, test_compile_8)
{
    char *expected = "\x09\x01\x20";
    int expected_size = 3;
    char *line = lexe_line(my_strclone("zjmp %288"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_SUCCESS);
    cr_assert_not_null(compiled.data);
    cr_assert_eq(compiled.len, expected_size);
    for (int k = 0; k <= expected_size; k++)
        cr_assert_eq(compiled.data[k], expected[k]);
    free(compiled.data);
    free(line);
}

Test(compile_line, test_compile_9)
{
    char *expected = "\x0b\x68\x01\x00\x14\x00\x01";
    int expected_size = 7;
    char *line = lexe_line(my_strclone("sti r1, %20, %1"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_SUCCESS);
    cr_assert_not_null(compiled.data);
    cr_assert_eq(compiled.len, expected_size);
    for (int k = 0; k <= expected_size; k++)
        cr_assert_eq(compiled.data[k], expected[k]);
    free(compiled.data);
    free(line);
}

Test(compile_line, test_compile_10)
{
    char *expected = "\x0b\x68\x01\xff\xe5\xb5\xfc";
    int expected_size = 7;
    char *line = lexe_line(my_strclone("sti r1, %-27, %-84484"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_SUCCESS);
    cr_assert_not_null(compiled.data);
    cr_assert_eq(compiled.len, expected_size);
    for (int k = 0; k <= expected_size; k++)
        cr_assert_eq(compiled.data[k], expected[k]);
    free(compiled.data);
    free(line);
}

Test(compile_line, invalid_label_name_1)
{
    char *line = lexe_line(my_strclone("inv-id:"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_FAILURE);
    free(line);
}

Test(compile_line, invalid_label_name_2)
{
    char *line = lexe_line(my_strclone("inv++@-id: add r6, r7, r7"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_FAILURE);
    free(line);
}

Test(compile_line, invalid_label_name_3)
{
    char *line = lexe_line(my_strclone("fork %:inv-id"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_FAILURE);
    free(line);
}

Test(compile_line, invalid_label_name_4)
{
    char *line = lexe_line(my_strclone(":"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_FAILURE);
    free(line);
}

Test(compile_line, invalid_label_name_5)
{
    char *line = lexe_line(my_strclone("fork %:"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_FAILURE);
    free(line);
}

Test(compile_line, compile_label_without_data_1)
{
    char *expected = "\x0c\x00\x00";
    int expected_size = 3;
    char *line = lexe_line(my_strclone("fork %:ok"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_SUCCESS);
    cr_assert_not_null(compiled.data);
    cr_assert_eq(compiled.len, expected_size);
    for (int k = 0; k <= expected_size; k++)
        cr_assert_eq(compiled.data[k], expected[k]);
    free(compiled.data);
    free(line);
}

Test(compile_line, compile_label_without_data_2)
{
    char *expected = "\x0b\x68\x01\x00\x00\x00\x01";
    int expected_size = 7;
    char *line = lexe_line(my_strclone("sti r1, %:ok, %1"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_SUCCESS);
    cr_assert_not_null(compiled.data);
    cr_assert_eq(compiled.len, expected_size);
    for (int k = 0; k <= expected_size; k++)
        cr_assert_eq(compiled.data[k], expected[k]);
    free(compiled.data);
    free(line);
}

Test(compile_line, compile_label_without_data_3)
{
    char *expected = "\x02\x90\x00\x00\x00\x00\x08";
    int expected_size = 7;
    char *line = lexe_line(my_strclone("ld %:ok, r8"));
    compiled_data_t compiled;
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_line(&data, &compiled, line), EXIT_SUCCESS);
    cr_assert_not_null(compiled.data);
    cr_assert_eq(compiled.len, expected_size);
    for (int k = 0; k <= expected_size; k++)
        cr_assert_eq(compiled.data[k], expected[k]);
    free(compiled.data);
    free(line);
}