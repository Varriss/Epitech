/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** double_chained_lists
*/

#include <stdlib.h>
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

list_t *create_list(void)
{
    list_t *root = malloc(sizeof(list_t));

    if (root != NULL) {
        root->data = NULL;
        root->next = root;
        root->prev = root;
    }
    return (root);
}

void empty_list(list_t *list)
{
    list_t *current;
    list_t *next;

    for (current = list->next; current != list; current = next) {
        next = current->next;
        free(current->data);
        free(current);
    }
}

void delete_list(list_t *root)
{
    empty_list(root);
    free(root);
    root = NULL;
}