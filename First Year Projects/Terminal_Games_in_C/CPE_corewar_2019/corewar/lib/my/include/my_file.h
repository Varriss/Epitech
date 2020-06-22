/*
** EPITECH PROJECT, 2019
** MY_FILE
** File description:
** My_file header
*/

#ifndef MY_FILE_H
#define MY_FILE_H

char *read_file(char const *path);

int create_file(char const *path);
int write_file(char const *path, char const *content);
int append_file(char const *path, char const *content);

#endif