/*
** EPITECH PROJECT, 2020
** TESTS_COMPILE_ARGUMENT
** File description:
** Test compile_argument
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(compile_argument, valid_register_1)
{
    char *arg = "r1";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 1);
    cr_assert_eq(compiled.data[0], (char)0x01);
    free(compiled.data);
}

Test(compile_argument, valid_register_2)
{
    char *arg = "r16";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 1);
    cr_assert_eq(compiled.data[0], (char)0x10);
    free(compiled.data);
}

Test(compile_argument, invalid_register_number_1)
{
    char *arg = "r";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_FAILURE);
    free(compiled.data);
}

Test(compile_argument, invalid_register_number_2)
{
    char *arg = "re";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_FAILURE);
    free(compiled.data);
}

Test(compile_argument, invalid_register_number_3)
{
    char *arg = "r0";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_FAILURE);
    free(compiled.data);
}

Test(compile_argument, invalid_register_number_4)
{
    char *arg = "r17";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_FAILURE);
    free(compiled.data);
}

Test(compile_argument, valid_direct_1)
{
    char *arg = "%0";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 4);
    cr_assert_eq(compiled.data[0], (char)0x00);
    cr_assert_eq(compiled.data[1], (char)0x00);
    cr_assert_eq(compiled.data[2], (char)0x00);
    cr_assert_eq(compiled.data[3], (char)0x00);
    free(compiled.data);
}

Test(compile_argument, valid_direct_2)
{
    char *arg = "%1";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 4);
    cr_assert_eq(compiled.data[0], (char)0x00);
    cr_assert_eq(compiled.data[1], (char)0x00);
    cr_assert_eq(compiled.data[2], (char)0x00);
    cr_assert_eq(compiled.data[3], (char)0x01);
    free(compiled.data);
}

Test(compile_argument, valid_direct_3)
{
    char *arg = "%-1";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 4);
    cr_assert_eq(compiled.data[0], (char)0xff);
    cr_assert_eq(compiled.data[1], (char)0xff);
    cr_assert_eq(compiled.data[2], (char)0xff);
    cr_assert_eq(compiled.data[3], (char)0xff);
    free(compiled.data);
}

Test(compile_argument, valid_direct_4)
{
    char *arg = "%-1";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 4);
    cr_assert_eq(compiled.data[0], (char)0xff);
    cr_assert_eq(compiled.data[1], (char)0xff);
    cr_assert_eq(compiled.data[2], (char)0xff);
    cr_assert_eq(compiled.data[3], (char)0xff);
    free(compiled.data);
}

Test(compile_argument, valid_direct_5)
{
    char *arg = "%95626";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 4);
    cr_assert_eq(compiled.data[0], (char)0x00);
    cr_assert_eq(compiled.data[1], (char)0x01);
    cr_assert_eq(compiled.data[2], (char)0x75);
    cr_assert_eq(compiled.data[3], (char)0x8a);
    free(compiled.data);
}

Test(compile_argument, valid_direct_6)
{
    char *arg = "%4294967295";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 4);
    cr_assert_eq(compiled.data[0], (char)0xff);
    cr_assert_eq(compiled.data[1], (char)0xff);
    cr_assert_eq(compiled.data[2], (char)0xff);
    cr_assert_eq(compiled.data[3], (char)0xff);
    free(compiled.data);
}

Test(compile_argument, valid_direct_7)
{
    char *arg = "%-4294967295";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 4);
    cr_assert_eq(compiled.data[0], (char)0x00);
    cr_assert_eq(compiled.data[1], (char)0x00);
    cr_assert_eq(compiled.data[2], (char)0x00);
    cr_assert_eq(compiled.data[3], (char)0x01);
    free(compiled.data);
}

Test(compile_argument, valid_direct_8)
{
    char *arg = "%-42949672505095";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 4);
    cr_assert_eq(compiled.data[0], (char)0x00);
    cr_assert_eq(compiled.data[1], (char)0x06);
    cr_assert_eq(compiled.data[2], (char)0xf0);
    cr_assert_eq(compiled.data[3], (char)0xf9);
    free(compiled.data);
}

Test(compile_argument, valid_direct_just_sign_1)
{
    char *arg = "%+";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 4);
    cr_assert_eq(compiled.data[0], (char)0x00);
    cr_assert_eq(compiled.data[1], (char)0x00);
    cr_assert_eq(compiled.data[2], (char)0x00);
    cr_assert_eq(compiled.data[3], (char)0x00);
    free(compiled.data);
}

Test(compile_argument, valid_direct_just_sign_2)
{
    char *arg = "%-";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 4);
    cr_assert_eq(compiled.data[0], (char)0x00);
    cr_assert_eq(compiled.data[1], (char)0x00);
    cr_assert_eq(compiled.data[2], (char)0x00);
    cr_assert_eq(compiled.data[3], (char)0x00);
    free(compiled.data);
}

Test(compile_argument, invalid_direct_1)
{
    char *arg = "%545b";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_FAILURE);
    free(compiled.data);
}

Test(compile_argument, invalid_direct_2)
{
    char *arg = "%";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_FAILURE);
    free(compiled.data);
}

Test(compile_argument, valid_indirect_1)
{
    char *arg = "0";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 2);
    cr_assert_eq(compiled.data[0], (char)0x00);
    cr_assert_eq(compiled.data[1], (char)0x00);
    free(compiled.data);
}

Test(compile_argument, valid_indirect_2)
{
    char *arg = "64";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 2);
    cr_assert_eq(compiled.data[0], (char)0x00);
    cr_assert_eq(compiled.data[1], (char)0x40);
    free(compiled.data);
}

Test(compile_argument, valid_indirect_3)
{
    char *arg = "0064";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 2);
    cr_assert_eq(compiled.data[0], (char)0x00);
    cr_assert_eq(compiled.data[1], (char)0x40);
    free(compiled.data);
}

Test(compile_argument, valid_indirect_4)
{
    char *arg = "+0064";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 2);
    cr_assert_eq(compiled.data[0], (char)0x00);
    cr_assert_eq(compiled.data[1], (char)0x40);
    free(compiled.data);
}

Test(compile_argument, valid_indirect_5)
{
    char *arg = "-0";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 2);
    cr_assert_eq(compiled.data[0], (char)0x00);
    cr_assert_eq(compiled.data[1], (char)0x00);
    free(compiled.data);
}

Test(compile_argument, valid_indirect_6)
{
    char *arg = "-1";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 2);
    cr_assert_eq(compiled.data[0], (char)0xff);
    cr_assert_eq(compiled.data[1], (char)0xff);
    free(compiled.data);
}

Test(compile_argument, valid_indirect_7)
{
    char *arg = "65535";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 2);
    cr_assert_eq(compiled.data[0], (char)0xff);
    cr_assert_eq(compiled.data[1], (char)0xff);
    free(compiled.data);
}

Test(compile_argument, valid_indirect_8)
{
    char *arg = "65536";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 2);
    cr_assert_eq(compiled.data[0], (char)0x00);
    cr_assert_eq(compiled.data[1], (char)0x00);
    free(compiled.data);
}

Test(compile_argument, valid_indirect_9)
{
    char *arg = "8524896";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 2);
    cr_assert_eq(compiled.data[0], (char)0x14);
    cr_assert_eq(compiled.data[1], (char)0x60);
    free(compiled.data);
}

Test(compile_argument, valid_indirect_10)
{
    char *arg = "-510";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 2);
    cr_assert_eq(compiled.data[0], (char)0xfe);
    cr_assert_eq(compiled.data[1], (char)0x02);
    free(compiled.data);
}

Test(compile_argument, valid_indirect_11)
{
    char *arg = "4294967295895486";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 2);
    cr_assert_eq(compiled.data[0], (char)0x67);
    cr_assert_eq(compiled.data[1], (char)0xbe);
    free(compiled.data);
}

Test(compile_argument, valid_indirect_just_sign_1)
{
    char *arg = "+";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 2);
    cr_assert_eq(compiled.data[0], (char)0x00);
    cr_assert_eq(compiled.data[1], (char)0x00);
    free(compiled.data);
}

Test(compile_argument, valid_indirect_just_sign_2)
{
    char *arg = "-";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_SUCCESS);
    cr_assert_eq(compiled.len, 2);
    cr_assert_eq(compiled.data[0], (char)0x00);
    cr_assert_eq(compiled.data[1], (char)0x00);
    free(compiled.data);
}

Test(compile_argument, invalid_indirect_1)
{
    char *arg = "qsd";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_FAILURE);
    free(compiled.data);
}

Test(compile_argument, invalid_indirect_2)
{
    char *arg = "0x20";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_FAILURE);
    free(compiled.data);
}

Test(compile_argument, invalid_indirect_3)
{
    char *arg = "545b";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_FAILURE);
    free(compiled.data);
}

Test(compile_argument, invalid_indirect_4)
{
    char *arg = "-2s";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_FAILURE);
    free(compiled.data);
}

Test(compile_argument, invalid_indirect_5)
{
    char *arg = "--2";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_FAILURE);
    free(compiled.data);
}

Test(compile_argument, invalid_indirect_6)
{
    char *arg = "++2";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_FAILURE);
    free(compiled.data);
}

Test(compile_argument, invalid_indirect_7)
{
    char *arg = "+-2";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_FAILURE);
    free(compiled.data);
}

Test(compile_argument, invalid_indirect_8)
{
    char *arg = "-+2";
    compiled_data_t compiled = {malloc(sizeof(char) * 4), 0};
    data_t data = EMPTY_DATA;

    cr_assert_eq(compile_argument(&data, &compiled, arg, -1), EXIT_FAILURE);
    free(compiled.data);
}