/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** get_next_line
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static int find_c_pos(char *str, char to_find)
{
    int i = 0;

    if (!str)
        return (-1);
    for (; str[i] != '\0'; i++)
        if (str[i] == to_find)
            return (i);
    if (to_find == '\0')
        return (i);
    return (-1);
}

static char *str_cat(char *first, char *secon)
{
    int i = 0;
    int first_len = (!first ? 0 : find_c_pos(first, '\0'));
    int secon_len = (!secon ? 0 : find_c_pos(secon, '\0'));
    char *concated = malloc(sizeof(char) * ((first_len + secon_len) + 1));

    if (first) {
        for (; i < first_len; i++)
            concated[i] = first[i];
        free(first);
    }
    if (secon) {
        for (; i < (first_len + secon_len); i++)
            concated[i] = secon[i - first_len];
    }
    concated[(first_len + secon_len)] = '\0';
    return (concated);
}

static char *get_pr_af(char *buff, int mode, int split, int buff_len)
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

static char *get_next_core(int fd, char *line, int pos, char *buf)
{
    static char *tmp = NULL;
    static int rf = READ_SIZE;

    tmp = (pos == 1 ? tmp : NULL);
    rf = (pos == 1 ? (rf) : READ_SIZE);
    if (((pos = find_c_pos(tmp, '\n')) >= 0) || (rf < READ_SIZE)) {
        if ((rf < READ_SIZE) && (pos == -1)) {
            line = (rf == 0 ? NULL : (str_cat(tmp, NULL)));
            rf = 0;
            return (line);
        }
        line = get_pr_af(tmp, -1, (pos >= 0 ? pos : rf), find_c_pos(tmp, '\0'));
        tmp = get_pr_af(tmp, 1, (pos >= 0 ? pos : rf), find_c_pos(tmp, '\0'));
        return (line);
    } else {
        rf = read(fd, buf, READ_SIZE);
        tmp = str_cat(tmp, buf);
        return (get_next_line(fd));
    }
}

// changement of fd reset the read index

char *get_next_line(int fd)
{
    char buf[READ_SIZE + 1] = {0};
    int pos = 0;
    static int prev_fd = 0;

    if (prev_fd != fd)
        pos = 0;
    else
        pos = 1;
    prev_fd = fd;
    return (get_next_core(fd, NULL, pos, buf));
}
