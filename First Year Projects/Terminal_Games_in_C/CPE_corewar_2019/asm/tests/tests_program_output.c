/*
** EPITECH PROJECT, 2020
** TESTS_PROGRAM_OUTPUT
** File description:
** Test program_output
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my_print.h"
#include "asm.h"

static int get_data(char *path, char *data, int *size)
{
    int fd = open(path, O_RDONLY);

    if (fd == -1)
        return (EXIT_FAILURE);
    *size = read(fd, data, 20000);
    close(fd);
    if (*size == -1)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

static void test_program_output(char *output_path, char *expected_path)
{
    char output_data[20000];
    int output_size;
    char expected_data[20000];
    int expected_size;

    cr_assert_eq(get_data(output_path, output_data, &output_size), 0);
    cr_assert_eq(get_data(expected_path, expected_data, &expected_size), 0);
    cr_assert_eq(output_size, expected_size);
    for (int k = 0; k < output_size; k++) {
        if (output_data[k] != expected_data[k]) {
            my_putstr_error("[FAIL] ");
            my_putstr_error(output_path);
            my_putstr_error(" differt output at index ");
            my_put_nbr_error(k);
            my_putstr_error("\n");
        }
        cr_assert_eq(output_data[k], expected_data[k]);
    }
}

Test(asm_, abel)
{
    char *input_path = "tests/champions/valids/abel.s";
    char *output_path = "abel.cor";
    char *expected_path = "tests/champions/valids/expected/abel.cor";

    cr_assert_eq(parse_file(input_path), EXIT_SUCCESS);
    test_program_output(output_path, expected_path);
}

Test(asm_, bill)
{
    char *input_path = "tests/champions/valids/bill.s";
    char *output_path = "bill.cor";
    char *expected_path = "tests/champions/valids/expected/bill.cor";

    cr_assert_eq(parse_file(input_path), EXIT_SUCCESS);
    test_program_output(output_path, expected_path);
}

Test(asm_, pdd)
{
    char *input_path = "tests/champions/valids/pdd.s";
    char *output_path = "pdd.cor";
    char *expected_path = "tests/champions/valids/expected/pdd.cor";

    cr_assert_eq(parse_file(input_path), EXIT_SUCCESS);
    test_program_output(output_path, expected_path);
}

Test(asm_, tyron)
{
    char *input_path = "tests/champions/valids/tyron.s";
    char *output_path = "tyron.cor";
    char *expected_path = "tests/champions/valids/expected/tyron.cor";

    cr_assert_eq(parse_file(input_path), EXIT_SUCCESS);
    test_program_output(output_path, expected_path);
}

Test(asm_, all_instructions)
{
    char *input_path = "tests/champions/valids/all_instructions.s";
    char *output_path = "all_instructions.cor";
    char *expected_path = "tests/champions/valids/expected/" \
        "all_instructions.cor";

    cr_assert_eq(parse_file(input_path), EXIT_SUCCESS);
    test_program_output(output_path, expected_path);
}