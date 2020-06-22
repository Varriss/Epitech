/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** multiple_enemy
*/

#include "my_rpg.h"

int count_enemy(list_t *list)
{
    int count = 0;

    for (list_t *res = list->next; (res != list) ; res = res->next) {
        if (res->data != NULL && res->data->enemy->type == enemy_type)
            count++;
    }
    return (count);
}

sfVector2f place_enemy(int count, int mode)
{
    sfVector2f pos = {900, 250};

    if (mode == 1) {
        if (count == 0)
            return (pos);
        pos.y += 50 * count * 0.3;
        pos.x += 50 * count * 0.3;
        return (pos);
    } else
    return ((sfVector2f){2 + count * 0.4, 2 + count * 0.4});
}