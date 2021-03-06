/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** how_too
*/

#include "my_rpg.h"

void switch_to_how_to(prog_stat_t *prog_stat, button_t *button
, list_t *scene, sfEvent *eve)
{
    if (button || scene || eve)
        prog_stat->scene_index = how_to_play_scene;
    sfMusic_pause(get_music_sound_cursor(prog_stat->musics_sounds->musics_list
    , menu_background_music)->data->music->music);
    play_sound(button_click, prog_stat);
}

list_data_t *init_how_to_button(void)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));
    sfIntRect rect = {0, 0, MENU_ICON_WIDTH, MENU_ICON_HEIGHT};

    button->pos.x = ((WINDOW_WIDTH / 2) - (MENU_ICON_WIDTH / 2)) / 2;
    button->pos.y = ((WINDOW_HEIGHT / 6) * 3) - (MENU_ICON_HEIGHT / 2);
    button->rect = rect;
    button->update = NULL;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = &switch_to_how_to;
    button->textu = sfTexture_createFromFile(MENU_HOW_TO_BUTTON, NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    return (data);
}