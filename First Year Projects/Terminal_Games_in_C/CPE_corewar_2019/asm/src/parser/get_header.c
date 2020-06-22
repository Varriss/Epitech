/*
** EPITECH PROJECT, 2020
** GET_HEADER
** File description:
** Get_header function
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "my_file.h"
#include "my_str.h"
#include "my_print.h"
#include "asm.h"

int get_header(int fd, data_t *data)
{
    if (get_header_name(fd, data))
        return (EXIT_FAILURE);
    if (get_header_comment(fd, data))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}