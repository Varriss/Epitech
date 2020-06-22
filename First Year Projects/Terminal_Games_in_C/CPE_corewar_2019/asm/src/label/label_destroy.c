/*
** EPITECH PROJECT, 2020
** LABEL_DESTROY
** File description:
** Label_destroy function
*/

#include <stdlib.h>
#include "asm.h"

void label_destroy(label_t *label)
{
    if (!label)
        return;
    if (label->name)
        free(label->name);
    free(label);
}