/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** datatypes
*/

#ifndef DATATYPES_H_
#define DATATYPES_H_

////////////////////////////////////////////////////////////////////////////////
//                              Previous Declarations                         //
////////////////////////////////////////////////////////////////////////////////
#include "datatypes.h"

////////////////////////////////////////////////////////////////////////////////
//                         Linked list Datastructure                          //
////////////////////////////////////////////////////////////////////////////////

typedef struct longvect
{
    long x;
    long y;
} longvect_t;

typedef struct command
{
    char *command;
    float value;
    int cycles;
} command_t;

typedef struct response
{
    int parser;
    int value_id;
    char *status;
    char *code_str;
    char *add_infos;
    float *distances;
    longvect_t time;
} response_t;

typedef struct parser_function
{
    char *command;
    response_t *(*function)(char *input);
} parser_function_t;

typedef struct string
{
    char *string;
} string_t;

typedef union list_data
{
    string_t *string;
} list_data_t;

#endif /* !DATATYPES_H_ */