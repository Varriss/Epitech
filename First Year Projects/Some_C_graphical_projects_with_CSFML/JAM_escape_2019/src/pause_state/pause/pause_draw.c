/*
** EPITECH PROJECT, 2020
** PAUSE_DRAW
** File description:
** Pause_draw function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_print.h"
#include "my_window.h"
#include "my_sprite.h"
#include "my_button.h"
#include "jam.h"

int pause_sreen_window(sfRenderWindow *window, pause_t *pause)
{
    sfImage *screen;

    if (!pause->bg_texture) {
        screen = sfRenderWindow_capture(window);
        if (!screen) {
            my_putstr_error("Screen capture fail\n");
            kill_game();
            return (EXIT_FAILURE);
        }
        pause->bg_texture = sfTexture_createFromImage(screen, NULL);
        sprite_set_texture(pause->bg_sprite, pause->bg_texture,
            WIDTH, HEIGHT);
        sfSprite_setColor(pause->bg_sprite, (sfColor){150, 150, 150, 255});
        sfImage_destroy(screen);
    }
    return (EXIT_SUCCESS);
}

void pause_draw(sfRenderWindow *window, pause_t *pause)
{
    if (!window || !pause)
        return;
    if (pause_sreen_window(window, pause))
        return;
    win_clear(window, sfGreen);
    win_draw_sprite(window, pause->bg_sprite);
    button_draw(window, pause->resume_button);
    button_draw(window, pause->restart_button);
    button_draw(window, pause->menu_button);
    button_draw(window, pause->quit_button);
    win_display(window);
}