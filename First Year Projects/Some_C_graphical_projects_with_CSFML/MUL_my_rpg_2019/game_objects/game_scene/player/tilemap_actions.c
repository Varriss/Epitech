/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** tilemap_actions
*/

#include "my_rpg.h"

static tmap_scene_t tilemap_actions[7] = {
    {'U', NULL, game_scene},
    {'D', &load_next_level, game_scene},
    {'*', NULL, game_scene},
    {'S', NULL, shop_scene},
    {'B', &boss_load, boss_scene},
    {'T', &destroy_trap, fight_scene},
    {'C', &chest_loot, game_scene}
};

void load_next_level(prog_stat_t *prog_stat, player_cursor_t *player_c,
list_t *go_list)
{
    reload_map(prog_stat, go_list);
    player_c->current_tile = NULL;
}

void boss_load(prog_stat_t *prog_stat, player_cursor_t *player_c,
list_t *go_list)
{
    if (prog_stat && go_list)
        switch_tile_to_path(player_c);
}

void destroy_trap(prog_stat_t *prog_stat, player_cursor_t *player_c,
list_t *go_list)
{
    if (prog_stat && go_list)
        switch_tile_to_path(player_c);
}

void manage_tilemap_actions(prog_stat_t *prog_stat, player_cursor_t *player_c,
list_t *go_list)
{
    for (int i = 0; i < 7; i++) {
        if (player_c->current_tile &&
        *(player_c->current_tile) == tilemap_actions[i].tile_id) {
            if (tilemap_actions[i].tile_action)
                tilemap_actions[i].tile_action(prog_stat, player_c, go_list);
            prog_stat->scene_index = tilemap_actions[i].scene_id;
        }
    }
}