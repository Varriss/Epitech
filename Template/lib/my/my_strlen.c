/*
** EPITECH PROJECT, 2019
** MY_STRLEN
** File description:
** returns the length of an array, does not count the '\0'
*/

int my_strlen(char const *str)
{
    int len = 0;

    if (!str)
        return (-1);
    while (str[len++] != '\0');
    return (len);
}