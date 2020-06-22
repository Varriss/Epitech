/*
** EPITECH PROJECT, 2020
** TESTS_PARSE_FILE
** File description:
** Test parse_file
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(parse_file, not_exist)
{
    char *path = "tests/champions/unexist";

    cr_assert_eq(parse_file(path), 84);
}

Test(parse_file, valid_1)
{
    char *path = "tests/champions/valids/abel.s";

    cr_assert_eq(parse_file(path), 0);
}

Test(parse_file, valid_2)
{
    char *path = "tests/champions/valids/bill.s";

    cr_assert_eq(parse_file(path), 0);
}

Test(parse_file, valid_3)
{
    char *path = "tests/champions/valids/pdd.s";

    cr_assert_eq(parse_file(path), 0);
}

Test(parse_file, valid_4)
{
    char *path = "tests/champions/valids/tyron.s";

    cr_assert_eq(parse_file(path), 0);
}

Test(parse_file, valid_5)
{
    char *path = "tests/champions/valids/name_com_space.s";

    cr_assert_eq(parse_file(path), 0);
}

Test(parse_file, invalid_1)
{
    char *path = "tests/champions/invalids/empty_1.s";

    cr_assert_eq(parse_file(path), 84);
}

Test(parse_file, invalid_2)
{
    char *path = "tests/champions/invalids/empty_2.s";

    cr_assert_eq(parse_file(path), 84);
}

Test(parse_file, invalid_3)
{
    char *path = "tests/champions/invalids/comment_not_after_name.s";

    cr_assert_eq(parse_file(path), 84);
}

Test(parse_file, invalid_4)
{
    char *path = "tests/champions/invalids/invalid_instruction.s";

    cr_assert_eq(parse_file(path), 84);
}

Test(parse_file, invalid_5)
{
    char *path = "tests/champions/invalids/syntax_error.s";

    cr_assert_eq(parse_file(path), 84);
}

Test(parse_file, invalid_6)
{
    char *path = "tests/champions/invalids/unexist_label.s";

    cr_assert_eq(parse_file(path), 84);
}

Test(parse_file, invalid_7)
{
    char *path = "tests/champions/invalids/double_label.s";

    cr_assert_eq(parse_file(path), 84);
}

Test(parse_file, invalid_8)
{
    char *path = "tests/champions/invalids/2_coms.s";

    cr_assert_eq(parse_file(path), 84);
}

Test(parse_file, invalid_9)
{
    char *path = "tests/champions/invalids/2_names.s";

    cr_assert_eq(parse_file(path), 84);
}