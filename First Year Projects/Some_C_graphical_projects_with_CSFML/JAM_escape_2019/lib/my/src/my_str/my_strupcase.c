/*
** EPITECH PROJECT, 2019
** MY_STRUPCASE
** File description:
** Function that puts every letter of every word in it in uppercase
*/

char *my_strupcase(char *str)
{
    for (int c = 0; str[c] != '\0'; c++) {
        if (str[c] > 96 && str[c] < 123)
            str[c] = str[c] - 32;
    }
    return str;
}