/*
** EPITECH PROJECT, 2020
** COMPILE_LINE
** File description:
** Compile_line function
*/

#include <stdlib.h>
#include "my_str.h"
#include "asm.h"
#include "op.h"

static int compile_instruction(data_t *data, compiled_data_t *compiled,
    int op_id, char **args)
{
    char coding_byte = get_coding_byte(data, args, op_id);

    if (coding_byte == '\0')
        return (EXIT_FAILURE);
    compiled->data = malloc(sizeof(char) * (MAX_INSTRUCTION_LEN + 1));
    if (!compiled->data)
        return (EXIT_FAILURE);
    compiled->data[compiled->len++] = op_tab[op_id].code;
    if (op_id >= 0 && op_id <= NB_OP
        && !(op_tab[op_id].nbr_args == 1 && op_tab[op_id].type[0] == T_DIR))
        compiled->data[compiled->len++] = coding_byte;
    for (int arg_id = 0; args[arg_id]; arg_id++)
        if (compile_argument(data, compiled, args[arg_id], op_id)) {
            free(compiled->data);
            return (EXIT_FAILURE);
        }
    return (EXIT_SUCCESS);
}

static int post_compile_instruction(data_t *data, compiled_data_t *compiled,
    char **tokens_space, int op_id)
{
    char **args = my_strtok(tokens_space[1], SEPARATOR_CHAR);
    int rtn_value = 0;

    compiled->data = NULL;
    compiled->len = 0;
    if (!args || array_len((void **)args) != op_tab[op_id].nbr_args) {
        print_inv_nb_args(data->line_id, op_id, array_len((void **)args));
        free_2d_str(args);
        return (EXIT_FAILURE);
    }
    rtn_value = compile_instruction(data, compiled, op_id, args);
    free_2d_str(args);
    return (rtn_value);
}

static int compile_line_label(data_t *data, compiled_data_t *compiled,
    char **tokens)
{
    int start_label = 0;

    if (tokens[0][my_strlen(tokens[0]) - 1] == LABEL_CHAR) {
        if (add_label_to_data(data, tokens[0]))
            return (EXIT_FAILURE);
        start_label = 1;
        if (!tokens[start_label]) {
            return (EXIT_SUCCESS);
        }
    }
    for (int op_id = 0; op_id < NB_OP; op_id++)
        if (my_strcmp(tokens[start_label], op_tab[op_id].mnemonique) == 0)
            return (post_compile_instruction(data, compiled,
                &tokens[start_label], op_id));
    print_error(data->line_id, "Invalid instruction.");
    return (EXIT_FAILURE);
}

int compile_line(data_t *data, compiled_data_t *compiled, char const *line)
{
    char **tokens = my_strtok(line, ' ');
    int rtn_value = 0;

    if (!tokens || !tokens[0]) {
        free_2d_str(tokens);
        return (EXIT_FAILURE);
    }
    rtn_value = compile_line_label(data, compiled, tokens);
    free_2d_str(tokens);
    return (rtn_value);
}