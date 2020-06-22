/*
** EPITECH PROJECT, 2020
** TESTS_GET_STRING
** File description:
** Test get_string
*/

#include <criterion/criterion.h>
#include "asm.h"
#include "op.h"

Test(file_name, ok)
{
    char name[1000] = "t2";

    get_file_name(NULL);
    cr_assert_str_eq(name, "t2");
    get_file_name(name);
    cr_assert_str_eq(name, "");
    set_file_name("test");
    get_file_name(name);
    cr_assert_str_eq(name, "test");
    set_file_name(NULL);
    get_file_name(name);
    cr_assert_str_eq(name, "test");
    set_file_name("../new.cor");
    get_file_name(name);
    cr_assert_str_eq(name, "new.cor");
    set_file_name("//././assets/new.cor2");
    get_file_name(name);
    cr_assert_str_eq(name, "new.cor2");
}

Test(is_string_line, valid)
{
    cr_assert_eq(is_string_line(".name \"Bill\""), 1);
    cr_assert_eq(is_string_line("\"Bill\""), 1);
}

Test(is_string_line, invalid)
{
    cr_assert_eq(is_string_line("begin: ld  %76, r1"), 0);
    cr_assert_eq(is_string_line(".name Bill"), 0);
}

Test(get_string, null)
{
    cr_assert_null(get_string(NULL, ""));
    cr_assert_null(get_string("", NULL));
    cr_assert_null(get_string(NULL, NULL));
}

Test(get_string, ok_1)
{
    char *line = ".name \"Bill\"";
    char *name = ".name";
    char *expected = "Bill";
    char *string = get_string(line, name);

    cr_assert_not_null(string);
    cr_assert_str_eq(string, expected);
    free(string);
}

Test(get_string, ok_2)
{
    char *line = ".comment \"Just a basic pompes, traction program\"";
    char *name = COMMENT_CMD_STRING;
    char *expected = "Just a basic pompes, traction program";
    char *string = get_string(line, name);

    cr_assert_not_null(string);
    cr_assert_str_eq(string, expected);
    free(string);
}

Test(get_string, error_1)
{
    char *line = ".name Bill\"";
    char *name = ".name";
    char *string = get_string(line, name);

    cr_assert_null(string);
}

Test(get_string, error_2)
{
    char *line = ".name \"Bill";
    char *name = ".name";
    char *string = get_string(line, name);

    cr_assert_null(string);
}

Test(get_string, error_3)
{
    char *line = ".nme \"Bill\"";
    char *name = ".name";
    char *string = get_string(line, name);

    cr_assert_null(string);
}

Test(get_string, error_4)
{
    char *line = ".nme \"Bill\" f";
    char *name = ".name";
    char *string = get_string(line, name);

    cr_assert_null(string);
}

Test(get_string, error_5)
{
    char *line = "\"Bill\" f";
    char *name = "";
    char *string = get_string(line, name);

    cr_assert_null(string);
}

Test(get_string, error_6)
{
    char *line = ".name \"Bill\"\"Bill\"";
    char *name = ".name";
    char *string = get_string(line, name);

    cr_assert_null(string);
}

Test(get_string, error_7)
{
    char *line = ".name \"Bill\" \"Bill\"";
    char *name = ".name";
    char *string = get_string(line, name);

    cr_assert_null(string);
}