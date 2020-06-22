/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_callbacks
*/

#include "my_rpg.h"

void quit_game(prog_stat_t *prog_stat, button_t *button, list_t *scene,
sfEvent *eve)
{
    if (button || scene || eve)
        prog_stat->running = 0;
}

void start_game(prog_stat_t *prog_stat, button_t *button, list_t *scene,
sfEvent *eve)
{
    if (button || scene || eve)
        prog_stat->scene_index = game_scene;
    sfMusic_pause(get_music_sound_cursor(prog_stat->musics_sounds->musics_list
    , menu_background_music)->data->music->music);
}

void main_menu(prog_stat_t *prog_stat, button_t *button, list_t *scene,
sfEvent *eve)
{
    if (prog_stat || button || scene || eve)
        prog_stat->scene_index = menu_scene;
}