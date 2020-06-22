/*
** EPITECH PROJECT, 2020
** Model main
** File description:
** main
*/

#include "./include/proj.h"

int main(int argc, char **argv, char **env)
{
    if (!argv)
        return (84);
    return (floor_zero(argc, env));
}