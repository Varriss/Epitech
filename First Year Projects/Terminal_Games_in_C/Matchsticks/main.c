/*
** EPITECH PROJECT, 2020
** Model main
** File description:
** main
*/

#include "./include/proj.h"

static int empty_board(int *board, int lines)
{
    for (int i = 0; i < lines; i++) {
        if (board[i] != 0)
            return (0);
    }
    return (1);
}

char *my_prompt(char const *mail)
{
    char *check = NULL;
    size_t n = 50;

    my_printf("%s", mail);
    if (getline(&check, &n, stdin) == -1)
        return (NULL);
    for (int i = 0; check[i] != '\0'; i++)
        if (check[i + 1] == '\n')
            check[i + 1] = '\0';
    return (check);
}

int *error_ret(char *check, int lines, int maxmatch, int *board)
{
    if (check == NULL)
        return (NULL);
    else
        return (error_line(lines, maxmatch, -1, board));
}

static int start(int lines, int maxmatch)
{
    int *board = get_board(lines);

    print_board(board, lines);
    while (!empty_board(board, lines)) {
        my_printf("\nYour turn:\n");
        board = update_board(board, maxmatch, lines);
        if (board == NULL)
            return (0);
        printf_board(board, lines);
        if (!empty_board(board, lines)) {
            board = ai_turn(board, maxmatch, lines);
            printf_board(board, lines);
        } else {
            free(board);
            return (2);
        }
    }
    free(board);
    return (1);
}

int main(int argc, char **argv)
{
    int lines = 0;
    int maxmactch = 0;

    if ((argc != 3) || my_str_isnum(argv[1]) || my_str_isnum(argv[2]))
        return (84);
    lines = my_getnbr(argv[1]);
    maxmactch = my_getnbr(argv[2]);
    return (win_handle(start(lines, maxmactch)));
}
