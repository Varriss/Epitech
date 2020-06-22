/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** use_potion
*/

#include <stdlib.h>
#include "my_rpg.h"

void use_potion(prog_stat_t *prog_stat, potion_t *potion, list_t *scene)
{
    inventory_t *inventory = (prog_stat->scene_index == game_scene ?
    find_object(scene, player_cursor_type)->data->player_c->inventory :
    find_object(scene, player_type)->data->player->inventory);
    sfVector2f orgin = potion->pos;

    if (potion->can_use) {
        potion->player_has--;
        inventory->life += potion->heal_value;
        if (inventory->life > PLAYER_MAX_HP)
            inventory->life = PLAYER_MAX_HP;
        orgin.x += 40;
        orgin.y += 40;
        create_heal_effect(scene, orgin);
    }
}