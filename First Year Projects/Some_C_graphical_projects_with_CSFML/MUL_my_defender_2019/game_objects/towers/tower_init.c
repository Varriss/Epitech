/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tower_init
*/

#include <stdlib.h>
#include "my_defender.h"

void select_check(prog_stat_t *prog_stat, struct button *button,
list_t *game_scene)
{
    if (find_object(game_scene,
    level_type)->data->level->selected_tower == button->id)
        sfSprite_setColor(button->sprite, (sfColor){255, 255, 255, 125});
    else
        sfSprite_setColor(button->sprite, (sfColor){255, 255, 255, 255});
}

list_data_t *init_tower_one_hud(void)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    button->pos.x = TILE_WIDTH * 1;
    button->pos.y = (WINDOW_HEIGHT - (TILE_HEIGHT * 1.5));
    button->update = &select_check;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = &t_one;
    button->textu = sfTexture_createFromFile(TURRET_ONE_PRICE, NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    button->id = 1;
    return (data);
}

list_data_t *init_tower_two_hud(void)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    button->pos.x = TILE_WIDTH * 3;
    button->pos.y = (WINDOW_HEIGHT - (TILE_HEIGHT * 1.5));
    button->update = &select_check;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = &t_two;
    button->textu = sfTexture_createFromFile(TURRET_TWO_PRICE, NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    button->id = 2;
    return (data);
}

list_data_t *init_tower_three_hud(void)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    button->pos.x = TILE_WIDTH * 5;
    button->pos.y = (WINDOW_HEIGHT - (TILE_HEIGHT * 1.5));
    button->update = &select_check;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = &t_three;
    button->textu = sfTexture_createFromFile(TURRET_THREE_PRICE, NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    button->id = 3;
    return (data);
}

list_data_t *init_tower_four_hud(void)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    button->pos.x = TILE_WIDTH * 7;
    button->pos.y = (WINDOW_HEIGHT - (TILE_HEIGHT * 1.5));
    button->update = &select_check;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = &t_four;
    button->textu = sfTexture_createFromFile(TURRET_FOUR_PRICE, NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    button->id = 4;
    return (data);
}