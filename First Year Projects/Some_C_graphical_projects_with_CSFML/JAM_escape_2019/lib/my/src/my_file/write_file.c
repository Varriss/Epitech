/*
** EPITECH PROJECT, 2019
** WRITE_FILE
** File description:
** Write file function
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "my_str.h"

int create_file(char const *path)
{
    FILE *fd = fopen(path, "w");

    fclose(fd);
    return (1);
}

int write_file(char const *path, char const *content)
{
    int success;
    FILE *fd = fopen(path, "w+");

    success = fwrite(content , 1, my_strlen(content), fd);
    fclose(fd);
    return (success);
}

int append_file(char const *path, char const *content)
{
    int success;
    FILE *fd = fopen(path, "a");

    success = fwrite(content , 1, my_strlen(content), fd);
    fclose(fd);
    return (success);
}