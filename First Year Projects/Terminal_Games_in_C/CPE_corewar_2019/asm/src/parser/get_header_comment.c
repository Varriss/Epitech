/*
** EPITECH PROJECT, 2020
** GET_HEADER_COMMENT
** File description:
** Get_header_comment function
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

static int add_header_comment_to_data(data_t *data, char *comment)
{
    compiled_data_t compiled = {NULL, BLOCK_COMMENT_LEN};

    if (my_strlen(comment) > MAX_COMMENT_LEN) {
        print_error(data->line_id, "The program comment is too long.");
        return (EXIT_FAILURE);
    }
    compiled.data = malloc(sizeof(char) * (compiled.len + 1));
    if (!compiled.data)
        return (EXIT_FAILURE);
    for (size_t k = 0; k <= compiled.len; k++)
        compiled.data[k] = '\0';
    for (size_t k = 0; comment[k]; k++)
        compiled.data[k + 8] = comment[k];
    return (append_compiled_data(&(data->compiled), compiled));
}

int add_header_comment(data_t *data, char *line)
{
    char *comment = NULL;

    if (!is_string_line(line)) {
        data->last_line = my_strclone(line);
        if (!data->last_line)
            return (EXIT_FAILURE);
        print_warning(data->line_id, "No comment specified.");
        return (EXIT_SUCCESS);
    }
    comment = get_string(line, COMMENT_CMD_STRING);
    if (!comment) {
        print_error(data->line_id, "An error with comment occured.");
        return (EXIT_FAILURE);
    }
    if (add_header_comment_to_data(data, comment)) {
        free(comment);
        return (EXIT_FAILURE);
    }
    free(comment);
    return (EXIT_SUCCESS);
}

int get_header_comment(int fd, data_t *data)
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
        rtn_value = add_header_comment(data, line);
        free(line);
        return (rtn_value);
    }
    print_warning(data->line_id, "No comment specified.");
    return (EXIT_SUCCESS);
}