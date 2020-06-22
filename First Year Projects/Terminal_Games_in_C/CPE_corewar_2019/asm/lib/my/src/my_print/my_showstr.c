/*
** EPITECH PROJECT, 2019
** MY_SHOWSTR
** File description:
** Wreite non-printable char in hex
*/

#include "my_print.h"

void print_hex_digit(int digit)
{
    if (digit < 10)
        digit += 48;
    else
        digit += 87;
    my_putchar(digit);
}

void print_hex_char(char c)
{
    char first = c / 16;
    char second = c % 16;

    my_putchar('\\');
    print_hex_digit(first);
    print_hex_digit(second);
}

int my_showstr(char const *str)
{
    char ch = 0;

    for (int c = 0; str[c] != '\0'; c++) {
        ch = str[c];
        if (ch >= ' ' && ch <= '~')
            my_putchar(ch);
        else
            print_hex_char(ch);
    }
    return (0);
}