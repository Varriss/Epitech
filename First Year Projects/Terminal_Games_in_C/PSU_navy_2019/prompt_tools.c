/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** prompt_tools
*/

#include <stdio.h>
#include "./include/navy.h"

//return 1 if c isn't between A and H
int is_between_a_h(char c)
{
    if ((c >= 'A') && (c <= 'H'))
        return (0);
    else
        return (1);
}

//return 1 if c isn't between 1 and 8
int is_between_one_heigth(char c)
{
    if ((c >= '1') && (c <= '8'))
        return (0);
    else
        return (1);
}

void get_prompt_result(char *pos, size_t *n)
{
    my_printf("attack:\t");
    while ((getline(&pos, n, stdin) != 3) || is_between_a_h(pos[0])
    || is_between_one_heigth(pos[1])) {
        my_printf("\nwrong position\nattack:\t");
    }
    pos[2] = '\0';
}