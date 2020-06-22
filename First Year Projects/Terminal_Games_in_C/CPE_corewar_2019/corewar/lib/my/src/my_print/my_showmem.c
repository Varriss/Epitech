/*
** EPITECH PROJECT, 2019
** MY_SHOWMEM
** File description:
** Prints a memory dump
*/

#include <unistd.h>
#include "my_print.h"

void print_hex(char c)
{
    char first = c / 16;
    char second = c % 16;

    if (c < 0) {
        first += 15;
        second += 15;
    }
    first += (first < 10) ? 48 : 87;
    second += (second < 10) ? 48 : 87;
    my_putchar(first);
    my_putchar(second);
}

void write_hex_adress(char const *str)
{
    char adr[] = "........:  ";
    int a = (intptr_t)str;
    int digit = 0;
    int neg = (a < 0) ? -1 : 1;

    if (neg == -1)
        a += 1;
    for (int i = 0; i< 8; i++) {
        digit = a % 16;
        if (neg == -1)
            digit += 15;
        a /= 16;
        digit += (digit < 10) ? 48 : 87;
        adr[7 - i] = digit;
    }
    for (int i = 0; adr[i] != '\0'; i++)
        my_putchar(adr[i]);
}

void write_hex_content(char const *str, int size)
{
    char ch = 0;

    for (int c = 0; c < 16; c++) {
        if (c < size) {
            ch = str[c];
            print_hex(ch);
        }
        else {
            my_putchar(' ');
            my_putchar(' ');
        }
        if (c % 2 == 1)
            my_putchar(' ');
    }
}

void write_printable_content(char const *str, int size)
{
    char ch = 0;

    for (int c = 0; c < size; c++) {
        ch = str[c];
        if (ch >= ' ' && ch <= '~')
            my_putchar(ch);
        else
            my_putchar('.');
    }
    my_putchar('$');
}

int my_showmem(char const *str, int size)
{
    int show_size = 0;

    for (int i = 0; i < size; i += 16) {
        show_size = (size - i >= 16) ? 16 : (size - i);
        write_hex_adress(&str[i]);
        write_hex_content(&str[i], show_size);
        write_printable_content(str + i, show_size);
        my_putchar('\n');
    }
    return 0;
}