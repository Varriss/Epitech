/*
** EPITECH PROJECT, 2020
** init_fight_scene.c
** File description:
** init_fight_scene
*/

#include <stdlib.h>
#include "my_rpg.h"

void set_turn(list_t *next_player)
{
    if (next_player->data != NULL) {
        if (next_player->data->enemy->type == enemy_type)
            next_player->data->enemy->turn = 1;
        else {
            next_player->data->player->turn = 1;
            next_player->data->player->defense = 0;
        }
    }
}

void set_next_turn(list_t *actual_player)
{
    list_t *next_player = actual_player->prev;
    int stop = 0;

    if (actual_player->data->enemy->type == enemy_type)
        actual_player->data->enemy->turn = 0;
    else
        actual_player->data->player->turn = 0;
    for (; (next_player != actual_player && stop == 0)
    ; next_player = next_player->prev) {
        if (next_player->data != NULL && ((next_player->data->button->type
        == enemy_type) || (next_player->data->button->type == player_type))) {
            set_turn(next_player);
            stop = 1;
        }
    }
}

static void init_fight_background(list_t *fight_scene)
{
    backgr_t *backgr = malloc(sizeof(backgr_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    backgr->pos.x = 0;
    backgr->pos.y = 0;
    backgr->textu = sfTexture_createFromFile(PATH_FIGHT, NULL);
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

list_t *init_fight_scene(list_t *game_scene)
{
    list_t *fight_scene = create_list();

    init_player(fight_scene, game_scene);
    init_enemy(fight_scene);
    init_fight_background(fight_scene);
    return (fight_scene);
}