/*
** EPITECH PROJECT, 2020
** GAME_MUTE
** File description:
** Game_mute function
*/

int game_mute(int new_state)
{
    static int state = 0;

    if (new_state != -1)
        state = new_state;
    return (state);
}

int is_game_mute(void)
{
    return (game_mute(-1));
}

void set_game_mute(int new_state)
{
    game_mute(new_state);
}