/*
** EPITECH PROJECT, 2019
** MY_STRNCMP
** File description:
** Reproduce the behavior of the str_ncmp function
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int c = 0; c < n; c++) {
        if (s1[c] == '\0' && s2[c] == '\0')
            return 0;
        if (s1[c] != s2[c])
            return (s1[c] - s2[c]);
    }
    return (0);
}