/*
** EPITECH PROJECT, 2019
** MY_STRCAT
** File description:
** concatenates two strings
*/

#include "my.h"

char *my_strcat(char *first, char *secon)
{
    int i = 0;
    int first_len = (!first ? 0 : find_char_pos(first, '\0'));
    int secon_len = (!secon ? 0 : find_char_pos(secon, '\0'));
    char *concated = malloc(sizeof(char) * ((first_len + secon_len) + 1));

    if (first)
        for (; i < first_len; i++)
            concated[i] = first[i];
    if (secon)
        for (; i < (first_len + secon_len); i++)
            concated[i] = secon[i - first_len];
    concated[(first_len + secon_len)] = '\0';
    free(first);
    free(secon);
    return (concated);
}