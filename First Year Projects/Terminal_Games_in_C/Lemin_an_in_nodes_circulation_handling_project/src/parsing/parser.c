/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** parsing
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lemin.h"

int format_line(char *line)
{
    if (my_strlen(line) <= 0)
        return (FAILURE_CODE);
    return (SUCCESS_CODE);
}

int add_line_to_list(list_t *line_list)
{
    list_data_t *line_elem = malloc(sizeof(list_data_t));

    line_elem->line = malloc(sizeof(line_t));
    line_elem->line->str = get_next_line(STDIN_FILENO);
    if (line_elem->line->str == NULL) {
        free(line_elem->line);
        free(line_elem);
        return (0);
    } else if (format_line(line_elem->line->str) != SUCCESS_CODE) {
        free(line_elem->line->str);
        free(line_elem->line);
        free(line_elem);
        return (0);
    }
    add_to_queue(line_list, line_elem);
    return (1);
}

void read_file(list_t *line_list)
{
    int reading = 1;

    while (reading)
        reading = add_line_to_list(line_list);
}

char **parser(void)
{
    char **file = NULL;
    list_t *line_list = create_list();

    read_file(line_list);
    file = convert_list_to_arr(line_list);
    destroy_line_list(line_list);
    return (file);
}