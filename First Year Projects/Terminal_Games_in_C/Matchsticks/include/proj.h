/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** proj
*/

#ifndef PROJ_H_
#define PROJ_H_

#include "../lib/my/my.h"

//
// project functions
//
int *get_board(int lines);
int print_board(int *board, int lines);
int win_handle(int win);
int *ai_turn(int *board, int maxmatch, int lines);
int *error_nbr(int nbr, int maxmatch, int *board, int line, int lines);
int *error_line(int lines, int maxmatch, int line, int *board);
int *update_board(int *board, int maxmatch, int lines);
void printf_board(int *board, int lines);
int *error_ret(char *check, int lines, int maxmatch, int *board);
char *my_prompt(char const *mail);

#endif /* !PROJ_H_ */