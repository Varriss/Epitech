/*
** EPITECH PROJECT, 2019
** MY_PUTCHAR
** File description:
** Put char
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}