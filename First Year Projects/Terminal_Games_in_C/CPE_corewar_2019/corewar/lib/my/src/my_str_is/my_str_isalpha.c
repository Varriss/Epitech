/*
** EPITECH PROJECT, 2019
** MY_STR_ISALPHA
** File description:
** Return 1 if only alphabetical and else 0
*/

int my_str_isalpha(char const *str)
{
    char ch = 0;

    for (int c = 0; str[c] != '\0'; c++) {
        ch = str[c];
        if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')))
            return (0);
    }
    return (1);
}