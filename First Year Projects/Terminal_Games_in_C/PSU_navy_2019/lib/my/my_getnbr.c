/*
** EPITECH PROJECT, 2019
** MY_GETNBR
** File description:
** returns a number, sent to the function as a string
*/

#include "my.h"

int is_a_nb_character(char c)
{
    if ('0' <= c && c <= '9')
        return 1;
    else
        return 0;
}

int is_negative(char const *str, int mk1)
{
    if (mk1 > 0 && str[mk1-1] == '-')
        return -1;
    else
        return 1;
}

int power(int a, int pow)
{
    int result = 1;

    for (int i = 0; i < pow; i++) {
        result *= a;
    }
    return result;
}

int return_nbr(char const *str, int mk1, int mk2)
{
    int n = mk2-mk1;
    int unsigned sum = 0;
    int power_count = n-1;

    for (int i = mk1; i < mk2; i++) {
        sum = sum + (str[i] - '0')*power(10, power_count);
        power_count--;
    }
    if (sum < (power(2, 16)-1))
        return (sum);
    else
        return (0);

}

int my_getnbr(char const *str)
{
    int marker1 = -1;
    int marker2 = -1;
    int result;

    for (int i = 0; i < (my_strlen(str)) && \
    !(marker1 != -1 && marker2 != -1); i++) {
        if (is_a_nb_character(str[i]) && marker1 == -1) {
            marker1 = i;
        } else if (!is_a_nb_character(str[i]) && marker1 != -1) {
            marker2 = i;
        }
    }
    result = is_negative(str, marker1) * return_nbr(str, marker1, marker2);
    return (result);
}