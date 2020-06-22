/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** create_command
*/

#include "ai.h"

command_t *create_command(char *command, float value, int cycles)
{
    command_t *res = malloc(sizeof(command_t));

    res->command = command;
    res->value = value;
    res->cycles = cycles;
    return (res);
}