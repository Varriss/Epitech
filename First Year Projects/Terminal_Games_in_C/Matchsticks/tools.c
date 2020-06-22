/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** win
*/

#include "proj.h"
#include <time.h>

int *ai_turn(int *board, int maxmatch, int lines)
{
    srandom(time(NULL));
    int line = (random() % lines - 1) + 1;
    int nbr = 0;

    while (board[line] == 0)
        line = (random() % lines - 1) + 1;
    nbr = (random() % (board[line] < maxmatch ? board[line] : maxmatch)) + 1;
    board[line] -= nbr;
    my_printf("\nAI's turn...\nAI removed %d match(es) from line %d",
    nbr, line + 1);
    return (board);
}

int win_handle(int win)
{
    if (win == 0)
        return (0);
    if (win == 1) {
        my_printf("I lost... snif... but I'll get you next time!!\n");
        return (1);
    } else if (win == 2) {
        my_printf("Yoo lost, too bad...\n");
        return (2);
    } else
        return (84);
}

int *update_board(int *board, int maxmatch, int lines)
{
    int line = 0;
    int nbr = 0;
    char *check = my_prompt("Line: ");

    if ((check == NULL) || (my_str_isnum(check)))
        return (error_ret(check, lines, maxmatch, board));
    line = my_getnbr(check);
    if ((line < 1) || (line > lines))
        return (error_line(lines, maxmatch, line, board));
    else {
        check = my_prompt("Matches: ");
        if (my_str_isnum(check))
            return (error_line(lines, maxmatch, -1, board));
        nbr = my_getnbr(check);
        if ((nbr > board[line - 1]) || (nbr > maxmatch) || (nbr == 0))
            return (error_nbr(nbr, maxmatch, board, line, lines));
    }
    my_printf("Player removed %d match(es) from line %d", nbr, line);
    board[line - 1] -= nbr;
    return (board);
}

void printf_board(int *board, int lines)
{
    my_printf("\n");
    print_board(board, lines);
}