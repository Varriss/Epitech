/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_findchar returns index of found char in src or -1 if not found
*/

int my_findchar(char c, char *src)
{
    for (int i = 0; src[i]; i++) {
        if (src[i] == c)
            return (i);
    }
    return (-1);
}