/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** parser_four
*/

#include "ai.h"

response_t *parser_four(char *input)
{
    response_t *response = malloc(sizeof(response_t));
    char **str_arr = my_str_to_word_array(input, ':');
    char *ptr;

    response->parser = 4;
    if (my_str_isnum(str_arr[1]))
        response->value_id = my_atoi(str_arr[0]);
    if (my_streq(str_arr[1], "OK") || my_streq(str_arr[1], "KO"))
        response->status = my_strdup(str_arr[1]);
    response->code_str = my_strdup(str_arr[2]);
    if (my_str_arr_len(str_arr) >= 5) {
        response->time.x = strtol(str_arr[3], &ptr, 10);
        response->time.y = strtol(str_arr[4], &ptr, 10);
    }
    response->distances = NULL;
    if (str_arr[5])
        response->add_infos = (my_strdup(str_arr[5]));
    free_my_str_arr(str_arr);
    return (response);
}