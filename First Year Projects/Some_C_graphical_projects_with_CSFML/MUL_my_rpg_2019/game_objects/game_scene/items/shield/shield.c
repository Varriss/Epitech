/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** shield
*/

#include <stdlib.h>
#include "my_rpg.h"

static char *shield_sprites[] = {
    "ressources/items/shield0.png",
    "ressources/items/shield1.png",
    "ressources/items/shield2.png",
    0
};

sfTexture **load_shield_texture(void)
{
    int textures_nbr = my_str_arr_len(shield_sprites);
    sfTexture **texture_tab = malloc(sizeof(sfTexture *) * (textures_nbr + 1));

    texture_tab[textures_nbr] = NULL;
    for (int i = 0; i < textures_nbr; i++) {
        texture_tab[i] = sfTexture_createFromFile(shield_sprites[i], NULL);
    }
    return (texture_tab);
}

shield_t *create_shield(int lvl)
{
    shield_t *shield = malloc(sizeof(shield_t));

    shield->type = shield_type;
    shield->texture = load_shield_texture();
    shield->sprite = sfSprite_create();
    shield->lvl = lvl;
    shield->quest = 5 + shield->lvl;
    shield->quest_completion = 0;
    sfSprite_setTexture(shield->sprite, shield->texture[0], sfTrue);
    sfSprite_setScale(shield->sprite, (sfVector2f){0.72, 0.66});
    shield->display = sfTrue;
    shield->pos = (sfVector2f){0, 0};
    shield->onhover = NULL;
    shield->onuse = NULL;
    shield->update = &update_shield;
    shield->render = &render_shield;
    shield->destroy = &destroy_shield;
    return (shield);
}

item_t *create_shield_item(void)
{
    item_t *shield_item = malloc(sizeof(item_t));

    shield_item->shield = create_shield(0);
    return (shield_item);
}