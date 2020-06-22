/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** parser_two
*/

#include <stdlib.h>
#include "ai.h"

// start and end included
float *convert_to_float_arr(char **str, int start, int size)
{
    float *res = malloc(sizeof(float) * (size + 1));

    res[size] = FLOAT_EMPTY;
    for (int i = 0; i < size; i++)
        res[i] = strtof(str[start + i], NULL);
    return (res);
}

response_t *parser_two(char *input)
{
    response_t *response = malloc(sizeof(response_t));
    char **str_arr = my_str_to_word_array(input, ':');

    response->parser = 2;
    if (my_str_isnum(str_arr[1]))
        response->value_id = my_atoi(str_arr[0]);
    if (my_streq(str_arr[1], "OK") || my_streq(str_arr[1], "KO"))
        response->status = my_strdup(str_arr[1]);
    response->code_str = my_strdup(str_arr[2]);
    if (my_str_arr_len(str_arr) >= 35)
        response->distances = convert_to_float_arr(str_arr, 3, 32);
    if (my_str_arr_len(str_arr) == 37)
        response->add_infos = my_strcat(my_strdup(str_arr[35]),
        my_strdup(str_arr[36]));
    else if (my_streq(str_arr[35], "No further info\n"))
        response->add_infos = (my_strdup(str_arr[35]));
    free_my_str_arr(str_arr);
    return (response);
}