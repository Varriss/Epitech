/*
** EPITECH PROJECT, 2019
** MY_STR_TO_WORD_ARRAY
** File description:
** Converts a string of words separated by special
** characters into an array of words
*/

#include "my.h"

int is_alphanum(char c)
{
    if (('0' <= c && c <= '9')
    || ('a' <= c && c <= 'z')
    || ('A' <= c && c <= 'Z'))
        return (1);
    else
        return (0);
}

int count_words(char const *str)
{
    int nb_words = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alphanum(str[i]) && !is_alphanum(str[i + 1]))
            nb_words++;
    }
    return (nb_words);
}

void malloc_the_words(char **dest, char const *src)
{
    int this_word_size = 0;
    int word = 0;

    for (int i = 0; src[i] != '\0' ; i++) {
        if (is_alphanum(src[i]))
            this_word_size++;
        if (is_alphanum(src[i]) && !is_alphanum(src[i + 1])) {
            dest[word] = malloc(sizeof(char) * (this_word_size + 1));
            dest[word][this_word_size] = '\0';
            word++;
        }
    }
}

void store_the_words(char ** dest, char const *src, int nb_words)
{
    int word = 0;
    int c = 0;

    for (int i = 0; word < nb_words; i++) {
        if (is_alphanum(src[i]) == 1) {
            dest[word][c] = src[i];
            c++;
        }
        if (is_alphanum(src[i]) && !is_alphanum(src[i + 1])) {
            c = 0;
            word++;
        }
    }
}

char **my_str_to_word_array(char *src)
{
    int nb_words;
    char **dest;

    if (src == 0)
        return (0);
    else {
        nb_words = count_words(src);
        dest = malloc(sizeof(char *) * (nb_words + 1));
        dest[nb_words] = 0;
        malloc_the_words(dest, src);
        store_the_words(dest, src, nb_words);
        return (dest);
    }
}