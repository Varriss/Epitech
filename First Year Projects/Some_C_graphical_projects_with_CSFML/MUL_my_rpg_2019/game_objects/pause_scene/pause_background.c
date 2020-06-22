/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_background
*/

#include <stdlib.h>
#include "my_rpg.h"

void render_pause_background(prog_stat_t *prog_stat, backgr_t *backgr)
{
    sfSprite_setTexture(backgr->sprite,
    prog_stat->last_window, sfTrue);
    sfSprite_setColor(backgr->sprite, (sfColor){255, 255, 255, 100});
    sfRenderWindow_setView(prog_stat->window,
    sfRenderWindow_getDefaultView(prog_stat->window));
    sfRenderWindow_drawSprite(prog_stat->window, backgr->sprite, NULL);
}

void init_pause_scene_background(list_t *pause_scene)
{
    backgr_t *backgr = malloc(sizeof(backgr_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    backgr->pos.x = 0;
    backgr->pos.y = 0;
    backgr->textu = NULL;
    backgr->type = background_type;
    backgr->sprite = sfSprite_create();
    sfSprite_setPosition(backgr->sprite, backgr->pos);
    backgr->destroy = &backgr_destroy;
    backgr->render = &render_pause_background;
    backgr->update = NULL;
    data->background = backgr;
    add_to_front(pause_scene, data);
}