/*
** EPITECH PROJECT, 2020
** GAME_KILLER
** File description:
** Game_killer function
*/

int game_killer(int state)
{
    static int killed = 0;

    if (state != -1)
        killed = state;
    return (killed);
}

void kill_game(void)
{
    game_killer(1);
}

int is_game_kill(void)
{
    return (game_killer(-1));
}