/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** my_chain_funcs_2
*/

#include "my.h"

int chain_len(chain_l *elem)
{
    chain_l *root = elem;
    int i = 1;

    if (elem == NULL)
        return (84);
    while ((elem->next != root) && (elem->next != NULL)) {
        elem = elem->next;
        i++;
    }
    return (i);
}

void disp_chain_vals(chain_l *elem)
{
    int len = chain_len(elem);

    for (int i = 0; (i < len) && (elem->next != 0); i++, elem = elem->next) {
        my_put_nbr(elem->val);
        my_putchar('\n');
    }
}

chain_l *sail_chain(chain_l *position, int shift)
{
    if (shift < 0) {
        shift *= -1;
        for (int i = 0; (i < shift) && (position->prev != 0)
        ; position = position->prev, i++);
    } else if (shift > 0)
        for (int i = 0; (i < shift) && (position->prev != 0)
        ; position = position->next, i++);
    return (position);
}