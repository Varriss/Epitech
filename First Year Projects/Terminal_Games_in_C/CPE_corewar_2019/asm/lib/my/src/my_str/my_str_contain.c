/*
** EPITECH PROJECT, 2019
** MY_STR_CONTAIN
** File description:
** Return 1 if true or 0 if false
*/

int my_str_contain_char(char const *str, char contain)
{
    for (int k = 0; str[k]; k++)
        if (str[k] == contain)
            return (1);
    return (0);
}

int my_str_contain_just_chars(char const *str, char const *contain)
{
    for (int k = 0; str[k]; k++)
        if (!my_str_contain_char(contain, str[k]))
            return (0);
    return (1);
}