/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** parser
*/

#include <stdio.h>
#include "ai.h"

static parser_function_t functions[NB_COMMANDS] = {
    {"START_SIMULATION", &parser_one},
    {"STOP_SIMULTION", &parser_one},
    {"CAR_FORWARD", &parser_one},
    {"CAR_BACKWARDS", &parser_one},
    {"WHEELS_DIR", &parser_one},
    {"GET_INFO_LIDAR", &parser_two},
    {"GET_CURRENT_SPEED", &parser_three},
    {"GET_CURRENT_WHEELS", &parser_three},
    {"CYCLE_WAIT", &parser_three},
    {"GET_CAR_SPEED_MAX", &parser_three},
    {"GET_CAR_SPEED_MIN", &parser_three},
    {"GET_INFO_SIMTIME", &parser_four}
};

response_t *parser(char *input, char *command)
{
    response_t *response = NULL;

    for (int i = 0; i < NB_COMMANDS; i++) {
        if (my_streq(command, functions[i].command)) {
            response = functions[i].function(input);
        }
    }
    free(input);
    return (response);
}