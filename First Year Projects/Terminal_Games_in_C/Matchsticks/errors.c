/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** errors
*/

#include "./include/proj.h"

int *error_nbr(int nbr, int maxmatch, int *board, int line, int lines)
{
    if (nbr > board[line - 1])
        my_printf("Error: not enough matches on this line\n");
    if (nbr > maxmatch)
        my_printf("Error: you cannot remove more than %d matches per turn\n",
        maxmatch);
    if (nbr == 0)
        my_printf("Error: you have to remove at least one match\n");
    if (nbr < 0)
        my_printf("Error: invalid input (positive number expected)\n");
    return (update_board(board, maxmatch, lines));
}

int *error_line(int lines, int maxmatch, int line, int *board)
{
    if ((line == 0) || (line > lines))
        my_printf("Error: this line is out of range\n");
    if (line < 0)
        my_printf("Error: invalid input (positive number expected)\n");
    return (update_board(board, maxmatch, lines));
}