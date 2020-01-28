/*
** EPITECH PROJECT, 2019
** MY_HEADER
** File description:
** My, header
*/

#ifndef READ_SIZE
#define READ_SIZE (101)
#endif

#ifndef MY_H
#define MY_H

#include <sys/types.h>
#include <dirent.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <wait.h>

//
// structs
//
typedef struct tab_of_function_pointer
{
    char ind;
    void *(*foo)(void *);
} func_tab_t;
typedef struct chained_list
{
    int val;
    struct chained_list *prev;
    struct chained_list *next;
} chain_l_t;

//
// PRINTF
//
void my_putchar(char c);
void my_super_putstr(char *src);
int my_putstr(char const *str);
int my_put_nbr(int nb);
void my_put_octal_nbr(unsigned int src);
void my_put_base_nbrs(unsigned int src, char *base);
void my_put_s_hexa_nbr(unsigned int src);
void my_put_hexa_nbr(unsigned int src);
void my_put_bin_nbr(unsigned int src);
void my_put_ptr(unsigned int src);
int my_printf(char *str, ...);

//
// Get infos
//
int my_strlen(char const *str);
char *get_next_line(int fd);
int find_char_pos(char *str, char to_find);
char *get_pre_aft(char *buff, int mode, int split, int buff_len);
char *my_prompt(char *mail);
int get_next_word_len(char const *str, int rank, char split);
char *get_next_split(char const *str, char split);
int count_split(char const *str, char split);

//
// chained list functions
//
chain_l_t *create_chaine(void);
void del_chain(chain_l_t *list);
void del_chain_ele(chain_l_t *elem);
void add_elem_before(chain_l_t *elem, int nb);
void add_elem_after(chain_l_t *elem, int nb);
int chain_len(chain_l_t *elem);
chain_l_t *sail_chain(chain_l_t *position, int shift);
void disp_chain_vals(chain_l_t *root);

//
// char/nbrs check functions
//
int my_isnumber(char c);
int is_negative(char const *str, int mk1);
int my_str_isnum(char *str);
int my_getnbr(char const *str);
int is_anum(char c);

//
// str transfo functions
//
int my_char_int_conv(char c);
char *my_strdup(char const *src);
char *my_strcat(char *first, char *secon);
char *my_strcpy(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int n);
char *my_strncpy(char *dest, char const *src, int n);
void initialize_str(char *src, int size);
char **str_to_tab(char const *str);
int str_cmp(char *one, char *two);
int str_ncmp(char *one, char *two, int n);
void free_tab(char **tab);

//
// compute functions
//
int my_compute_power_rec(int nb, int p);

#endif /* !MY_H_ */