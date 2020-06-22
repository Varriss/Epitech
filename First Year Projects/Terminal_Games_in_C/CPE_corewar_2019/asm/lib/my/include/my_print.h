/*
** EPITECH PROJECT, 2019
** MY_PRINT
** File description:
** My_print header
*/

#ifndef MY_PRINT_H
#define MY_PRINT_H

void my_putchar(char c);
void my_putstr(char const *str);
void my_putstr_line(char const *str);
void my_putstr_error(char const *str);
int my_putstr_and_rtn(char const *str, int rtn_value);
int my_putstr_error_and_rtn(char const *str, int rtn_value);
void my_putstr_array(char **str, char separator);
void my_put_nbr(int nb);
void my_put_nbr_error(int nb);

void try_help(char const *binary_name, char const *msg);

int my_showstr(char const *str);
int my_showmem(char const *str, int size);

void *malloc_error_null(void);
int malloc_error_zero(void);

#endif