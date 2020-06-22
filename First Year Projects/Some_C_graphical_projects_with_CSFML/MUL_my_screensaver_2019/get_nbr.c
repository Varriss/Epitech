/*
** EPITECH PROJECT, 2019
** MUL
** File description:
** get_nbr
*/

static char is_digit(char test_char)
{
    return (test_char >= '0' && test_char <= '9');
}

int my_getnbr(char *str)
{
    char *reader = str;
    int is_neg = 0;
    int return_number = 0;

    while (*reader != '\0' && !is_digit(*reader)) {
        if (*reader == '-')
            is_neg = !is_neg;
        reader++;
    }
    while (*reader != '\0' && is_digit(*reader)) {
        return_number = (return_number * 10) + ((*reader) - '0');
        reader++;
    }
    return (is_neg ? -return_number : return_number);
}