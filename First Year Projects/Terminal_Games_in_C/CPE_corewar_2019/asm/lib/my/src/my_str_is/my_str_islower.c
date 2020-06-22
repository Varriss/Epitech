/*
** EPITECH PROJECT, 2019
** MY_STR_ISLOWER
** File description:
** Returns 1 if string only contains lowercase alphabetical and 0 otherwise
*/

int my_str_islower(char const *str)
{
    char ch = 0;

    for (int c = 0; str[c] != '\0'; c++) {
        ch = str[c];
        if (!(ch >= 'a' && ch <= 'z'))
            return (0);
    }
    return (1);
}