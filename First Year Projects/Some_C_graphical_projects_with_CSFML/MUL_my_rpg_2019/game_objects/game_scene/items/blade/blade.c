/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** blade
*/

#include "my_rpg.h"

static char *blade_sprites[] = {
        "ressources/items/blade_0.png",
        "ressources/items/blade_1.png",
        "ressources/items/blade_2.png",
        0
};

void update_blade_lvl(blade_t *blade)
{
    static int last_blade_lvl = 0;

    if (blade->quest_completion >= blade->quest && blade->lvl < MAX_BLADE_LVL) {
        blade->lvl++;
        blade->quest_completion = 0;
        blade->quest = 5 + (blade->lvl * 3);
    }
    if (blade->lvl != last_blade_lvl) {
        last_blade_lvl = blade->lvl;
        sfSprite_setTexture(blade->sprite
        , blade->texture[blade->lvl], sfTrue);
    }
}

void update_blade(prog_stat_t *prog_stat, blade_t *potion,
list_t *scene)
{
    list_t *player_c = find_object(scene, player_cursor_type);
    sfVector2f actual_pos = {10 * (blade_type + 1) + 80, 800};

    if (player_c && prog_stat) {
        potion->pos.x = player_c->data->player_c->sprite_pos.x
        - (WINDOW_WIDTH / 2) + actual_pos.x;
        potion->pos.y = player_c->data->player_c->sprite_pos.y
        - (WINDOW_HEIGHT / 2) + actual_pos.y;
    } else {
        potion->pos.x = actual_pos.x;
        potion->pos.y = actual_pos.y;
    }
    sfSprite_setPosition(potion->sprite, potion->pos);
    update_blade_lvl(potion);
}

sfTexture **load_blade_texture(void)
{
    int textures_nbr = my_str_arr_len(blade_sprites);
    sfTexture **texture_tab = malloc(sizeof(sfTexture *) * (textures_nbr + 1));

    texture_tab[textures_nbr] = NULL;
    for (int i = 0; i < textures_nbr; i++) {
        texture_tab[i] = sfTexture_createFromFile(blade_sprites[i], NULL);
    }
    return (texture_tab);
}

blade_t *create_blade(int lvl)
{
    blade_t *blade = malloc(sizeof(blade_t));

    blade->type = blade_type;
    blade->texture = load_blade_texture();
    blade->sprite = sfSprite_create();
    blade->lvl = lvl;
    blade->quest = 5 + blade->lvl;
    blade->quest_completion = 0;
    sfSprite_setTexture(blade->sprite, blade->texture[0], sfTrue);
    sfSprite_setScale(blade->sprite, (sfVector2f){0.5, 0.5});
    blade->display = sfTrue;
    blade->pos = (sfVector2f){0, 0};
    blade->onhover = NULL;
    blade->onuse = NULL;
    blade->update = &update_blade;
    blade->render = &render_blade;
    blade->destroy = &destroy_blade;
    return (blade);
}

item_t *create_blade_item(void)
{
    item_t *blade_item = malloc(sizeof(item_t));

    blade_item->blade = create_blade(0);
    return (blade_item);
}