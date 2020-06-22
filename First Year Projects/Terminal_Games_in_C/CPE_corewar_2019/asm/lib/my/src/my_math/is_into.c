/*
** EPITECH PROJECT, 2019
** IN_INTO
** File description:
** Return if value in into 2 other value
*/

int int_is_into(int x, int a, int b)
{
    if (a < b)
        return (x >= a && x <= b);
    else if (a > b)
        return (x >= b && x <= a);
    return (x == a);
}

int float_is_into(float x, float a, float b)
{
    if (a < b)
        return (x >= a && x <= b);
    else if (a > b)
        return (x >= b && x <= a);
    return (x == a);
}