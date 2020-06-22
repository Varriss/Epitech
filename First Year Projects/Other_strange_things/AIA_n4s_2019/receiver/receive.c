/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** receive
*/

#include "ai.h"

char *receive(void)
{
    char *received = NULL;

    received = get_next_line(0);
    if (!received)
        my_write(1, "Returned NULL", 2);
    if (my_strlen(received) <= 2) {
        free(received);
        return (NULL);
    }
    return (received);
}