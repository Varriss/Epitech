/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** my_chain_funcs
*/

#include "my.h"

chain_l *create_chaine(void)
{
    chain_l *root = NULL;

    root = malloc(sizeof(chain_l));
    root->val = 0;
    root->next = root;
    root->prev = root;
    return (root);
}

void del_chain(chain_l *list)
{
    chain_l *to_free = NULL;

    while (list->next != NULL) {
        to_free = list;
        list = list->next;
        to_free->prev->next = NULL;
        free(to_free);
    }
}

void del_chain_ele(chain_l *elem)
{
    elem->next->prev = elem->prev;
    elem->prev->next = elem->next;
    free(elem);
    elem = NULL;
}

void add_elem_after(chain_l *elem, int nb)
{
    chain_l *new = NULL;

    if (nb > 0) {
        new = create_chaine();
        new->prev = elem;
        new->next = elem->next;
        elem->next = new;
        nb--;
        add_elem_after(new, nb);
    }
}

void add_elem_before(chain_l *elem, int nb)
{
    chain_l *new = NULL;

    if (nb > 0) {
        new = create_chaine();
        new->next = elem;
        new->prev = elem->prev;
        elem->prev = new;
        nb--;
        add_elem_after(new, nb);
    }
}