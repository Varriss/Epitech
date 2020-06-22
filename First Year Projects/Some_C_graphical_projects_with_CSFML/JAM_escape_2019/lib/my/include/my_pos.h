/*
** EPITECH PROJECT, 2019
** MY_POS
** File description:
** My_pos header
*/

#ifndef MY_POS_H
#define MY_POS_H

//////////////////////// VAR ////////////////////////

// def struct
typedef struct pos_s pos_t;

// struct
struct pos_s
{
    int x;
    int y;
};

///////////////////// PROTOTYPE /////////////////////

int pos_eq(pos_t *pos1, pos_t *pos2);

#endif