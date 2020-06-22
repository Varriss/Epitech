/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** buttons
*/

#include <stdlib.h>
#include "my_defender.h"

char *int_to_str_conv(int nb, char *result)
{
    int display;
    char *disp = malloc(2);

    disp[1] = '\0';
    if (nb >= 10) {
        display = nb % 10;
        nb = nb / 10;
        result = int_to_str_conv(nb, result);
        disp[0] = display + '0';
        result = my_strcat(result, disp);
    } else if (nb < 10) {
        disp[0] = nb + '0';
        result = my_strcat(result, disp);
    }
    return (result);
}

list_data_t *init_start_hud(void)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    button->pos.x = WINDOW_WIDTH - (MENU_ICON_WIDTH * 1.1);
    button->pos.y = (WINDOW_HEIGHT - (MENU_ICON_HEIGHT * 1.65 * 2));
    button->update = NULL;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = &manage_waves;
    button->textu = sfTexture_createFromFile(
    "Ressources/buttons/start_wave.png", NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    return (data);
}

list_data_t *init_quit_hud(void)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    button->pos.x = WINDOW_WIDTH - (MENU_ICON_WIDTH * 1.1);
    button->pos.y = (WINDOW_HEIGHT - (MENU_ICON_HEIGHT * 1.5));
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

list_data_t *init_sell_hud(void)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    button->pos.x = WINDOW_WIDTH - (MENU_ICON_WIDTH * 3.7);
    button->pos.y = (WINDOW_HEIGHT - (MENU_ICON_HEIGHT * 1.8));
    button->update = NULL;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = NULL;
    button->textu = sfTexture_createFromFile("Ressources/buttons/sell.png"
    , NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    return (data);
}