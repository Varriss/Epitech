/*
** EPITECH PROJECT, 2020
** Model
** File description:
** my_prompt
*/

#include "my.h"

char *my_prompt(char *mail)
{
    my_printf("%s", mail);
    return (get_next_line(STDIN_FILENO));
}