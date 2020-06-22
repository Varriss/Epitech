/*
** EPITECH PROJECT, 2020
** MY_GAMESTATE_MANAGER
** File description:
** My_gamestate_manager header
*/

#ifndef MY_GAMESTATE_MANAGER_H_
#define MY_GAMESTATE_MANAGER_H_

//////////////////////// VAR ////////////////////////

// def struct
typedef struct sfRenderWindow sfRenderWindow;
typedef struct gamestate_manager_s gamestate_manager_t;

// struct
struct gamestate_manager_s
{
    int gamestate_count;
    void *(**create_states)(gamestate_manager_t *);
    void (**input_states)(void *, sfEvent);
    void (**update_states)(void *);
    void (**draw_states)(sfRenderWindow *, void *);
    void *(**destroy_states)(void *);
    int current_state;
    void **current_state_data;
};

///////////////////// PROTOTYPE /////////////////////

// constructor and destructor
gamestate_manager_t *gamestate_manager_create(int gamestate_count);
void gamestate_manager_add_constructor_functions(gamestate_manager_t *gsm,
    void *(* const *create_states)(gamestate_manager_t *),
    void *(* const *destroy_states)(void *));
void gamestate_manager_add_update_functions(gamestate_manager_t *gsm,
    void (* const *input_states)(void *, sfEvent),
    void (* const *update_states)(void *),
    void (* const *draw_states)(sfRenderWindow *, void *));
void *gamestate_manager_destroy(gamestate_manager_t *gsm);

int gamestate_manager_set_state(gamestate_manager_t *gsm,
    int state, int destroy);
void gamestate_manager_load_state(gamestate_manager_t *gsm, int state);
void gamestate_manager_unload_state(gamestate_manager_t *gsm, int state);

// update
void gamestate_manager_handle_events(gamestate_manager_t *gsm, sfEvent event);
void gamestate_manager_update(gamestate_manager_t *gsm);
void gamestate_manager_draw(sfRenderWindow *window, gamestate_manager_t *gsm);

#endif /* !MY_GAMESTATE_MANAGER_H_ */