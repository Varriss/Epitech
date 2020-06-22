/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** parser_two
*/

#include "ai.h"

response_t *parser_one(char *input)
{
    response_t *response = malloc(sizeof(response_t));
    char **str_arr = my_str_to_word_array(input, ':');

    response->parser = 1;
    if (my_str_isnum(str_arr[1]))
        response->value_id = my_atoi(str_arr[0]);
    if (my_streq(str_arr[1], "OK") || my_streq(str_arr[1], "KO"))
        response->status = my_strdup(str_arr[1]);
    response->code_str = my_strdup(str_arr[2]);
    response->distances = NULL;
    if (str_arr[3])
        response->add_infos = (my_strdup(str_arr[3]));
    free_my_str_arr(str_arr);
    return (response);
}