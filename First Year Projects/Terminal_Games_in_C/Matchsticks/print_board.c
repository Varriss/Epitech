/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** print_board
*/

#include "./include/proj.h"

int *get_board(int lines)
{
    int *board = malloc(sizeof(int) *lines);

    board[0] = 1;
    for (int i = 1; i < lines; i++)
        board[i] = 1 + (2 * i);
    return (board);
}

static void print_line(int nbr, int width, int line)
{
    int rnbr = (1 + 2 * line);

    my_putchar('*');
    for (int i = 0; i < (width - rnbr) / 2; i++)
        my_putchar(' ');
    for (int i = 0; i < nbr; i++)
        my_putchar('|');
    for (int i = 0; i < ((width - nbr) + (rnbr - nbr)) / 2; i++)
        my_putchar(' ');
    my_putstr("*\n");
}

int print_board(int *board, int lines)
{
    int width = 1 + (lines - 1) * 2;

    for (int i = 0; i <= width + 1; i++)
        my_putchar('*');
    my_putchar('\n');
    for (int i = 0; i < lines; i++)
        print_line(board[i], width, i);
    for (int i = 0; i <= width + 1; i++)
        my_putchar('*');
    my_putchar('\n');
    return (0);
}