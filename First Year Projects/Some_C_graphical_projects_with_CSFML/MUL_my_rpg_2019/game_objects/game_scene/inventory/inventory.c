/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory
*/

#include <stdlib.h>
#include "my_rpg.h"

static item_sorter_t sorter[item_number] = {
    {potion_type, &create_potion_item},
    {blade_type, &create_blade_item},
    {shield_type, &create_shield_item}
};

item_t **create_items(void)
{
    item_t **items = malloc(sizeof(item_t *) * (item_number));

    for (int i = 0; i < item_number; i++)
        items[i] = sorter[i].add_item();
    return (items);
}

inventory_t *init_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    inventory->life = PLAYER_MAX_HP;
    inventory->items = create_items();
    inventory->gold_counter = init_gold_counter();
    inventory->update = &update_inventory;
    inventory->render = &render_inventory;
    inventory->destroy = &destroy_inventory;
    return (inventory);
}