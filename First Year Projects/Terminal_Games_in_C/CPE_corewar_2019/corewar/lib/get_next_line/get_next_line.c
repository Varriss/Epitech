/*
** EPITECH PROJECT, 2019
** GET_NEXT_LINE
** File description:
** Get_next_line function
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

char *add_buff_to_str(char *str, char *buff, int buff_size)
{
    char *new_str;
    int str_len;
    int k = 0;

    if (!str) {
        str = malloc(sizeof(char));
        str[0] = '\0';
    }
    for (str_len = 0; str && str[str_len]; str_len++);
    new_str = malloc(sizeof(char) * (str_len + buff_size + 1));
    for (; k < str_len; k++)
        new_str[k] = str[k];
    for (int i = 0; i < buff_size; i++, k++)
        new_str[k] = buff[i];
    new_str[k] = '\0';
    free(str);
    return (new_str);
}

char *read_until_new_line(int fd, char *str)
{
    char *buff;
    int read_size;

    for (int k = 0; str && str[k]; k++)
        if (str[k] == '\n')
            return (str);
    buff = malloc(sizeof(char) * (READ_SIZE + 1));
    if (!buff)
        return (NULL);
    read_size = read(fd, buff, READ_SIZE);
    buff[read_size] = 0;
    if (read_size < 1) {
        free(buff);
        return (str);
    }
    str = add_buff_to_str(str, buff, read_size);
    free(buff);
    return (read_until_new_line(fd, str));
}

void put_in_last_char(char *tmp, char *last_read, int str_len)
{
    int last_read_len = 0;

    for (; tmp[str_len + 1 + last_read_len]; last_read_len++);
    if (last_read_len == 0) {
        last_read[0] = '\0';
        return;
    }
    last_read[0] = '\0';
    for (int k = 0; k < last_read_len; k++)
        last_read[k] = tmp[str_len + 1 + k];
    last_read[last_read_len] = '\0';
}

void parse_str_last_read(char **str, char *last_read)
{
    int str_len = 0;
    char *tmp = str[0];

    if (!tmp)
        return;
    for (; str[0][str_len] && str[0][str_len] != '\n'; str_len++);
    str[0] = malloc(sizeof(char) * (str_len + 1));
    if (!str[0])
        return;
    for (int k = 0; k < str_len; k++)
        str[0][k] = tmp[k];
    str[0][str_len] = '\0';
    if (!tmp[str_len]) {
        free(tmp);
        last_read[0] = '\0';
        return;
    }
    put_in_last_char(tmp, last_read, str_len);
    free(tmp);
}

char *get_next_line(int fd)
{
    static char last_read[READ_SIZE + 1] = "\0";
    static int last_fd = -1;
    char *str = NULL;

    if (last_fd != fd) {
        last_fd = fd;
        last_read[1] = '\0';
    }
    if (fd < 0)
        return (NULL);
    if (last_read[0]) {
        str = malloc(sizeof(char) * (READ_SIZE + 1));
        if (!str)
            return (NULL);
        for (int c = 0; c < READ_SIZE + 1; c++)
            str[c] = last_read[c];
    }
    str = read_until_new_line(fd, str);
    parse_str_last_read(&str, last_read);
    return (str);
}