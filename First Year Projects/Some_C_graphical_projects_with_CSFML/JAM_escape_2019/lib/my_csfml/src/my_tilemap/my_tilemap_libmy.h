/*
** EPITECH PROJECT, 2019
** MY_TILEMAP_LIBMY
** File description:
** My_tilemap_libmy header
*/

#ifndef MY_TILEMAP_LIBMY_H_
#define MY_TILEMAP_LIBMY_H_

char *read_file(char const *path);
char **my_strtok(char const *str, char delim);
int my_get_nbr(char const *str);
int my_str_isint(char const *str);
void **free_2d_str(char **str);
int str_array_len(char const **str);
int my_strcmp(char const *s1, char const *s2);
int int_is_into(int x, int a, int b);

#endif /* !MY_TILEMAP_LIBMY_H_ */