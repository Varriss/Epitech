/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_over
*/

#include "my_rpg.h"

static void init_quit_button(list_t *fight_scene)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));
    sfIntRect rect = {0, 0, MENU_ICON_WIDTH, MENU_ICON_HEIGHT};

    button->rect = rect;
    button->pos.x = 650;
    button->pos.y = 600;
    button->update = NULL;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = &quit_game;
    button->textu = sfTexture_createFromFile(MENU_QUIT_BUTTON, NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    add_to_queue(fight_scene, data);
}

static void init_loose_backgr(list_t *fight_scene)
{
    backgr_t *backgr = malloc(sizeof(backgr_t));
    list_data_t *data = malloc(sizeof(list_data_t));
    sfVector2f scale = {1.5, 1.5};

    backgr->pos.x = 400;
    backgr->pos.y = 30;
    backgr->textu = sfTexture_createFromFile(GAME_OVER, NULL);
    backgr->type = background_type;
    backgr->sprite = sfSprite_create();
    sfSprite_setTexture(backgr->sprite, backgr->textu, sfTrue);
    sfSprite_setScale(backgr->sprite, scale);
    sfSprite_setPosition(backgr->sprite, backgr->pos);
    backgr->destroy = &backgr_destroy;
    backgr->render = &render_background;
    backgr->update = NULL;
    data->background = backgr;
    add_to_queue(fight_scene, data);
}

list_t * game_over_scene_init(void)
{
    list_t *game_over_list = create_list();

    init_loose_backgr(game_over_list);
    init_quit_button(game_over_list);
    return (game_over_list);
}