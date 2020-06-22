/*
** EPITECH PROJECT, 2020
** Model
** File description:
** proj
*/

#ifndef PROJ_H_
#define PROJ_H_

#include "../lib/my/my.h"

//
// project functions
//
int floor_zero(int argc, char **env);
int fork_proce(int ret, char *buffer, char **env);
int prog_exe(char *filepath, char **env);
int my_cd(char *buffer);
int my_setenv(char **argv, char **env);
int my_env(char *buffer, char **env);
int my_exit(char *buffer);
char *get_str_in_tab(char **tab, char *to_find);

#endif /* !PROJ_H_ */