/*
** EPITECH PROJECT, 2020
** LABEL_CREATE
** File description:
** Label_create function
*/

#include <stdlib.h>
#include "list.h"
#include "my_str.h"
#include "asm.h"

label_t *label_create(char *name, int pos)
{
    label_t *label = malloc(sizeof(label_t));

    if (!label)
        return (NULL);
    label->to_find = 0;
    label->pos = pos;
    label->line_id = 0;
    label->is_long_size = 0;
    label->name = my_strclone(name);
    if (!label->name) {
        label_destroy(label);
        return (NULL);
    }
    return (label);
}

label_t *label_create_to_find(char *name, int pos,
    int line_id, int is_long_size)
{
    label_t *label = malloc(sizeof(label_t));

    if (!label)
        return (NULL);
    label->to_find = 1;
    label->pos = pos;
    label->line_id = line_id;
    label->is_long_size = is_long_size;
    label->name = my_strclone(name);
    if (!label->name) {
        label_destroy(label);
        return (NULL);
    }
    return (label);
}