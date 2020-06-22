/*
** EPITECH PROJECT, 2020
** FILE_NAME
** File description:
** File_name function
*/

#include <stddef.h>
#include "my_str.h"

static void file_name(char *get_name, char const *set_name, int action)
{
    static char name[1024] = {0};
    int char_id = 0;
    int k;

    if (action) {
        char_id = my_strlen(set_name);
        while (char_id > 0 && set_name[char_id] != '/')
            char_id--;
        if (set_name[char_id] == '/')
            char_id++;
        for (k = char_id; set_name[k]; k++)
            name[k - char_id] = set_name[k];
        name[k - char_id] = '\0';
    }
    else {
        for (int k = 0; k < my_strlen(name) + 1; k++)
            get_name[k] = name[k];
    }
}

void get_file_name(char *get_name)
{
    if (!get_name)
        return;
    file_name(get_name, NULL, 0);
}

void set_file_name(char const *set_name)
{
    if (!set_name)
        return;
    file_name(NULL, set_name, 1);
}