/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019_2
** File description:
** init_scenes
*/

#include <stdlib.h>
#include "my_defender.h"

static list_t *init_menu_scene(void)
{
    list_t *menu_scene = create_list();

    init_menu_buttons(menu_scene);
    init_menu_background(menu_scene);
    return (menu_scene);
}

static list_t *init_game_scene(void)
{
    list_t *game_scene = create_list();

    initialize_hud(game_scene);
    initialize_map(game_scene);
    init_level(game_scene);
    return (game_scene);
}

static list_t *init_pause_scene(void)
{
    list_t *pause_scene = create_list();

    init_pause_scene_buttons(pause_scene);
    init_pause_scene_background(pause_scene);
    return (pause_scene);
}

list_t *init_controls_scene(void)
{
    list_t *pause_scene = create_list();

    init_control_scene_background(pause_scene);
}

list_t **init_scenes(void)
{
    list_t **scenes = malloc(sizeof(list_t *) * NB_SCENES);

    if (!scenes)
        return (NULL);
    scenes[0] = init_menu_scene();
    scenes[1] = init_game_scene();
    scenes[2] = init_pause_scene();
    scenes[3] = init_defeat_scene();
    scenes[4] = init_controls_scene();
    return (scenes);
}