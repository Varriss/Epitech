/*
** EPITECH PROJECT, 2019
** MY_STR_ISUPPER
** File description:
** Returns 1 if string only contains uppercase alphabetical and 0 otherwise
*/

int my_str_isupper(char const *str)
{
    char ch = 0;

    for (int c = 0; str[c] != '\0'; c++) {
        ch = str[c];
        if (!(ch >= 'A' && ch <= 'Z'))
            return (0);
    }
    return (1);
}