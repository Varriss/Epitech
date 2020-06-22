/*
** EPITECH PROJECT, 2019
** WINDOW
** File description:
** Window
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include "my_window.h"

sfRenderWindow *win_create(int width, int height,
    char const *name, int const framerate_limit)
{
    sfRenderWindow *window = NULL;
    sfVideoMode vm = {width, height, 32};

    window = sfRenderWindow_create(vm, name, sfClose | sfResize, NULL);
    if (!window)
        return (NULL);
    if (framerate_limit > 0)
        sfRenderWindow_setFramerateLimit(window, framerate_limit);
    return (window);
}

int win_is_open(sfRenderWindow *window)
{
    if (!window)
        return (0);
    return (sfRenderWindow_isOpen(window));
}

void *win_destroy(sfRenderWindow *window)
{
    if (window)
        sfRenderWindow_destroy(window);
    return (NULL);
}

void win_handle_events(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}