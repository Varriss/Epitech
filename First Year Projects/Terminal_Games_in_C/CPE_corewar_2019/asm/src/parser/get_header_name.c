/*
** EPITECH PROJECT, 2020
** GET_HEADER_NAME
** File description:
** Get_header_name function
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "my_file.h"
#include "my_str.h"
#include "my_print.h"
#include "asm.h"
#include "op.h"

static char get_exec_magic(int k)
{
    int result = COREWAR_EXEC_MAGIC;

    for (int i = 0; i < 2 - k; i++)
        result /= 256;
    return (result % 256);
}

static int add_header_name_to_data(data_t *data, char *name)
{
    compiled_data_t compiled = {NULL, BLOCK_NAME_LEN};

    if (my_strlen(name) > MAX_NAME_LEN) {
        print_error(data->line_id, "The program name is too long.");
        return (EXIT_FAILURE);
    }
    compiled.data = malloc(sizeof(char) * (compiled.len + 1));
    if (!compiled.data)
        return (EXIT_FAILURE);
    for (size_t k = 0; k <= compiled.len; k++)
        compiled.data[k] = '\0';
    for (size_t k = 0; k < 3; k++)
        compiled.data[k + 1] = get_exec_magic(k);
    for (size_t k = 0; name[k]; k++)
        compiled.data[k + 4] = name[k];
    return (append_compiled_data(&(data->compiled), compiled));
}

int add_header_name(data_t *data, char *line)
{
    char *name = NULL;

    if (!is_string_line(line)) {
        print_error(data->line_id, "The name must be at begen.");
        return (EXIT_FAILURE);
    }
    name = get_string(line, NAME_CMD_STRING);
    if (!name) {
        print_error(data->line_id, "The name must be at begen.");
        return (EXIT_FAILURE);
    }
    if (add_header_name_to_data(data, name)) {
        free(name);
        return (EXIT_FAILURE);
    }
    free(name);
    return (EXIT_SUCCESS);
}

int get_header_name(int fd, data_t *data)
{
    char *line = NULL;
    int rtn_value;

    while ((line = lexe_line(get_next_line(fd))) != NULL) {
        if (!line) {
            print_error(data->line_id, "An error occurred.");
            return (EXIT_FAILURE);
        }
        data->line_id++;
        if (line[0] == '\0') {
            free(line);
            continue;
        }
        rtn_value = add_header_name(data, line);
        free(line);
        return (rtn_value);
    }
    print_empty_file();
    return (EXIT_FAILURE);
}