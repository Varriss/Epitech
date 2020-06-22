/*
** EPITECH PROJECT, 2020
** PLAYER_HANDLE_EVENTS
** File description:
** Player_handle_events function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_audio.h"
#include "my_tileset.h"
#include "my_tilemap.h"
#include "my_clock.h"
#include "tilemap.h"
#include "jam.h"
#include "entity.h"

void player_handle_events(player_t *player, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyUp || event.key.code == sfKeyZ)
            player->vertical_move = -1;
        if (event.key.code == sfKeyRight || event.key.code == sfKeyD)
            player->horizontal_move = 1;
        if (event.key.code == sfKeyDown || event.key.code == sfKeyS)
            player->vertical_move = 1;
        if (event.key.code == sfKeyLeft || event.key.code == sfKeyQ)
            player->horizontal_move = -1;
    }
    if (event.type == sfEvtKeyReleased) {
        if (event.key.code == sfKeyUp || event.key.code == sfKeyZ)
            player->vertical_move = 0;
        if (event.key.code == sfKeyRight || event.key.code == sfKeyD)
            player->horizontal_move = 0;
        if (event.key.code == sfKeyDown || event.key.code == sfKeyS)
            player->vertical_move = 0;
        if (event.key.code == sfKeyLeft || event.key.code == sfKeyQ)
            player->horizontal_move = 0;
    }
}