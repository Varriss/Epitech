/*
** EPITECH PROJECT, 2020
** CODING_BYTE
** File description:
** Coding_byte function
*/

#include <stdlib.h>
#include "my_str.h"
#include "asm.h"
#include "op.h"
#include "strings.h"

static char get_arg_coding_byte(char *arg, int arg_id, int op_id)
{
    if (arg[0] == REGISTER_CHAR) {
        if (op_id == -1 || op_tab[op_id].type[arg_id] & T_REG)
            return (DESC_REG);
        return (0);
    }
    if (arg[0] == DIRECT_CHAR) {
        if (op_id == -1 || op_tab[op_id].type[arg_id] & T_DIR)
            return (DESC_DIR);
        return (0);
    }
    if ((arg[0] >= '0' && arg[0] <= '9') || arg[0] == '-') {
        if (op_id == -1 || op_tab[op_id].type[arg_id] & T_IND)
            return (DESC_IND);
        return (0);
    }
    return (0);
}

char get_coding_byte(data_t *data, char **args, int op_id)
{
    char coding_byte = '\0';
    char arg_coding_byte;

    for (int k = 0; args[k]; k++) {
        arg_coding_byte = get_arg_coding_byte(args[k], k, op_id);
        if (arg_coding_byte == '\0') {
            print_error(data->line_id, INVALID_ARGS);
            return ('\0');
        }
        coding_byte |= arg_coding_byte << (6 - k * 2);
    }
    return (coding_byte);
}