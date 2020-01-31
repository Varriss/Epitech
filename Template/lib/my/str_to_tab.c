/*
** EPITECH PROJECT, 2020
** Model
** File description:
** str_to_tab
*/

#include "my.h"

int get_next_word_len(char const *str, int rank, char split)
{
    int len = 0;
    int stop = 0;

    for (int i = rank; stop == 0; i++) {
        if (str[i] != split)
            len++;
        if ((str[i] != split) && ((str[i + 1] == split)
        | (str[i + 1] == '\0')))
            stop = 1;
    }
    return (len);
}

char *get_next_split(char const *str, char split)
{
    static int rank = 0;
    int word_len = get_next_word_len(str, rank, split);
    char *word = malloc(word_len + 1);
    int stop = 0;

    for (int i = 0; stop == 0; rank++) {
        if ((str[rank] != split)
        && ((str[rank + 1] == split) | (str[rank + 1] == '\0')))
            stop = 1;
        if (str[rank] != split) {
            word[i] = str[rank];
            i++;
        }
    }
    word[word_len] = '\0';
    if (str[rank] == '\0')
        rank = 0;
    return (word);
}

//count one per packs of followed splits

int count_split(char const *str, char split)
{
    int splits = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] != split) && ((i > 0) && (str[i - 1] == split)))
            splits++;
    return (splits);
}

char **str_to_tab(char const *str)
{
    char **tab = NULL;
    int words = 1 + count_split(str, ' ');

    tab = malloc(sizeof(char *) * (words + 1));
    for (int i = 0; i < words; i++)
        tab[i] = get_next_split(str, ' ');
    tab[words] = 0;
    return (tab);
}