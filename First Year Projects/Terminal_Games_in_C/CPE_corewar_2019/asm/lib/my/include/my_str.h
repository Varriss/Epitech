/*
** EPITECH PROJECT, 2019
** MY_STR
** File description:
** My_str header
*/

#ifndef MY_STR_H
#define MY_STR_H

// my_str
int my_strlen(char const *str);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char **my_strtok(char const *str, char delim);
void *free_2d_str(char **str);
int array_len(void **array);
char *my_strclone(char const *str);
char *my_strcat(char const *str1, char const *str2);

void *multi_free(int nb, ...);

// my_strchr
char *my_strchr(char const *str, char c);
int my_strchr_index(char const *str, char c);
int my_strchr_nindex(char const *str, char c, int n);

int my_str_eq(char const *s1, char const *s2);

// my_str_contain
int my_str_contain_char(char const *str, char contain);
int my_str_contain_just_chars(char const *str, char const *contain);

int my_str_count_char(char const *str, char c);

char *fill_of(char c, int size);

// convert
char my_charlowcase(char c);
char *my_strlowcase(char *str);
char *my_strupcase(char *str);

#endif