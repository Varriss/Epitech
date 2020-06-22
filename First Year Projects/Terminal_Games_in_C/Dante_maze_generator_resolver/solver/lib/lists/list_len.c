/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** list_len
*/

#include "./lists.h"

int list_len(list_t *list)
{
    int len = 0;
    list_t *tmp = list->next;

    while (tmp != list) {
        len++;
        tmp = tmp->next;
    }
    return (len);
}