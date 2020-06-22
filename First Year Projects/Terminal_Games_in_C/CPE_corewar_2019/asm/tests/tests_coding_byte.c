/*
** EPITECH PROJECT, 2020
** TESTS_CODING_BYTE
** File description:
** Test coding_byte
*/

#include <criterion/criterion.h>
#include "my_str.h"
#include "asm.h"

Test(get_coding_byte, without_op_1)
{
    char **args = my_strtok("r2,23,%34", ',');
    char expected = 0b01111000;
    data_t data = EMPTY_DATA;
    char coding_byte = get_coding_byte(&data, args, -1);

    cr_assert_eq(coding_byte, expected);
    free_2d_str(args);
}

Test(get_coding_byte, without_op_2)
{
    char **args = my_strtok("23,-45,%34", ',');
    char expected = 0b11111000;
    data_t data = EMPTY_DATA;
    char coding_byte = get_coding_byte(&data, args, -1);

    cr_assert_eq(coding_byte, expected);
    free_2d_str(args);
}

Test(get_coding_byte, without_op_3)
{
    char **args = my_strtok("r1,r3,34", ',');
    char expected = 0b01011100;
    data_t data = EMPTY_DATA;
    char coding_byte = get_coding_byte(&data, args, -1);

    cr_assert_eq(coding_byte, expected);
    free_2d_str(args);
}

Test(get_coding_byte, valid_add_1)
{
    char **args = my_strtok("r6,r7,r7", ',');
    char expected = 0b01010100;
    data_t data = EMPTY_DATA;
    char coding_byte = get_coding_byte(&data, args, 3);

    cr_assert_eq(coding_byte, expected);
    free_2d_str(args);
}

Test(get_coding_byte, invalid_add_1)
{
    char **args = my_strtok("r6,20,r7", ',');
    char expected = '\0';
    data_t data = EMPTY_DATA;
    char coding_byte = get_coding_byte(&data, args, 3);

    cr_assert_eq(coding_byte, expected);
    free_2d_str(args);
}

Test(get_coding_byte, invalid_add_2)
{
    char **args = my_strtok("%6,r3,r7", ',');
    char expected = '\0';
    data_t data = EMPTY_DATA;
    char coding_byte = get_coding_byte(&data, args, 3);

    cr_assert_eq(coding_byte, expected);
    free_2d_str(args);
}

Test(get_coding_byte, invalid_add_3)
{
    char **args = my_strtok("r6,qsdqs,r7", ',');
    char expected = '\0';
    data_t data = EMPTY_DATA;
    char coding_byte = get_coding_byte(&data, args, 3);

    cr_assert_eq(coding_byte, expected);
    free_2d_str(args);
}

Test(get_coding_byte, valid_ldi_1)
{
    char **args = my_strtok("r6,r7,r7", ',');
    char expected = 0b01010100;
    data_t data = EMPTY_DATA;
    char coding_byte = get_coding_byte(&data, args, 9);

    cr_assert_eq(coding_byte, expected);
    free_2d_str(args);
}

Test(get_coding_byte, valid_ldi_2)
{
    char **args = my_strtok("r6,%7,r7", ',');
    char expected = 0b01100100;
    data_t data = EMPTY_DATA;
    char coding_byte = get_coding_byte(&data, args, 9);

    cr_assert_eq(coding_byte, expected);
    free_2d_str(args);
}

Test(get_coding_byte, valid_ldi_3)
{
    char **args = my_strtok("6,r7,r7", ',');
    char expected = 0b11010100;
    data_t data = EMPTY_DATA;
    char coding_byte = get_coding_byte(&data, args, 9);

    cr_assert_eq(coding_byte, expected);
    free_2d_str(args);
}

Test(get_coding_byte, invalid_ldi_1)
{
    char **args = my_strtok("r6,20,20", ',');
    char expected = '\0';
    data_t data = EMPTY_DATA;
    char coding_byte = get_coding_byte(&data, args, 9);

    cr_assert_eq(coding_byte, expected);
    free_2d_str(args);
}

Test(get_coding_byte, invalid_ldi_2)
{
    char **args = my_strtok("%20,20,%20", ',');
    char expected = '\0';
    data_t data = EMPTY_DATA;
    char coding_byte = get_coding_byte(&data, args, 9);

    cr_assert_eq(coding_byte, expected);
    free_2d_str(args);
}