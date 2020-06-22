/*
** EPITECH PROJECT, 2020
** COMPILE_ARGUMENT
** File description:
** Compile_argument function
*/

#include <stdlib.h>
#include <limits.h>
#include "my_str.h"
#include "my_str_is.h"
#include "my_math.h"
#include "asm.h"
#include "op.h"

static int compile_register_argument(compiled_data_t *compiled, char *arg)
{
    int nb;

    if (!my_str_isint(&arg[1]))
        return (EXIT_FAILURE);
    nb = my_get_nbr(&arg[1]);
    if (nb < 1 || nb > REG_NUMBER)
        return (EXIT_FAILURE);
    compiled->data[compiled->len++] = nb;
    return (EXIT_SUCCESS);
}

static void compile_direct_argument_long_size(compiled_data_t *compiled,
    long long int nb, int op_id)
{
    int long_size = 1;

    for (int k = 0; op_id > 0 && op_id < NB_OP && k < NB_OP_SMALL_IND; k++)
        if (my_strcmp(op_tab[op_id].mnemonique, OP_SMALL_IND_SIZE[k]) == 0)
            long_size = 0;
    if (long_size) {
        compiled->data[compiled->len++] = nb / 256 / 256 / 256;
        compiled->data[compiled->len++] = nb / 256 / 256 % 256;
    }
}

static int compile_direct_argument(data_t *data,
    compiled_data_t *compiled, char *arg, int op_id)
{
    long long int nb;

    if (!arg[1])
        return (EXIT_FAILURE);
    if (arg[1] == LABEL_CHAR)
        return (compile_direct_label_argument(data, compiled, arg, op_id));
    if (!my_str_isllint(&arg[1]))
        return (EXIT_FAILURE);
    nb = my_get_llint(&arg[1]) % ((long long int)UINT_MAX + 1);
    if (nb < 0)
        nb = (long long int)UINT_MAX + 1 + nb;
    compile_direct_argument_long_size(compiled, nb, op_id);
    compiled->data[compiled->len++] = nb / 256 % 256;
    compiled->data[compiled->len++] = nb % 256;
    return (EXIT_SUCCESS);
}

static int compile_indirect_argument(compiled_data_t *compiled, char *arg)
{
    long long int nb;

    if (!my_str_isllint(arg))
        return (EXIT_FAILURE);
    nb = my_get_llint(arg) % (USHRT_MAX + 1);
    if (nb < 0)
        nb = (USHRT_MAX + 1) + nb;
    compiled->data[compiled->len++] = nb / 256;
    compiled->data[compiled->len++] = nb % 256;
    return (EXIT_SUCCESS);
}

int compile_argument(data_t *data, compiled_data_t *compiled,
    char *arg, int op_id)
{
    int rtn_value;

    if (arg[0] == REGISTER_CHAR) {
        rtn_value = compile_register_argument(compiled, arg);
        if (rtn_value)
            print_error(data->line_id, "Invalid register number.");
        return (rtn_value);
    }
    if (arg[0] == DIRECT_CHAR)
        return (compile_direct_argument(data, compiled, arg, op_id));
    return (compile_indirect_argument(compiled, arg));
}