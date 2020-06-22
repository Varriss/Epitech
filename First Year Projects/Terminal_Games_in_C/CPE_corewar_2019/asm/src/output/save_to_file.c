/*
** EPITECH PROJECT, 2020
** SAVE_TO_FILE
** File description:
** Save_to_file function
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "my_str.h"

int save_to_file(char const *path, char const *data, size_t data_len)
{
    FILE *fd = fopen(path, "w");

    if (!fd)
        return (EXIT_FAILURE);
    if (fwrite(data , 1, data_len, fd) != data_len) {
        fclose(fd);
        return (EXIT_FAILURE);
    }
    fclose(fd);
    return (EXIT_SUCCESS);
}