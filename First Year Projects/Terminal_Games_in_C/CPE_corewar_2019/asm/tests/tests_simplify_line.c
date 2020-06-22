/*
** EPITECH PROJECT, 2020
** TESTS_SIMPLIFY_LINE
** File description:
** Test simplify_line
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(simplify_line, null)
{
    cr_assert_null(simplify_line(NULL));
}

Test(simplify_line, just_spaces)
{
    char *line = "  \t   \t";
    char *expected = "";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}

Test(simplify_line, spaces_in_quotes)
{
    char *line = "  \"    \"  ";
    char *expected = "\"    \"";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}

Test(simplify_line, tabs_in_quotes)
{
    char *line = "  \" \t\t  \t \"  ";
    char *expected = "\" \t\t  \t \"";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}

Test(remove_comment, null)
{
    remove_comment(NULL);
}

Test(simplify_line, comment_in_quotes)
{
    char *line = ".name \" #comment \"";
    char *expected = ".name \" #comment \"";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}

Test(simplify_line, comment_1)
{
    char *line = "#comment";
    char *expected = "";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}

Test(simplify_line, comment_space)
{
    char *line = " #comment";
    char *expected = "";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}

Test(simplify_line, comment_2)
{
    char *line = "zjmp %:live#comment";
    char *expected = "zjmp %:live";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}

Test(simplify_line, comment_3)
{
    char *line = "zjmp %:live #comment";
    char *expected = "zjmp %:live";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}

Test(simplify_line, comment_4)
{
    char *line = "zjmp %:live # long long comment   ";
    char *expected = "zjmp %:live";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}

Test(simplify_line, ok)
{
    char *line = "zjmp %:live";
    char *expected = "zjmp %:live";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}

Test(simplify_line, only_tab)
{
    char *line = "zjmp\t\t \t%:live";
    char *expected = "zjmp %:live";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}

Test(simplify_line, spaces_1)
{
    char *line = "   zjmp     %:live   ";
    char *expected = "zjmp %:live";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}

Test(simplify_line, line_1)
{
    char *line = "    sti r1, %:live, %1";
    char *expected = "sti r1,%:live,%1";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}

Test(simplify_line, line_2)
{
    char *line = "    ld %100, r4 ";
    char *expected = "ld %100,r4";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}

Test(simplify_line, line_3)
{
    char *line = "ok:   \t";
    char *expected = "ok:";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}

Test(simplify_line, line_4)
{
    char *line = "  sti r5,    r4,r1  ";
    char *expected = "sti r5,r4,r1";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}

Test(simplify_line, line_5)
{
    char *line = "  sti r5  ,    r4   ,r1  ";
    char *expected = "sti r5,r4,r1";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}

Test(simplify_line, line_6)
{
    char *line = " live:   sti r1, %:live,%1";
    char *expected = "live: sti r1,%:live,%1";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}
/*
Test(simplify_line, line_7)
{
    char *line = " live:   sti r1  %:live %1";
    char *expected = "live: sti r1,%:live,%1";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}

Test(simplify_line, line_8)
{
    char *line = "  sti r5,,    r4, , ,,r1  ,";
    char *expected = "sti r5,r4,r1";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}

Test(simplify_line, line_9)
{
    char *line = "  sti r5 r4,,r1  , ";
    char *expected = "sti r5,r4,r1";
    char *simplified = simplify_line(line);

    cr_assert_not_null(simplified);
    cr_assert_str_eq(simplified, expected);
    free(simplified);
}*/