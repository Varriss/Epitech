/*
** EPITECH PROJECT, 2019
** Model
** File description:
** my_printf
*/

#include "my.h"

static func_tab_t p_f_t_[] = {
    {'s', &my_putstr},
    {'S', &my_super_putstr},
    {'o', &my_put_octal_nbr},
    {'d', &my_put_nbr},
    {'i', &my_put_nbr},
    {'c', &my_putchar},
    {'X', &my_put_s_hexa_nbr},
    {'x', &my_put_hexa_nbr},
    {'b', &my_put_bin_nbr},
    {'p', &my_put_ptr},
    {'%', 0},
    {'\0', 0}
};

int my_printf(char *str, ...)
{
    va_list ap;
    int j = 0;

    va_start(ap, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            i++;
            for (j = 0; str[i] != p_f_t_[j].ind && p_f_t_[j].ind != '\0'; j++);
            if (p_f_t_[j].ind == '\0')
                return (84);
            if (str[i] == '%')
                write(1, "%", 1);
            else
                p_f_t_[j].foo(va_arg(ap, void *));
        } else
            write(1, &str[i], 1);
    }
    va_end(ap);
    return (0);
}