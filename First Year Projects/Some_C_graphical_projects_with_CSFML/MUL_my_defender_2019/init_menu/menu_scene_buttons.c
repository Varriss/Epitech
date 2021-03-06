/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019_2
** File description:
** menu_scene_buttons
*/

#include <stdlib.h>
#include "my_defender.h"

static list_data_t *init_controls_button(void)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    button->pos.x = ((WINDOW_WIDTH / 2) - (MENU_ICON_WIDTH / 2)) / 2;
    button->pos.y = ((WINDOW_HEIGHT / 6) * 3) - (MENU_ICON_HEIGHT / 2);
    button->update = NULL;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = &get_controls;
    button->textu = sfTexture_createFromFile("Ressources/buttons/controls.png",
    NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    return (data);
}

static list_data_t *init_quit_button(void)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    button->pos.x = ((WINDOW_WIDTH / 2) - (MENU_ICON_WIDTH / 2)) / 2;
    button->pos.y = ((WINDOW_HEIGHT / 6) * 4) - (MENU_ICON_HEIGHT / 2);
    button->update = NULL;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = &quit_game;
    button->textu = sfTexture_createFromFile("Ressources/buttons/quit.png"
    , NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    return (data);
}

static list_data_t *init_start_button(void)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    button->pos.x = ((WINDOW_WIDTH / 2) - (MENU_ICON_WIDTH / 2)) / 2;
    button->pos.y = ((WINDOW_HEIGHT / 6) * 2) - (MENU_ICON_HEIGHT / 2);
    button->update = NULL;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = &start_game;
    button->textu = sfTexture_createFromFile("Ressources/buttons/start.png"
    , NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    return (data);
}

void init_menu_buttons(list_t *menu_scene)
{
    add_to_front(menu_scene, init_controls_button());
    add_to_front(menu_scene, init_start_button());
    add_to_front(menu_scene, init_quit_button());
}