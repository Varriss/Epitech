/*
** EPITECH PROJECT, 2019
** Model
** File description:
** my_chain_funcs_2
*/

#include "my.h"

int chain_l_ten(chain_l_t *elem)
{
    chain_l_t *root = elem;
    int i = 1;

    if (elem == NULL)
        return (84);
    while ((elem->next != root) && (elem->next != NULL)) {
        elem = elem->next;
        i++;
    }
    return (i);
}

void disp_chain_vals(chain_l_t *elem)
{
    int len = chain_l_ten(elem);

    if (elem)
        for (int i = 0; (i < len) && (elem->next != 0); i++) {
            my_put_nbr(elem->val);
            my_putchar('\n');
            elem = elem->next;
        }
}

chain_l_t *sail_chain(chain_l_t *position, int shift)
{
    if ((!position) || (position == NULL))
        return (NULL);
    if ((!shift) || (shift == 0))
        return (position);
    if (shift < 0) {
        shift *= -1;
        for (int i = 0; (i < shift) && (position->prev != 0);
        position = position->prev, i++);
    } else if (shift > 0)
        for (int i = 0; (i < shift) && (position->prev != 0);
        position = position->next, i++);
    return (position);
}