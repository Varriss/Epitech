/*
** EPITECH PROJECT, 2020
** COMPILE_POST_LABEL
** File description:
** Compile_post_label function
*/

#include <stdlib.h>
#include <limits.h>
#include "list.h"
#include "my_str.h"
#include "my_str_is.h"
#include "my_math.h"
#include "asm.h"
#include "op.h"
#include "strings.h"

static int get_compiled_label(data_t *data, label_t *to_find, long long int *nb)
{
    label_t *label;

    for (int k = 0; k < list_get_size(data->labels); k++) {
        label = (label_t *)list_get(data->labels, k);
        if (label->to_find == 1)
            continue;
        if (my_strcmp(to_find->name, label->name) != 0)
            continue;
        *nb = label->pos;
        return (EXIT_SUCCESS);
    }
    return (EXIT_FAILURE);
}

static void label_fill_data(data_t *data, label_t *label, long long int nb)
{
    unsigned int pos;

    nb = nb - label->instruction_at + 1;
    pos = label->pos;
    if (label->is_long_size) {
        data->compiled.data[pos++] = nb / 256 / 256 / 256 % 256;
        data->compiled.data[pos++] = nb / 256 / 256 % 256;
    }
    data->compiled.data[pos++] = nb / 256 % 256;
    data->compiled.data[pos++] = nb % 256;
}

int compile_missed_labels(data_t *data)
{
    label_t *label;
    long long int nb = 0;

    if (!data->labels)
        return (EXIT_SUCCESS);
    for (int k = 0; k < list_get_size(data->labels); k++) {
        label = (label_t *)list_get(data->labels, k);
        if (label->to_find == 0)
            continue;
        if (get_compiled_label(data, label, &nb)) {
            print_error(label->line_id, "Undefined label.");
            return (EXIT_FAILURE);
        }
        label_fill_data(data, label, nb);
    }
    return (EXIT_SUCCESS);
}