/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory_callbacks
*/

#include <stdlib.h>
#include "my_rpg.h"


void update_inventory(prog_stat_t *prog_stat, inventory_t *inventory,
list_t *scene)
{
    for (int i = 0; i < item_number; i++) {
        if (inventory->items[i]->potion->update)
            inventory->items[i]->potion->update(prog_stat,
            inventory->items[i]->potion, scene);
    }
    inventory->gold_counter->update(prog_stat, inventory->gold_counter, scene);
}

void render_inventory(prog_stat_t *prog_stat, inventory_t *inventory,
list_t *scene)
{
    for (int i = 0; i < item_number; i++) {
        if (inventory->items[i]->potion->update)
            inventory->items[i]->potion->render(prog_stat,
            inventory->items[i]->potion, scene);
    }
    inventory->gold_counter->render(prog_stat, inventory->gold_counter, scene);
}

void destroy_inventory(prog_stat_t *prog_stat, inventory_t *inventory,
list_t *scene)
{
    for (int i = 0; i < item_number; i++) {
        if (inventory->items[i]->potion->update)
            inventory->items[i]->potion->destroy(prog_stat,
            inventory->items[i]->potion, scene);
        free(inventory->items[i]);
    }
    inventory->gold_counter->destroy(prog_stat, inventory->gold_counter, scene);
}