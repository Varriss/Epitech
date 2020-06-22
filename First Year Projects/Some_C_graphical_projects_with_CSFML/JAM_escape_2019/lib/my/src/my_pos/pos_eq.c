/*
** EPITECH PROJECT, 2019
** POS_EQ
** File description:
** Return 1 if pos equals and 0 else
*/

#include "my_pos.h"

int pos_eq(pos_t *pos1, pos_t *pos2)
{
    if (!pos1 || !pos2)
        return (0);
    if (pos1->x == pos2->x && pos1->y == pos1->x)
        return (1);
    return (0);
}