/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_scene
*/

#include <stdlib.h>
#include "my_rpg.h"

void come_back_to_scene(prog_stat_t *prog_stat, struct button *button,
list_t *game_scene, sfEvent *eve)
{
    if (button || game_scene || eve)
        prog_stat->scene_index = prog_stat->prev_index;
    play_sound(button_click, prog_stat);
}

list_t *init_pause_scene(void)
{
    list_t *pause_scene = create_list();

    init_pause_scene_buttons(pause_scene);
    init_pause_scene_background(pause_scene);
    return (pause_scene);
}