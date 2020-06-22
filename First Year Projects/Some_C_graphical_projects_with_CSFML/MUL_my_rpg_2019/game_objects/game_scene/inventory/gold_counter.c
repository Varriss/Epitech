/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** gold_counter
*/

#include <stdlib.h>
#include "my_rpg.h"

gold_counter_t *init_gold_counter(void)
{
    gold_counter_t *counter = malloc(sizeof(gold_counter_t));

    counter->golds = STARTING_GOLD;
    counter->pos = (sfVector2f){10, 10};
    counter->gold_text = init_text(counter->pos, 30);
    counter->texture = sfTexture_createFromFile(GOLD_PIECE_SPRITE, NULL);
    counter->sprite = sfSprite_create();
    counter->rect = (sfIntRect){0, 0, 120, 120};
    counter->update = &update_g_counter;
    counter->render = &render_g_counter;
    counter->destroy = &destroy_g_counter;
    counter->clock = sfClock_create();
    sfSprite_setTexture(counter->sprite, counter->texture, sfTrue);
    sfSprite_setScale(counter->sprite, (sfVector2f){0.33, 0.33});
    return (counter);
}