/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** init
*/

#include <signal.h>
#include <unistd.h>
#include "./include/navy.h"

int j_one_start(void)
{
    int j_two_id = 0;

    my_printf("my_pid:\t%d\nwaiting for enemy connection...\n", getpid());
    j_two_id = wait_value();
    if (j_two_id <= 0)
        return (-1);
    send_value_to(j_two_id, j_two_id);
    my_printf("\nenemy connected\n\n");
    return (j_two_id);
}

int j_two_start(char *j_one)
{
    int j_one_id = my_atoi(j_one);
    int my_id = getpid();

    if (j_one_id <= 0)
        return (-1);
    my_printf("my_pid:\t%d\n", my_id);
    send_value_to(my_id, j_one_id);
    if (my_id != wait_value())
        return (-1);
    my_printf("successfully connected\n\n");
    return (j_one_id);
}

int link_then_start(int argc, char *const *argv, char **map)
{
    int one = 0;
    int two = 0;
    struct sigaction *sig = NULL;

    sig = init_sig();
    if (argc == 2) {
        one = getpid();
        two = j_one_start();
    } else if ((argc == 3) && (my_is_numberstr(argv[1]))) {
        two = getpid();
        one = j_two_start(argv[1]);
    }
    if ((one == -1) || (two == -1))
        return (clean_all(FAILURE_CODE, map, sig));
    return (clean_all(game(one, two, map), map, sig));
}