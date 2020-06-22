/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019_2
** File description:
** menu_scene
*/

#include <stdlib.h>
#include "my_defender.h"

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
    backgr->destroy = &menu_back_destroy;
    backgr->render = &render_background;
    backgr->update = NULL;
    data->background = backgr;
    add_to_front(pause_scene, data);
}

void init_control_scene_background(list_t *list)
{
    backgr_t *backgr = malloc(sizeof(backgr_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    backgr->pos.x = 0;
    backgr->pos.y = 0;
    backgr->textu =
    sfTexture_createFromFile("Ressources/menu/howtoplay.png", NULL);
    backgr->type = background_type;
    backgr->sprite = sfSprite_create();
    sfSprite_setTexture(backgr->sprite, backgr->textu, sfTrue);
    sfSprite_setPosition(backgr->sprite, backgr->pos);
    backgr->destroy = &menu_back_destroy;
    backgr->render = &render_background;
    backgr->update = NULL;
    data->background = backgr;
    add_to_front(list, data);
}

void menu_back_destroy(prog_stat_t *prog_stat, backgr_t *background)
{
    sfSprite_destroy(background->sprite);
    sfTexture_destroy(background->textu);
    free(background);
}

void render_background(prog_stat_t *prog_stat, backgr_t *backgr)
{
    static int last_window = 0;

    if (prog_stat->scene_index == 2 && last_window == 1) {
        sfSprite_setTexture(backgr->sprite,
        prog_stat->last_window, sfTrue);
        sfSprite_setColor(backgr->sprite, (sfColor){255, 255, 255, 100});
    }
    last_window = prog_stat->scene_index;
    sfRenderWindow_drawSprite(prog_stat->window, backgr->sprite, NULL);
}

void init_menu_background(list_t *menu_scene)
{
    backgr_t *backgr = malloc(sizeof(backgr_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    backgr->pos.x = 0;
    backgr->pos.y = 0;
    backgr->textu =
    sfTexture_createFromFile("Ressources/menu/MenuBackground.png", NULL);
    backgr->type = background_type;
    backgr->sprite = sfSprite_create();
    sfSprite_setTexture(backgr->sprite, backgr->textu, sfTrue);
    sfSprite_setPosition(backgr->sprite, backgr->pos);
    backgr->destroy = &menu_back_destroy;
    backgr->render = &render_background;
    backgr->update = NULL;
    data->background = backgr;
    sfSprite_setColor(backgr->sprite, (sfColor){255, 255, 255,100});
    add_to_front(menu_scene, data);
}