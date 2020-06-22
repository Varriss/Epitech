/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** tests_parsers
*/

#include "ai.h"
#include "datatypes.h"
#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(parser_one, test_return_1)
{
    char *return_str = "1:OK:No errors so far:No further info";
    response_t *response = parser_one(return_str);

    cr_assert_eq(response->value_id, 1);
    cr_assert_str_eq(response->status, "OK");
    cr_assert_str_eq(response->code_str, "No errors so far");
    cr_assert_str_eq(response->add_infos, "No further info");
}

Test(parser_two, test_return_2)
{
    char *return_str = "1:OK:No errors so far:\
    700.0:750.0:800.0:850.0:900.0:975.0:1050.0:1125.0:1225.0:1375.0:1500.0:\
    2500.0:3000.0:3010.0:3010.0:3010.0:3010.0:3010.0:3010.0:3010.0:3000.0:\
    2750.0:2500.0:1500.0:1375.0:1225.0:1125.0:1125.0:1050.0:975.0:900.0:850.0:\
    No further info";
    response_t *response = parser_two(return_str);
    float distances[] = {700.0, 750.0, 800.0, 850.0, 900.0, 975.0, 1050.0,
    1125.0, 1225.0, 1375.0, 1500.0, 2500.0, 3000.0, 3010.0, 3010.0, 3010.0,
    3010.0, 3010.0, 3010.0, 3010.0, 3000.0, 2750.0, 2500.0, 1500.0, 1375.0,
    1225.0, 1125.0, 1125.0, 1050.0, 975.0, 900.0, 850.0, FLOAT_EMPTY};

    cr_assert_eq(response->value_id, 1);
    cr_assert_str_eq(response->status, "OK");
    cr_assert_str_eq(response->code_str, "No errors so far");
    for (int i = 0; response->distances[i] != FLOAT_EMPTY; i++)
        cr_assert_float_eq(response->distances[i], distances[i], 1);
    cr_assert_str_eq(response->add_infos, "No further info");
}

Test(parser_three, test_return_3)
{
    char *return_str = "1:OK:No errors so far:0.5:No further info";
    response_t *response = parser_three(return_str);

    cr_assert_eq(response->value_id, 1);
    cr_assert_str_eq(response->status, "OK");
    cr_assert_str_eq(response->code_str, "No errors so far");
    cr_assert_str_eq(response->add_infos, "No further info");
}

Test(parser_four, test_return_4)
{
    char *return_str =
    "1:OK:No errors so far:[23s,219978370ns]:No further info";
    response_t *response = parser_four(return_str);

    cr_assert_eq(response->value_id, 1);
    cr_assert_str_eq(response->status, "OK");
    cr_assert_str_eq(response->code_str, "No errors so far");
    cr_assert_eq(response->time.x, 23);
    cr_assert_eq(response->time.y, 219978370);
    cr_assert_str_eq(response->add_infos, "No further info");
}