/*
** EPITECH PROJECT, 2020
** Model
** File description:
** tools
*/

#include "my.h"

int find_char_pos(char *str, char to_find)
{
    int i = 0;

    if ((!str) || (!to_find))
        return (-1);
    for (; str[i] != '\0'; i++)
        if (str[i] == to_find)
            return (i);
    if (to_find == '\0')
        return (i);
    return (-1);
}

char *get_pre_aft(char *buff, int mode, int split, int buff_len)
{
    char *prev = NULL;
    char *afte = NULL;

    if (mode < 0) {
        prev = malloc(sizeof(char) * split + 1);
        for (int i = 0; i < split; i++)
            prev[i] = buff[i];
        prev[split] = '\0';
        return (prev);
    } else {
        afte = malloc(sizeof(char) * (buff_len - split));
        for (int i = split; i < buff_len; i++)
            afte[i - split] = buff[i + 1];
        afte[buff_len - split - 1] = '\0';
        return (afte);
    }
}