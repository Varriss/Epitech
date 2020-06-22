/*
** EPITECH PROJECT, 2020
** init_fight_scene.c
** File description:
** init_fight_scene
*/

#include <stdlib.h>
#include "my_rpg.h"

static void init_boss_background(list_t *fight_scene)
{
    backgr_t *backgr = malloc(sizeof(backgr_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    backgr->pos.x = 0;
    backgr->pos.y = 0;
    backgr->textu = sfTexture_createFromFile(BOSS_BACKGROUND, NULL);
    backgr->type = background_type;
    backgr->sprite = sfSprite_create();
    sfSprite_setTexture(backgr->sprite, backgr->textu, sfTrue);
    sfSprite_setPosition(backgr->sprite, backgr->pos);
    backgr->destroy = &backgr_destroy;
    backgr->render = &render_background;
    backgr->update = NULL;
    data->background = backgr;
    add_to_front(fight_scene, data);
}

list_t *init_boss_scene(list_t *game_scene)
{
    list_t *boss_scene = create_list();

    init_player(boss_scene, game_scene);
    init_boss(boss_scene);
    init_boss_background(boss_scene);
    return (boss_scene);
}