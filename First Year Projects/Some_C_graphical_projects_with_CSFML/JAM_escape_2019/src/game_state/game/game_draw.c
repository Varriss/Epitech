/*
** EPITECH PROJECT, 2020
** GAME_DRAW
** File description:
** Game_draw function
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include "my_math.h"
#include "my_button.h"
#include "my_tilemap.h"
#include "my_window.h"
#include "my_clock.h"
#include "tilemap.h"
#include "jam.h"
#include "my_str.h"
#include "entity.h"

static void win_draw_time(sfRenderWindow *window, game_t *game)
{
    static sfText *time = NULL;
    char *display = NULL;
    static int seconds_left = 360;

    if (time == NULL)
        time = init_text();
    seconds_left = 360 - clock_get_s(game->global_clock); 
    display = my_strcat("Time left\t", int_to_str(seconds_left / 60));
    display = my_strcat(display, " min ");
    display = my_strcat(display, int_to_str(seconds_left % 60));
    sfText_setString(time, display);
    sfRenderWindow_drawText(window, time, NULL);
    free(display);
}

void game_draw(sfRenderWindow *window, game_t *game)
{
    if (!game || !window)
        return;
    win_clear(window, sfGreen);
    win_draw_sprite(window, game->bg_sprite);
    tilemap_draw_layer(window, game->tilemap, MAP_LAYER);
    player_draw(window, game->player);
    win_draw_sprite(window, game->blur_fg_sprite);
    win_draw_time(window, game);
    win_display(window);
}