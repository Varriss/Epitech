/*
** EPITECH PROJECT, 2020
** DATA
** File description:
** Data function
*/

#include <stdlib.h>
#include "list.h"
#include "asm.h"

int data_create(data_t *data)
{
    data->labels = list_create((void (*)(void *))&label_destroy);
    if (!data->labels)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

void data_destroy(data_t data)
{
    if (data.labels)
        list_destroy(data.labels);
    if (data.compiled.data)
        free(data.compiled.data);
}

int data_destroy_rtn_failure(data_t data)
{
    if (data.labels)
        list_destroy(data.labels);
    if (data.compiled.data)
        free(data.compiled.data);
    return (EXIT_FAILURE);
}