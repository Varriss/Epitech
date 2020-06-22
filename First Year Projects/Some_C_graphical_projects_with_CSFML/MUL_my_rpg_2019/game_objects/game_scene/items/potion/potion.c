/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** potion
*/

#include <stdlib.h>
#include "my_rpg.h"

potion_t *create_potion(void)
{
    potion_t *potion = malloc(sizeof(potion_t));

    potion->type = potion_type;
    potion->texture = sfTexture_createFromFile(POTION_SPRITE, NULL);
    potion->sprite = sfSprite_create();
    sfSprite_setTexture(potion->sprite, potion->texture, sfTrue);
    sfSprite_setScale(potion->sprite, (sfVector2f){0.5, 0.5});
    potion->display = sfTrue;
    potion->pos = (sfVector2f){0, 0};
    potion->price = POTION_PRICE;
    potion->player_has = 3;
    potion->heal_value = POTION_HEAL;
    potion->onhover = NULL;
    potion->onuse = &use_potion;
    potion->text = init_text(potion->pos, 25);
    potion->update = &update_potion;
    potion->render = &render_potion;
    potion->destroy = &destroy_potion;
    return (potion);
}

item_t *create_potion_item(void)
{
    item_t *potion_item = malloc(sizeof(item_t));

    potion_item->potion = create_potion();
    return (potion_item);
}