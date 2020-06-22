/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** chest_loot
*/

#include <stdlib.h>
#include "my_rpg.h"

void switch_tile_to_path(player_cursor_t *player_c)
{
    *(player_c->current_tile) = '*';
    sfTexture_destroy(player_c->tile_ptr->texture);
    player_c->tile_ptr->texture = sfTexture_createFromFile(
    "ressources/tilemap/path.png", NULL);
    sfSprite_setTexture(player_c->tile_ptr->sprite,
    player_c->tile_ptr->texture, sfTrue);
    sfSprite_setPosition(player_c->tile_ptr->sprite, player_c->tile_ptr->pos);
}

void chest_loot(prog_stat_t *prog_stat, player_cursor_t *player_c,
list_t *scene)
{
    inventory_t *inventory = find_object(scene,
    player_cursor_type)->data->player_c->inventory;

    switch_tile_to_path(player_c);
    if (prog_stat || player_c)
        inventory->items[0]->potion->player_has += rand() % 5 + 1;
    inventory->gold_counter->golds += rand() % 75 + 15;
}