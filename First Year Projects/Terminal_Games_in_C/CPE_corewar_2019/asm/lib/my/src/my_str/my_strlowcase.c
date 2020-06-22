/*
** EPITECH PROJECT, 2019
** MY_STRLOWCASE
** File description:
** Function that puts every letter of every word in it in lowercase
*/

char my_charlowcase(char c)
{
    if (c > 64 && c < 91)
        c += 32;
    return (c);
}

char *my_strlowcase(char *str)
{
    for (int c = 0; str[c] != '\0'; c++) {
        if (str[c] > 64 && str[c] < 91)
            str[c] = str[c] + 32;
    }
    return (str);
}