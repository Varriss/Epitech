/*
** EPITECH PROJECT, 2019
** BACKGROUND_DRAW
** File description:
** Background_draw funcion
*/

#include <SFML/Graphics.h>
#include "my_clock.h"
#include "my_background.h"
#include "my_window.h"

void background_draw(sfRenderWindow *window,
    background_t *background, int frame)
{
    int x;
    int width;
    sfVector2f pos = {0, 0};

    for (int id = 0; id < background->nb_layer; id++) {
        if (!background->sprites[id])
            continue;
        width = sfTexture_getSize(background->textures[id]).x;
        width = width * sfSprite_getScale(background->sprites[id]).x;
        x = (-(sfInt64)(background->vx[id] * frame / 1000)) % width;
        pos.x = x;
        sfSprite_setPosition(background->sprites[id], pos);
        win_draw_sprite(window, background->sprites[id]);
        while (x + width <= background->frame_width) {
            x += width;
            pos.x = x;
            sfSprite_setPosition(background->sprites[id], pos);
            win_draw_sprite(window, background->sprites[id]);
        }
    }
}

void background_draw_clock(sfRenderWindow *window,
    background_t *background, my_clock_t *clock)
{
    int ms = clock_get_ms(clock);

    background_draw(window, background, ms);
}