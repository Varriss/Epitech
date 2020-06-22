/*
** EPITECH PROJECT, 2019
** MY_GET_NBR
** File description:
** Convert char * to int
*/

int my_get_nbr(char const *str)
{
    int number = 0;
    int is_neg = 1;
    int i = 0;

    for (; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-')
            is_neg *= -1;
    }
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        number *= 10;
        if (is_neg == 1)
            number += str[i] - 48;
        else
            number -= str[i] - 48;
    }
    return (number);
}
