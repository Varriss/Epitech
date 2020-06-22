/*
** EPITECH PROJECT, 2019
** MY_STRLEN
** File description:
** Return leng of string
*/

int my_strlen(char const *str)
{
    int len = 0;

    if (!str)
        return (len);
    for (;str[len]; len++);
    return (len);
}