/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** button_game_menu
*/

#include <stdlib.h>
#include "my_defender.h"

static list_data_t *init_resume_button(void)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    button->pos.x = ((WINDOW_WIDTH / 2) - (MENU_ICON_WIDTH / 2)) / 2;
    button->pos.y = (WINDOW_HEIGHT - 225) - MENU_ICON_HEIGHT;
    button->update = NULL;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = &start_game;
    button->textu = sfTexture_createFromFile("Ressources/buttons/resume.png",
    NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    return (data);
}

list_data_t *init_main_menu_button(void)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    button->pos.x = ((WINDOW_WIDTH / 2) - (MENU_ICON_WIDTH / 2));
    button->pos.y = (WINDOW_HEIGHT - 225) - MENU_ICON_HEIGHT;
    button->update = NULL;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = &main_menu;
    button->textu = sfTexture_createFromFile(
    "Ressources/buttons/main_menu.png", NULL);
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

    button->pos.x = ((WINDOW_WIDTH / 2) - (MENU_ICON_WIDTH / 2)) * 1.5;
    button->pos.y = (WINDOW_HEIGHT - 225) - MENU_ICON_HEIGHT;
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

static list_data_t *init_pause_title(void)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    button->pos.x = ((WINDOW_WIDTH / 2) - 300);
    button->pos.y = MENU_ICON_HEIGHT * 1.2;
    button->update = NULL;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = NULL;
    button->textu = sfTexture_createFromFile("Ressources/HUD/game_paused.png",
    NULL);
    button->type = background_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    return (data);
}

void init_pause_scene_buttons(list_t *pause_scene)
{
    add_to_front(pause_scene, init_resume_button());
    add_to_front(pause_scene, init_main_menu_button());
    add_to_front(pause_scene, init_quit_button());
    add_to_front(pause_scene, init_pause_title());
}