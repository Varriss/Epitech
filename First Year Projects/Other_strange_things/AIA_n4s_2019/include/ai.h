/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** ai
*/

#ifndef AI_H_
#define AI_H_

////////////////////////////////////////////////////////////////////////////////
//                              INCLUDES                                      //
////////////////////////////////////////////////////////////////////////////////

#include "../lib/my/my.h"
#include "../lib/lists/lists.h"

#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
//                               DEFINES                                      //
////////////////////////////////////////////////////////////////////////////////
#define SUCCESS_CODE 0
#define FAILURE_CODE 84
#define NB_COMMANDS 12
#define READ_SIZE 1
#define FLOAT_EMPTY -2.0
#define INT_EMPTY -1
#define FLOAT_DIGITS 2
////////////////////////////////////////////////////////////////////////////////
//                               FUNCTIONS                                    //
////////////////////////////////////////////////////////////////////////////////
int ai(void);
int send(command_t *command);
command_t *create_command(char *command, float value, int cycles);
char *receive(void);
response_t *parser(char *input, char *command);
char *get_next_line(int fd);
response_t *parser_one(char *input);
response_t *parser_two(char *input);
response_t *parser_three(char *input);
response_t *parser_four(char *input);
void destroy_response(response_t *to_destroy);
float algo_one(float left, float mid, float right);
float algo_two(float left, float mid, float right);
float algo_three(float left, float mid, float right);
#endif /* !AI_H_ */