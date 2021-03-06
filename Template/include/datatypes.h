/*
** EPITECH PROJECT, 2020
** Datatypes
** File description:
** datatypes
*/

#ifndef DATATYPES_H_
#define DATATYPES_H_

////////////////////////////////////////////////////////////////////////////////
//                              Previous Declarations                         //
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//                                  Structures                                //
////////////////////////////////////////////////////////////////////////////////

typedef enum scenes_index
{
    nb_scenes
} scenes_index_t;

typedef enum o_type
{
    to_fill
} o_type_t;

////////////////////////////////////////////////////////////////////////////////
//                         Linked list Datastructure                          //
////////////////////////////////////////////////////////////////////////////////

typedef struct data_exemple_s
{
    int o_type;
} data_exemple_t;

typedef union list_data
{
    data_exemple_t *exemple;
} list_data_t;

#endif /* !DATATYPES_H_ */