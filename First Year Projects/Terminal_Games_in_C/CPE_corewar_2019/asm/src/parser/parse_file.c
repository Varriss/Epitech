/*
** EPITECH PROJECT, 2020
** PARSE_FILE
** File description:
** Parse_file function
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "list.h"
#include "get_next_line.h"
#include "my_file.h"
#include "my_str.h"
#include "my_print.h"
#include "asm.h"
#include "op.h"

static void add_file_size(data_t *data)
{
    int len;
    int pos = 0;

    if (data->compiled.len <= BLOCK_NAME_LEN + BLOCK_COMMENT_LEN)
        return;
    len = data->compiled.len - (BLOCK_NAME_LEN + BLOCK_COMMENT_LEN);
    while (len != 0) {
        data->compiled.data[LOC_PROGRAM_SIZE - pos] = len % 256;
        len /= 256;
        pos++;
    }
}

static int save_and_free(char const *output_path, data_t data)
{
    int rtn_val;

    if (compile_missed_labels(&data)) {
        data_destroy(data);
        return (EXIT_FAILURE);
    }
    add_file_size(&data);
    rtn_val = save_to_file(output_path, data.compiled.data, data.compiled.len);
    data_destroy(data);
    return (rtn_val);
}

static int compile_and_append(data_t *data, char const *line)
{
    compiled_data_t compiled = {NULL, 0};

    if (compile_line(data, &compiled, line))
        return (EXIT_FAILURE);
    return (append_compiled_data(&(data->compiled), compiled));
}

static int parse_file_loop(int fd, char const *output_path)
{
    char *line = NULL;
    data_t data = EMPTY_DATA;

    if (data_create(&data) || get_header(fd, &data))
        return (data_destroy_rtn_failure(data));
    line = data.last_line;
    while ((line = (line == NULL ? get_next_line(fd) : line)) != NULL) {
        data.line_id++;
        line = lexe_line(line);
        if (!line) {
            print_error(data.line_id, "An error occurred\n");
            return (data_destroy_rtn_failure(data));
        }
        if (line[0] && compile_and_append(&data, line)) {
            free(line);
            return (data_destroy_rtn_failure(data));
        }
        line = multi_free(1, line);
    }
    return (save_and_free(output_path, data));
}

int parse_file(char const *path)
{
    int fd = open(path, O_RDONLY);
    char *output_path = NULL;
    int rtn_value = 0;

    if (fd == -1) {
        my_putstr("Error in function open\n");
        return (84);
    }
    set_file_name(path);
    output_path = get_output_path(path);
    rtn_value = parse_file_loop(fd, output_path);
    close(fd);
    free(output_path);
    return (rtn_value ? 84 : 0);
}