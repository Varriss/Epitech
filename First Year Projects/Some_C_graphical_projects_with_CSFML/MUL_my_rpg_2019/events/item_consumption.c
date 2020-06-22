/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** item_consumption
*/

#include <stdlib.h>
#include "my_rpg.h"

void check_pause(prog_stat_t *prog_stat, sfEvent *event, list_t *scene)
{
    if (event->key.code == sfKeyEscape && scene)
    {
        if (prog_stat->scene_index == game_scene
        || prog_stat->scene_index == fight_scene)
        {
            sfTexture_updateFromRenderWindow(prog_stat->last_window,
            prog_stat->window, 0, 0);
            prog_stat->prev_index = prog_stat->scene_index;
            prog_stat->scene_index = pause_scene;
        } else if (prog_stat->scene_index == pause_scene
        && (prog_stat->prev_index != pause_scene)) {
            prog_stat->scene_index = prog_stat->prev_index;
            prog_stat->prev_index = pause_scene;
        }
    }
}

void check_attack(prog_stat_t *prog_stat, sfEvent *event, list_t *scene)
{
    if (((prog_stat->scene_index == fight_scene)
    || (prog_stat->scene_index == boss_scene))
    && ((event->key.code == sfKeyNum2) || (event->key.code) == sfKeyNum3)) {
        if (event->key.code == sfKeyNum3)
            find_object(scene, player_type)->data->player->defense = 1;
        attack_attack(prog_stat, scene, event);
    }
}

void check_item_consumption(sfEvent *event, prog_stat_t *prog_stat,
list_t *scene)
{
    list_t *player_c = find_object(scene, player_cursor_type);
    list_t *player = find_object(scene, player_type);
    inventory_t *inventory = NULL;

    if (prog_stat->scene_index == game_scene
    || prog_stat->scene_index == fight_scene
    || prog_stat->scene_index == boss_scene)
    {
        inventory = (player_c ? player_c->data->player_c->inventory
        : player->data->player->inventory);
        if (event->key.code == sfKeyNum1)
        {
            inventory->items[0]->potion->onuse(prog_stat,
            inventory->items[0]->potion, scene);
        }
    }
    check_attack(prog_stat, event, scene);
    check_pause(prog_stat, event, scene);
}