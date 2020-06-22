/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_envet_callbacks
*/

#include "my_rpg.h"

static void set_rotate_player(player_cursor_t *player, int x, int y
, prog_stat_t *prog)
{
    player->pos.x += x * TILE_WIDTH;
    player->pos.y += y * TILE_HEIGHT;
    if (x == 0)
        sfSprite_setRotation(player->sprite, (y == 1 ? 0 : 180));
    else if (y == 0)
        sfSprite_setRotation(player->sprite, (x == 1 ? -90 : 90));
    play_sound(walk, prog);
}

static int move_player_c(int x, int y, list_t *g_o_list, prog_stat_t *prog)
{
    sfVector2i current_pos;
    player_cursor_t *player = find_object(g_o_list,
    player_cursor_type)->data->player_c;
    tile_map_t *tilemap = find_object(g_o_list, tile_map_type)->data->tile_map;

    current_pos.x = (int)player->pos.x / TILE_WIDTH;
    current_pos.y = (int)player->pos.y / TILE_HEIGHT;
    if ((current_pos.x + x) >= MAP_WIDTH || (current_pos.y + y) >= MAP_HEIGHT
    || (current_pos.x + x) < 0 || (current_pos.y + y) < 0)
        return (FAILURE_CODE);
    if (tilemap->map[current_pos.y + y][current_pos.x + x] != 'X') {
        set_rotate_player(player, x, y, prog);
        player->current_tile =
        &(tilemap->map[current_pos.y + y][current_pos.x + x]);
        player->tile_ptr =
        &(tilemap->tiles[current_pos.y + y][current_pos.x + x]);
        manage_tilemap_actions(prog, player, g_o_list);
    }
    return (SUCCESS_CODE);
}

void direction_pressed(sfEvent *event, prog_stat_t *prog_stat,
list_t *g_o_list)
{
    if (prog_stat && (prog_stat->scene_index == game_scene)) {
        switch (event->key.code)
        {
        case sfKeyLeft:
            move_player_c(-1, 0, g_o_list, prog_stat);
            break;
        case sfKeyRight:
            move_player_c(1, 0, g_o_list, prog_stat);
            break;
        case sfKeyUp:
            move_player_c(0, -1, g_o_list, prog_stat);
            break;
        case sfKeyDown:
            move_player_c(0, 1, g_o_list, prog_stat);
            break;
        default:
            break;
        }
    }
    check_item_consumption(event, prog_stat, g_o_list);
}