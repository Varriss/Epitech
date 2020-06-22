/*
** EPITECH PROJECT, 2019
** WINDOW_DISPLAY
** File description:
** Window display
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include "my_window.h"

void win_clear(sfRenderWindow *window, sfColor color)
{
    sfRenderWindow_clear(window, color);
}

void win_draw_sprite(sfRenderWindow *window, sfSprite *sprite)
{
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void win_display(sfRenderWindow *window)
{
    sfRenderWindow_display(window);
}