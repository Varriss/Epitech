/*
** EPITECH PROJECT, 2020
** TESTS_PARSE_FILE
** File description:
** Test parse_file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "asm.h"

void redirect(void);

Test(print_empty_file, output, .init=redirect)
{
    char *path = "tests/champions/invalids/empty_1.s";

    set_file_name(path);
    print_empty_file();
    cr_assert_stderr_eq_str("\033[1;37masm, empty_1.s: \033[1;36mThe "
        "file is empty.\n\033[0m[");
}

Test(print_no_comment, output, .init=redirect)
{
    char *path = "tests/champions/warnings/comment_after_name.s";

    set_file_name(path);
    print_warning(1, NO_COMMENT);
    cr_assert_stderr_eq_str("\033[1;37masm, comment_after_name.s, line 1: "
        "\033[1;31mWarning: \033[1;36mNo comment specified.\n\033[0m");
}

Test(print_syntax_error, output, .init=redirect)
{
    char *path = "tests/champions/invalids/syntax_error.s";

    set_file_name(path);
    print_error(1, SYNTAX_ERROR);
    cr_assert_stderr_eq_str("\033[1;37masm, syntax_error.s, "
        "line 1: \033[1;36mSyntax error.\n\033[0m");
}

Test(parse_file, invalid_comment_after_name, .init=redirect)
{
    char *path = "tests/champions/warnings/comment_after_name.s";

    cr_assert_eq(parse_file(path), 84);
    cr_assert_stderr_eq_str("\033[1;37masm, comment_after_name.s, line 1: "
        "\033[1;31mWarning: \033[1;36mNo comment specified.\n\033[0m");
}

Test(parse_file, invalid_empty_1, .init=redirect)
{
    char *path = "tests/champions/invalids/empty_1.s";

    cr_assert_eq(parse_file(path), 84);
    cr_assert_stderr_eq_str("\033[1;37masm, empty_1.s: \033[1;36mThe "
        "file is empty.\n\033[0m[");
}

Test(parse_file, invalid_empty_2, .init=redirect)
{
    char *path = "tests/champions/invalids/empty_2.s";

    cr_assert_eq(parse_file(path), 84);
    cr_assert_stderr_eq_str("\033[1;37masm, empty_2.s: \033[1;36mThe "
        "file is empty.\n\033[0m[");
}

Test(parse_file, not_exist)
{
    char *path = "tests/champions/unexist";

    cr_assert_eq(parse_file(path), 84);
}
/*
Test(parse_file, valid_0)
{
    char *path = "tests/champions/valids/abel.s";

    cr_assert_eq(parse_file(path), 0);
}

Test(parse_file, valid_1)
{
    char *path = "tests/champions/valids/bill.s";

    cr_assert_eq(parse_file(path), 0);
}

Test(parse_file, valid_2)
{
    char *path = "tests/champions/valids/pdd.s";

    cr_assert_eq(parse_file(path), 0);
}

Test(parse_file, valid_3)
{
    char *path = "tests/champions/valids/tyron.s";

    cr_assert_eq(parse_file(path), 0);
}

Test(parse_file, valid_4)
{
    char *path = "tests/champions/valids/name_com_space.s";

    cr_assert_eq(parse_file(path), 0);
}*/