/*
** EPITECH PROJECT, 2019
** MY_HEADER
** File description:
** ITS MYYY HEADEEEEEER
*/

#ifndef MY_H_
#define MY_H_

#include "./my_printf.h"

int my_isnumber(char c);
int my_atoi(char *src);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
void my_put_nbr_base(long int nb, char *base);
int my_prime_prime_sup(int nb);
int my_is_letter(char c);
int is_a_nb_character(char c);
int is_a_nb_character(char c);
int is_negative(char const *str, int mk1);
int power(int a, int pow);
int return_nbr(char const *str, int mk1, int mk2);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int nb);
int my_putchar(char c);
int my_putstr(char const *str);
void my_swap_chars(char *src1, char *src2);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *src, int size);
char *my_strdup(char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_is_numberstr(char *src);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcat(char *dest, char *src);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *src);
int my_streq(char *src, char *to_cmp);
char *my_strlowcase(char *str);
char * my_strncat(char *dest, char const *src, int n);
char *my_strncpy(char *dest, char const *src, int n);
char **my_str_to_word_array(char *src, char c);
int check_rest(char *str, char *to_find, int i);
void free_my_str_arr(char **src);
void print_my_str_arr(char **src, char sep);
int my_str_arr_len(char **src);
char **my_str_arr_dup(char **src);
int my_write(int returnval, char *src, int output);
int my_findchar(char c, char *src);

// my_getnextline

#endif /* !MY_H_ */