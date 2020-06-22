/*
** EPITECH PROJECT, 2020
** GAMESTATE_MANAGER
** File description:
** Gamestate_manager header
*/

#ifndef GAMESTATE_MANAGER_H_
#define GAMESTATE_MANAGER_H_

///////////////////// PROTOTYPE /////////////////////

// menu
menu_t *menu_create(gamestate_manager_t *gsm);
void menu_handle_events(menu_t *menu, sfEvent event);
void menu_update(menu_t *menu);
void menu_draw(sfRenderWindow *window, menu_t *menu);
void *menu_destroy(menu_t *menu);

// game
game_t *game_create(gamestate_manager_t *gsm);
void game_handle_events(game_t *game, sfEvent event);
void game_update(game_t *game);
void game_draw(sfRenderWindow *window, game_t *game);
void *game_destroy(game_t *game);

// pause
pause_t *pause_create(gamestate_manager_t *gsm);
void pause_handle_events(pause_t *pause, sfEvent event);
void pause_update(pause_t *pause);
void pause_draw(sfRenderWindow *window, pause_t *pause);
void *pause_destroy(pause_t *pause);

// victory
victory_t *victory_create(gamestate_manager_t *gsm);
void victory_handle_events(victory_t *victory, sfEvent event);
void victory_update(victory_t *victory);
void victory_draw(sfRenderWindow *window, victory_t *victory);
void *victory_destroy(victory_t *victory);

// lose
lose_t *lose_create(gamestate_manager_t *gsm);
void lose_handle_events(lose_t *lose, sfEvent event);
void lose_update(lose_t *lose);
void lose_draw(sfRenderWindow *window, lose_t *lose);
void *lose_destroy(lose_t *lose);

//////////////////////// VAR ////////////////////////

static void *(* const CREATE_STATE_FUNCTIONS[6])(gamestate_manager_t *gsm) = {
    (void *(*)(gamestate_manager_t *))&menu_create,
    (void *(*)(gamestate_manager_t *))&game_create,
    (void *(*)(gamestate_manager_t *))&pause_create,
    (void *(*)(gamestate_manager_t *))&victory_create,
    (void *(*)(gamestate_manager_t *))&lose_create
};
static void (* const INPUT_STATE_FUNCTIONS[6])(void *, sfEvent) = {
    (void (*)(void *, sfEvent))&menu_handle_events,
    (void (*)(void *, sfEvent))&game_handle_events,
    (void (*)(void *, sfEvent))&pause_handle_events,
    (void (*)(void *, sfEvent))&victory_handle_events,
    (void (*)(void *, sfEvent))&lose_handle_events
};
static void (* const UPDATE_STATE_FUNCTIONS[6])(void *) = {
    (void (*)(void *))&menu_update,
    (void (*)(void *))&game_update,
    (void (*)(void *))&pause_update,
    (void (*)(void *))&victory_update,
    (void (*)(void *))&lose_update
};
static void (* const DRAW_STATE_FUNCTIONS[6])(sfRenderWindow *, void *) = {
    (void (*)(sfRenderWindow *, void *))&menu_draw,
    (void (*)(sfRenderWindow *, void *))&game_draw,
    (void (*)(sfRenderWindow *, void *))&pause_draw,
    (void (*)(sfRenderWindow *, void *))&victory_draw,
    (void (*)(sfRenderWindow *, void *))&lose_draw
};
static void *(* const DESTROY_STATE_FUNCTIONS[6])(void *) = {
    (void *(*)(void *))&menu_destroy,
    (void *(*)(void *))&game_destroy,
    (void *(*)(void *))&pause_destroy,
    (void *(*)(void *))&victory_destroy,
    (void *(*)(void *))&lose_destroy
};

#endif /* !GAMESTATE_MANAGER_H_ */