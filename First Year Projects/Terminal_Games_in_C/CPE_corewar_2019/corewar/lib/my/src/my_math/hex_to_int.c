/*
** EPITECH PROJECT, 2020
** hex_to_int
** File description:
** hex_to_int
*/

static int convert_val(char c)
{
    char caract[16] = "0123456789abcdef";
    char caract_maj[16] = "0123456789ABCDEF";

    for (int i = 0; i < 16; i++)
        if (c == caract[i])
            return (i);
    for (int i = 0; i < 16; i++)
        if (c == caract_maj[i])
            return (i);
    return (0);
}

int hex_to_int(char *hex)
{
    int nb = 0;
    int i = 0;
    int l = 0;

    if (!hex)
        return (-1);
    if (hex[0] && hex[0] == '0')
        l++;
    if (hex[1] && (hex[1] == 'x' || hex[1] == 'X'))
        l++;
    for (; hex[i + 1]; i++);
    for (int k = 1; i > l; i--, k *= 16)
        nb += convert_val(hex[i]) * k;
    return (nb);
}
