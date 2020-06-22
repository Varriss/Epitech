/*
** EPITECH PROJECT, 2019
** Model
** File description:
** my_chain_funcs
*/

#include "my.h"

chain_l_t *create_chaine(void)
{
    chain_l_t *root = NULL;

    root = malloc(sizeof(chain_l_t));
    root->val = 0;
    root->next = root;
    root->prev = root;
    return (root);
}

void del_chain(chain_l_t *list)
{
    chain_l_t *to_free = NULL;

    if ((list) && (list != NULL))
        while (list->next != NULL) {
            to_free = list;
            list = list->next;
            to_free->prev->next = NULL;
            free(to_free);
        }
}

void del_chain_ele(chain_l_t *elem)
{
    if ((elem) && (elem != NULL)) {
        elem->next->prev = elem->prev;
        elem->prev->next = elem->next;
        free(elem);
        elem = NULL;
    }
}

void add_elem_after(chain_l_t *elem, int nb)
{
    chain_l_t *new = NULL;

    if ((nb) && (nb > 0) && (elem) && (elem != NULL)) {
        new = create_chaine();
        new->prev = elem;
        new->next = elem->next;
        elem->next = new;
        nb--;
        add_elem_after(new, nb);
    }
}

void add_elem_before(chain_l_t *elem, int nb)
{
    chain_l_t *new = NULL;

    if ((nb) && (nb > 0) && (elem) && (elem != NULL)) {
        new = create_chaine();
        new->next = elem;
        new->prev = elem->prev;
        elem->prev = new;
        nb--;
        add_elem_after(new, nb);
    }
}