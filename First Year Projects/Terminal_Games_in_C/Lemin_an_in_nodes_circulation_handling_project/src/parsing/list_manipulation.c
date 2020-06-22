/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** list_manipulation
*/

#include "stdlib.h"
#include "lemin.h"

void destroy_line_list(list_t *line_list)
{
    list_t *cursor = line_list->next;

    for (; cursor != line_list; cursor = cursor->next) {
        if (cursor->data->line->str) {
            free(cursor->data->line->str);
            free(cursor->data->line);
        }
    }
    delete_list(line_list);
}

char **convert_list_to_arr(list_t *line_list)
{
    char **res = NULL;
    int listlen = list_len(line_list);
    list_t *cursor = line_list->next;

    res = malloc(sizeof(char *) * (listlen + 1));
    res[listlen] = NULL;
    for (int i = 0; i < listlen; i++, cursor = cursor->next)
        res[i] = my_strdup(cursor->data->line->str);
    return (res);
}

void print_list(list_t *line_list)
{
    list_t *cursor = line_list->next;

    for (; cursor != line_list; cursor = cursor->next) {
        if (cursor->data->line)
            my_printf("%s\n", cursor->data->line->str);
    }
}