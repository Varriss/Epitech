/*
** EPITECH PROJECT, 2020
** my_str_ishex
** File description:
** my_str_ishex
*/

static int check_caract(char c)
{
    char caract[22] = "0123456789abcdefABCDEF";

    for (int i = 0; i < 22; i++)
        if (c == caract[i])
            return (1);
    return (0);
}

int my_str_ishex(char *src)
{
    int i = 0;

    if (!src)
        return (0);
    if (src[0] && src[0] == '0')
        i++;
    if (src[1] && (src[1] == 'x' || src[1] == 'X'))
        i++;
    for (; src[i]; i++)
        if (check_caract(src[i]) == 0)
            return (0);
    return (1);
}
