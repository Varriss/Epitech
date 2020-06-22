/*
** EPITECH PROJECT, 2020
** GET_OUTPUT_PATH
** File description:
** Get_output_path function
*/

#include <stdlib.h>
#include "my_str.h"
#include "asm.h"
#include "op.h"

char *get_output_path(char const *path)
{
    int asm_name_len = my_strlen(ASM_NAME_EXTENTION);
    int char_id;
    char output_path[1024] = {0};

    if (!path)
        return (NULL);
    char_id = my_strlen(path) - 1;
    while (char_id > 0 && path[char_id] != '/')
        char_id--;
    if (path[char_id] == '/')
        char_id++;
    for (int k = char_id; path[k]; k++)
        output_path[k - char_id] = path[k];
    if (my_strcmp(&(output_path[my_strlen(output_path) - asm_name_len]),
        ASM_NAME_EXTENTION) == 0)
        output_path[my_strlen(output_path) - asm_name_len] = '\0';
    return (my_strcat(output_path, BINARY_NAME_EXTENTION));
}