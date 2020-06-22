/*
** EPITECH PROJECT, 2020
** victory.c
** File description:
** victory
*/

#include <stdlib.h>
#include "my_rpg.h"

void back_tomap(prog_stat_t *prog_stat, button_t *button, list_t *scene,
sfEvent *eve)
{
    if (eve && button && scene)
        prog_stat->scene_index = game_scene;
}

static void init_backtogame_button(list_t *fight_scene)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));
    sfIntRect rect = {0, 0, 181, 181};

    button->rect = rect;
    button->pos.x = 900;
    button->pos.y = 800;
    button->update = NULL;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = &back_tomap;
    button->textu = sfTexture_createFromFile(BACK_TOGAME_BUTTON, NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setScale(button->sprite, (sfVector2f){0.5, 0.5});
    data->button = button;
    add_to_queue(fight_scene, data);
}

static void init_victory_backgr(list_t *fight_scene)
{
    backgr_t *backgr = malloc(sizeof(backgr_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    backgr->pos.x = 400;
    backgr->pos.y = 100;
    backgr->textu = sfTexture_createFromFile(VICTORY, NULL);
    backgr->type = background_type;
    backgr->sprite = sfSprite_create();
    sfSprite_setTexture(backgr->sprite, backgr->textu, sfTrue);
    sfSprite_setPosition(backgr->sprite, backgr->pos);
    sfSprite_setScale(backgr->sprite, (sfVector2f){1.5, 1.5});
    backgr->destroy = &backgr_destroy;
    backgr->render = &render_background;
    backgr->update = NULL;
    data->background = backgr;
    add_to_queue(fight_scene, data);
}

list_t *victory_init(void)
{
    list_t *victory_list = create_list();

    init_backtogame_button(victory_list);
    init_victory_backgr(victory_list);
    return (victory_list);
}