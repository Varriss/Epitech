/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** defeat_scene
*/

#include <stdlib.h>
#include "my_defender.h"

static void destroy_defeat_bg(prog_stat_t *prog_stat, backgr_t *defeat_bg)
{
    sfSprite_destroy(defeat_bg->sprite);
    sfTexture_destroy(defeat_bg->textu);
    free(defeat_bg);
}

static list_data_t *init_defeat_background(void)
{
    list_data_t *defeat_bg_elem = malloc(sizeof(list_data_t));
    backgr_t *defeat_bg = malloc(sizeof(backgr_t));
    sfVector2f pos = {0, 0};

    defeat_bg->pos = pos;
    defeat_bg->textu = sfTexture_createFromFile("Ressources/menu/defeat_bg.png",
    NULL);
    defeat_bg->sprite = sfSprite_create();
    sfSprite_setTexture(defeat_bg->sprite, defeat_bg->textu, sfTrue);
    sfSprite_setPosition(defeat_bg->sprite, defeat_bg->pos);
    defeat_bg->update = NULL;
    defeat_bg->render = &render_background;
    defeat_bg->destroy = &destroy_defeat_bg;
    defeat_bg_elem->background = defeat_bg;
    return (defeat_bg_elem);
}

static list_data_t *init_quit_button(void)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    button->pos.x = ((WINDOW_WIDTH / 2) - (MENU_ICON_WIDTH / 2));
    button->pos.y = (WINDOW_HEIGHT - 175) - (MENU_ICON_HEIGHT / 2);
    button->update = NULL;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = &quit_game;
    button->textu = sfTexture_createFromFile("Ressources/buttons/quit.png",
    NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    return (data);
}

static void init_defeat_buttons(list_t *defeat_scene)
{
    add_to_front(defeat_scene, init_main_menu_button());
    add_to_front(defeat_scene, init_quit_button());
}

list_t *init_defeat_scene(void)
{
    list_t *defeat_scene = create_list();

    init_defeat_buttons(defeat_scene);
    add_to_front(defeat_scene, init_defeat_background());
    return (defeat_scene);
}