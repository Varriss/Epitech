/*
** EPITECH PROJECT, 2020
** Model
** File description:
** proj
*/

#ifndef PROJ_H_
#define PROJ_H_

#include "../lib/my/my.h"


typedef struct s_flags_and_targets {
    char *flags;
    char **targets;
} t_f_t;
//
// project functions
//
char *storeflags(char **av);
char **get_targets(char **av);
int args_handle(int ac, char **av);
struct dirent **list_dir(char *fpath);
void sort(struct dirent **tab, int rank);
int standard_case(t_f_t *f_t);

#endif /* !PROJ_H_ */