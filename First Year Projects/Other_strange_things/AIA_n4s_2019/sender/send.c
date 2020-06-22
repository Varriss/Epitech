/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** send
*/

#include <stdio.h>
#include <string.h>
#include "ai.h"

int send(command_t *command)
{
    char buffer[255];

    if (!command || !command->command)
        return (FAILURE_CODE);
    if (command->value != FLOAT_EMPTY) {
        gcvt(command->value, FLOAT_DIGITS, buffer);
        my_printf("%s:%s\n", command->command, buffer);
    } else if ((command->value == FLOAT_EMPTY)
    && (command->cycles != INT_EMPTY)) {
        my_printf("%s:%d\n", command->command, command->cycles);
    } else
        my_printf("%s\n", command->command);
    return (SUCCESS_CODE);
}