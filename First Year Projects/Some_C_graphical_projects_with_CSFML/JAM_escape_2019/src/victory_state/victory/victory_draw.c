/*
** EPITECH PROJECT, 2020
** VICTORY_DRAW
** File description:
** Victory_draw function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_print.h"
#include "my_sprite.h"
#include "my_window.h"
#include "my_button.h"
#include "jam.h"

int victory_sreen_window(sfRenderWindow *window, victory_t *victory)
{
    sfImage *screen;

    if (!victory->bg_texture) {
        screen = sfRenderWindow_capture(window);
        if (!screen) {
            my_putstr_error("Screen capture fail\n");
            kill_game();
            return (EXIT_FAILURE);
        }
        victory->bg_texture = sfTexture_createFromImage(screen, NULL);
        sprite_set_texture(victory->bg_sprite, victory->bg_texture,
            WIDTH, HEIGHT);
        sfImage_destroy(screen);
    }
    return (EXIT_SUCCESS);
}

void victory_draw(sfRenderWindow *window, victory_t *victory)
{
    int time = clock_get_ms(victory->clock);
    int grey = 255 - (time / 6 > 150 ? 150 : time / 6);

    if (!window || !victory)
        return;
    if (victory_sreen_window(window, victory))
        return;
    win_clear(window, sfGreen);
    sfSprite_setColor(victory->bg_sprite, (sfColor){grey, grey, grey, 255});
    win_draw_sprite(window, victory->bg_sprite);
    if (time > 2500)
        win_draw_sprite(window, victory->wasted_sprite);
    //button_draw(window, victory->menu_button);
    win_display(window);
}