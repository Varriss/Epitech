/*
** EPITECH PROJECT, 2020
** COMPILE_LABEL
** File description:
** Compile_label function
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

int is_valid_label_name(char *name, int line_id)
{
    int valid_letter;

    if (!name[0]) {
        print_error(line_id, "Undefined label.");
        return (0);
    }
    for (int k = 0; name[k]; k++) {
        valid_letter = 0;
        for (int i = 0; LABEL_CHARS[i]; i++)
            if (name[k] == LABEL_CHARS[i]) {
                valid_letter = 1;
                break;
            }
        if (valid_letter == 0) {
            print_error(line_id, "Invalid label name.");
            return (0);
        }
    }
    return (1);
}

static int is_label_long_size(int op_id)
{
    int long_size = 1;

    for (int k = 0; op_id > 0 && op_id < NB_OP && k < NB_OP_SMALL_IND; k++)
        if (my_strcmp(op_tab[op_id].mnemonique, OP_SMALL_IND_SIZE[k]) == 0)
            long_size = 0;
    return (long_size);
}

static int get_label_value(data_t *data, long long int *nb, char *arg, int *tmp)
{
    label_t *label;

    if (!is_valid_label_name(&arg[2], data->line_id))
        return (EXIT_FAILURE);
    for (int k = 0; k < list_get_size(data->labels); k++) {
        label = (label_t *)list_get(data->labels, k);
        if (label->to_find == 0 && my_strcmp(&arg[2], label->name) == 0) {
            *nb = label->pos - data->compiled.len;
            return (EXIT_SUCCESS);
        }
    }
    label = label_create_to_find(&arg[2], tmp[0], data->line_id,
        is_label_long_size(tmp[1]));
    if (!label) {
        print_error(data->line_id, "An error occurred.");
        return (EXIT_FAILURE);
    }
    label->instruction_at = data->compiled.len + 1;
    list_add(data->labels, label);
    return (EXIT_SUCCESS);
}

int compile_direct_label_argument(data_t *data,
    compiled_data_t *compiled, char *arg, int op_id)
{
    long long int nb = 0;

    if (arg[0] != DIRECT_CHAR || arg[1] != LABEL_CHAR || !arg[2])
        return (EXIT_FAILURE);
    if (get_label_value(data, &nb, arg,
        (int []){(int)(data->compiled.len + compiled->len), op_id}))
        return (EXIT_FAILURE);
    if (nb < 0)
        nb = (long long int)UINT_MAX + 1 + nb;
    if (is_label_long_size(op_id)) {
        compiled->data[compiled->len++] = nb / 256 / 256 / 256;
        compiled->data[compiled->len++] = nb / 256 / 256 % 256;
    }
    compiled->data[compiled->len++] = nb / 256 % 256;
    compiled->data[compiled->len++] = nb % 256;
    return (EXIT_SUCCESS);
}

int add_label_to_data(data_t *data, char *arg)
{
    label_t *label;

    arg[my_strlen(arg) - 1] = '\0';
    if (!is_valid_label_name(arg, data->line_id))
        return (EXIT_FAILURE);
    if (!data->labels)
        return (EXIT_SUCCESS);
    for (int k = 0; k < list_get_size(data->labels); k++) {
        if (((label_t *)list_get(data->labels, k))->to_find == 1)
            continue;
        if (my_strcmp(arg, ((label_t *)list_get(data->labels, k))->name) == 0) {
            print_error(data->line_id, MULTI_LABEL_DEF);
            return (EXIT_FAILURE);
        }
    }
    label = label_create(arg, data->compiled.len);
    if (!label)
        return (EXIT_FAILURE);
    list_add(data->labels, label);
    return (EXIT_SUCCESS);
}