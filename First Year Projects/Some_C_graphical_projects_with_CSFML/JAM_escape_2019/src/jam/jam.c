/*
** EPITECH PROJECT, 2020
** JAM
** File description:
** Jam function
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_gamestate_manager.h"
#include "my_window.h"
#include "jam.h"
#include "gamestate_manager.h"

void fix_mouse(sfEvent *event)
{
    static int window_width = WIDTH;
    static int window_height = HEIGHT;
    float x_scale = WIDTH / (float)window_width;
    float y_scale = HEIGHT / (float)window_height;

    if (event->type == sfEvtResized) {
        window_width = event->size.width;
        window_height = event->size.height;
    }
    if (event->type == sfEvtMouseMoved) {
        event->mouseMove.x *= x_scale;
        event->mouseMove.y *= y_scale;
    }
    if (event->type == sfEvtMouseButtonPressed
        || event->type == sfEvtMouseButtonReleased) {
        event->mouseButton.x *= x_scale;
        event->mouseButton.y *= y_scale;
    }
}

void game_check_key(sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyM)
        set_game_mute(!is_game_mute());
}

int game_loop(sfRenderWindow *window, gamestate_manager_t *gsm)
{
    sfEvent event;

    while (win_is_open(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            fix_mouse(&event);
            game_check_key(event);
            win_handle_events(window, event);
            gamestate_manager_handle_events(gsm, event);
        }
        gamestate_manager_update(gsm);
        gamestate_manager_draw(window, gsm);
        if (gsm->current_state != -1
            && !gsm->current_state_data[gsm->current_state])
            sfRenderWindow_close(window);
        if (is_game_kill())
            sfRenderWindow_close(window);
    }
    return (EXIT_SUCCESS);
}

gamestate_manager_t *init_gsm()
{
    gamestate_manager_t *gsm = gamestate_manager_create(GAMESTATE_COUNT);

    if (!gsm)
        return (NULL);
    gamestate_manager_add_constructor_functions(gsm,
        CREATE_STATE_FUNCTIONS, DESTROY_STATE_FUNCTIONS);
    gamestate_manager_add_update_functions(gsm, INPUT_STATE_FUNCTIONS,
        UPDATE_STATE_FUNCTIONS, DRAW_STATE_FUNCTIONS);
    if (gamestate_manager_set_state(gsm, START_STATE, 1))
        return (gamestate_manager_destroy(gsm));
    return (gsm);
}

int jam(void)
{
    int return_value;
    sfRenderWindow *window = NULL;
    gamestate_manager_t *gsm = init_gsm();

    if (!gsm)
        return (84);
    window = win_create(WIDTH, HEIGHT, NAME, FRAME_RATE);
    if (!window) {
        gamestate_manager_destroy(gsm);
        return (84);
    }
    return_value = game_loop(window, gsm);
    gamestate_manager_destroy(gsm);
    win_destroy(window);
    return (return_value);
}