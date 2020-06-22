/*
** EPITECH PROJECT, 2020
** APPEND_COMPILED_DATA
** File description:
** Append_compiled_data function
*/

#include <stdlib.h>
#include "my_str.h"
#include "asm.h"

int append_compiled_data(compiled_data_t *data, compiled_data_t to_add)
{
    char *new_data = malloc(sizeof(char) * (data->len + to_add.len + 1));
    unsigned int k;

    if (!new_data)
        return (EXIT_FAILURE);
    for (k = 0; data->data && k < data->len; k++)
        new_data[k] = data->data[k];
    for (unsigned int i = 0; to_add.data && i < to_add.len; k++, i++)
        new_data[k] = to_add.data[i];
    new_data[k] = '\0';
    if (data->data)
        free(data->data);
    if (to_add.data)
        free(to_add.data);
    data->data = new_data;
    data->len += to_add.len;
    return (EXIT_SUCCESS);
}