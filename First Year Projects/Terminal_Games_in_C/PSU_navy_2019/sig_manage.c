/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** sig_manage
*/

#ifndef _POSIX_SOURCE
#define _POSIX_SOURCE
#endif
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "./include/navy.h"

int sig_handle(int signal)
{
    static int nbr = 0;
    static int tmp = 0;
    static int delivery = 0;

    if (signal == SIGUSR1)
        nbr++;
    if (signal == SIGUSR2) {
        tmp = nbr;
        nbr = 0;
        delivery = 1;
    }
    if ((signal == -2) && (delivery == 1)) {
        delivery = 0;
        return (tmp);
    } else
        return (-1);
}

struct sigaction *init_sig(void)
{
    struct sigaction *sig = malloc(sizeof(struct sigaction));

    sigemptyset(&(sig->sa_mask));
    sig->sa_handler = &sig_handle;
    sig->sa_flags = 0;
    sigaction(SIGUSR1, sig, 0);
    sigaction(SIGUSR2, sig, 0);
    return (sig);
}

int wait_value(void)
{
    int value = 0;

    pause();
    while ((value = sig_handle(-2)) == -1)
        pause();
    return (value);
}

void send_value_to(int x, int usr_id)
{
    for (int i = 0; i < x; i++) {
        kill(usr_id, SIGUSR1);
        usleep(SEND_SLEEP);
    }
    kill(usr_id, SIGUSR2);
}