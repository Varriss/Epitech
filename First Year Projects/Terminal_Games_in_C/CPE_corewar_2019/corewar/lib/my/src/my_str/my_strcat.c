/*
** EPITECH PROJECT, 2019
** MY_STRCAT
** File description:
** My_strcat function
*/

#include <stddef.h>
#include <stdlib.h>
#include "my_str.h"

char *my_strcat(char const *str1, char const *str2)
{
    int str1_len = my_strlen(str1);
    int str2_len = my_strlen(str2);
    char *cat = malloc(sizeof(char) * (str1_len + str2_len + 1));
    int k;

    if (!cat)
        return (NULL);
    for (k = 0; k < str1_len; k++)
        cat[k] = str1[k];
    for (int i = 0; i < str2_len; i++, k++)
        cat[k] = str2[i];
    cat[k] = '\0';
    return (cat);
}