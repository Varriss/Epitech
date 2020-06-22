/*
** EPITECH PROJECT, 2019
** MY_STR_ISNUM
** File description:
** Return 1 if only digits and else 0
*/

int my_str_isnum(char const *str)
{
    char ch = 0;

    for (int c = 0; str[c] != '\0'; c++) {
        ch = str[c];
        if (!(ch >= '0' && ch <= '9'))
            return (0);
    }
    return (1);
}