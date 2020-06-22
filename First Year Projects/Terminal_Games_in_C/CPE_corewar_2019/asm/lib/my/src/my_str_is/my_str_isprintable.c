/*
** EPITECH PROJECT, 2019
** MY_STR_ISPRINTABLE
** File description:
** Returns 1 if string only contains printable characters and 0 otherwise
*/

int my_str_isprintable(char const *str)
{
    char ch = 0;

    for (int c = 0; str[c] != '\0'; c++) {
        ch = str[c];
        if (!(ch >= ' ' && ch <= '~'))
            return (0);
    }
    return (1);
}