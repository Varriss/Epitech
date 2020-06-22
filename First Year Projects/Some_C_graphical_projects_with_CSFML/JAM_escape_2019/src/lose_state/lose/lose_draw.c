/*
** EPITECH PROJECT, 2020
** LOSE_DRAW
** File description:
** Lose_draw function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_print.h"
#include "my_sprite.h"
#include "my_window.h"
#include "my_button.h"
#include "jam.h"

int lose_sreen_window(sfRenderWindow *window, lose_t *lose)
{
    sfImage *screen;

    if (!lose->bg_texture) {
        screen = sfRenderWindow_capture(window);
        if (!screen) {
            my_putstr_error("Screen capture fail\n");
            kill_game();
            return (EXIT_FAILURE);
        }
        lose->bg_texture = sfTexture_createFromImage(screen, NULL);
        sprite_set_texture(lose->bg_sprite, lose->bg_texture,
            WIDTH, HEIGHT);
        sfImage_destroy(screen);
    }
    return (EXIT_SUCCESS);
}

void lose_draw(sfRenderWindow *window, lose_t *lose)
{
    int time = clock_get_ms(lose->clock);
    int grey = 255 - (time / 6 > 150 ? 150 : time / 6);

    if (!window || !lose)
        return;
    if (lose_sreen_window(window, lose))
        return;
    win_clear(window, sfGreen);
    sfSprite_setColor(lose->bg_sprite, (sfColor){grey, grey, grey, 255});
    win_draw_sprite(window, lose->bg_sprite);
    if (time > 2500)
        win_draw_sprite(window, lose->wasted_sprite);
    //button_draw(window, lose->menu_button);
    win_display(window);
}