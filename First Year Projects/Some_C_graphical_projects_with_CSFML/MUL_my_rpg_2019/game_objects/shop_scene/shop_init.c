/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** shop_init
*/

#include "my_rpg.h"

void back_to_game(prog_stat_t *prog_stat, struct button *button,
list_t *game_scen, sfEvent *eve)
{
    if (game_scen && eve && prog_stat && button)
        prog_stat->scene_index = game_scene;
}

static void init_background(list_t *shop_scen)
{
    backgr_t *backgr = malloc(sizeof(backgr_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    backgr->pos.x = 0;
    backgr->pos.y = 0;
    backgr->textu = sfTexture_createFromFile(SHOP_BACKGROUND, NULL);
    backgr->type = background_type;
    backgr->sprite = sfSprite_create();
    sfSprite_setTexture(backgr->sprite, backgr->textu, sfTrue);
    sfSprite_setPosition(backgr->sprite, backgr->pos);
    backgr->destroy = &backgr_destroy;
    backgr->render = &render_default_background;
    backgr->update = NULL;
    data->background = backgr;
    add_to_front(shop_scen, data);
}

void init_customer_interact(list_t *shop_scen, list_t *game_scene)
{
    customer_t *shop = malloc(sizeof(backgr_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    shop->type = customer_type;
    shop->inventory = find_object(game_scene
    , player_cursor_type)->data->player_c->inventory;
    shop->monologus_pos = (sfVector2f) {200, 100};
    data->customer_api = shop;
    shop->update = NULL;
    shop->render = NULL;
    shop->destroy = NULL;
    add_to_front(shop_scen, data);
}

static void init_back_to_game_button(list_t *shop_scen)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));
    sfIntRect rect = {0, 0, MENU_ICON_WIDTH, MENU_ICON_HEIGHT};

    button->pos.x = ((WINDOW_WIDTH / 2) - (MENU_ICON_WIDTH / 2)) / 2;
    button->pos.y = ((WINDOW_HEIGHT / 6) * 4) - (MENU_ICON_HEIGHT / 2);
    button->rect = rect;
    button->update = NULL;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = &back_to_game;
    button->textu = sfTexture_createFromFile(MENU_QUIT_BUTTON, NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    add_to_queue(shop_scen, data);
}

    /* init_customer_interact(shop_scene, game_scene); */

list_t *init_shop_scene(list_t *game_scene)
{
    list_t *shop_scen = create_list();

    if (game_scene)
        init_back_to_game_button(shop_scen);
    init_background(shop_scen);
    return (shop_scen);
}