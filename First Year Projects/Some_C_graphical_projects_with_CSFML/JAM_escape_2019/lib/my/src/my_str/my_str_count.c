/*
** EPITECH PROJECT, 2019
** MY_STR_COUNT
** File description:
** Return occurence count
*/

int my_str_count_char(char const *str, char c)
{
    int occurence = 0;

    if (!str)
        return (0);
    for (int k = 0; str[k]; k++)
        if (str[k] == c)
            occurence++;
    return (occurence);
}