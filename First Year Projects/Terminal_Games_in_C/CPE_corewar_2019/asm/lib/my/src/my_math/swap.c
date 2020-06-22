/*
** EPITECH PROJECT, 2019
** SWAP
** File description:
** Swap
*/

void swap_int(int *a, int *b)
{
    int tmp = *a;

    *a = *b;
    *b = tmp;
}