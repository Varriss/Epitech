/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_scenes
*/

#include "my_rpg.h"

sfText *init_text(sfVector2f pos, int size)
{
    sfText *text = sfText_create();
    static sfFont *font = NULL;

    if (font == NULL)
        font = sfFont_createFromFile(FONT_STYLE_ONE);
    sfText_setColor(text, sfWhite);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    return (text);
}

list_t **init_scenes(void)
{
    list_t **scenes_list = malloc(sizeof(list_t *) * NB_SCENES);

    scenes_list[menu_scene] = init_menu_scene();
    scenes_list[game_scene] = init_game_scene();
    scenes_list[fight_scene] = init_fight_scene(scenes_list[game_scene]);
    scenes_list[boss_scene] = init_boss_scene(scenes_list[game_scene]);
    scenes_list[shop_scene] = init_shop_scene(scenes_list[game_scene]);
    scenes_list[victory_scene] = victory_init();
    scenes_list[game_over_scene] = game_over_scene_init();
    scenes_list[how_to_play_scene] = init_how_to_scene();
    scenes_list[pause_scene] = init_pause_scene();
    return (scenes_list);
}