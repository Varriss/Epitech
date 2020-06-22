/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** game
*/

#include <stdlib.h>
#include <unistd.h>
#include "./include/navy.h"

static int update_game_state(char **map, char **radar)
{
    int count = 0;
    int i_lose = 1;

    for (int i = 2; map[i]; i++)
        for (int j = 2; map[i][j] != '\0'; j++)
            if (my_isnumber(map[i][j]))
                i_lose = 0;
    for (int i = 0; radar[i]; i++)
        for (int j = 0; radar[i][j] != '\0'; j++)
            if (radar[i][j] == 'x')
                count++;
    if (i_lose == 1)
        return (-1);
    if (count == 14)
        return (0);
    return (1);
}

void do_not_player_turn(char *pos, char **map, int one_id)
{
    my_printf("waiting for enemy's attack...\n");
    pos[0] = wait_value();
    pos[1] = wait_value();
    send_value_to(update_own_map(map, pos), one_id);
}

void do_player_turn(char *pos, char **map, char **enemy_map, int two_id)
{
    size_t n = (unsigned long) 2;

    get_prompt_result(pos, &n);
    send_value_to(pos[0], two_id);
    usleep(500);
    send_value_to(pos[1], two_id);
    if (update_radar(enemy_map, pos, wait_value()))
        my_printf("%s: hit\n\n", pos);
    else
        my_printf("%s: missed\n\n", pos);
    print_maps(map, enemy_map);
}

int finish_him(char *pos, char **enemy_map, int game_state)
{
    free(pos);
    free_my_str_arr(enemy_map);
    if (game_state == -1)
        my_printf("Enemy won\n");
    else if (game_state == 0)
        my_printf("I won\n");
    return (game_state *= -1);
}

int game(int one_id, int two_id, char **map)
{
    char *pos = malloc(3);
    char **enemy_map = generate_layout();
    int player_turn = (one_id == getpid() ? 1 : 0);
    int game_state = 1;
    int tmp = 0;

    print_maps(map, enemy_map);
    pos[2] = '\0';
    while (game_state == 1) {
        if (player_turn)
            do_player_turn(pos, map, enemy_map, two_id);
        else
            do_not_player_turn(pos, map, one_id);
        game_state = update_game_state(map, enemy_map);
        player_turn = !player_turn;
        tmp = one_id;
        one_id = two_id;
        two_id = tmp;
    }
    return (finish_him(pos, enemy_map, game_state));
}
