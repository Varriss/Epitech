/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** main
*/

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int ac, char *const *argv)
{
    int fd = open(argv[1], O_RDONLY);
    char *s = get_next_line (fd);

    while (s)
    {
        printf("%s\n", s);
        free(s);
        s = get_next_line (fd);
    }
    close(fd);
    return  (0);
}