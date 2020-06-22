/*
** EPITECH PROJECT, 2020
** GAMESTATE_MANAGER_CREATE
** File description:
** Gamestate_manager_create function
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_gamestate_manager.h"

void gamestate_manager_init(gamestate_manager_t *gsm)
{
    for (int k = 0; k < gsm->gamestate_count + 1; k++) {
        gsm->current_state_data[k] = NULL;
        gsm->create_states[k] = NULL;
        gsm->input_states[k] = NULL;
        gsm->update_states[k] = NULL;
        gsm->draw_states[k] = NULL;
        gsm->destroy_states[k] = NULL;
    }
}

gamestate_manager_t *gamestate_manager_create(int gamestate_count)
{
    gamestate_manager_t *gsm = malloc(sizeof(gamestate_manager_t));
    int nb = gamestate_count + 1;

    if (!gsm)
        return (NULL);
    gsm->gamestate_count = gamestate_count;
    gsm->current_state = -1;
    gsm->current_state_data = malloc(sizeof(void *) * nb);
    gsm->create_states = malloc(sizeof(void *(*)(gamestate_manager_t *)) * nb);
    gsm->input_states = malloc(sizeof(void (*)(void *, sfEvent)) * nb);
    gsm->update_states = malloc(sizeof(void (*)(void *)) * nb);
    gsm->draw_states = malloc(sizeof(void (*)(sfRenderWindow *, void *)) * nb);
    gsm->destroy_states = malloc(sizeof(void *(*)(void *)) * nb);
    if (!gsm->current_state_data || !gsm->create_states || !gsm->input_states
        || !gsm->update_states || !gsm->draw_states || !gsm->destroy_states)
        return (gamestate_manager_destroy(gsm));
    gamestate_manager_init(gsm);
    return (gsm);
}

void gamestate_manager_add_constructor_functions(gamestate_manager_t *gsm,
    void *(* const *create_states)(gamestate_manager_t *),
    void *(* const *destroy_states)(void *))
{
    if (!gsm)
        return;
    for (int k = 0; create_states && k < gsm->gamestate_count; k++)
        gsm->create_states[k] = create_states[k];
    for (int k = 0; destroy_states && k < gsm->gamestate_count; k++)
        gsm->destroy_states[k] = destroy_states[k];
}

void gamestate_manager_add_update_functions(gamestate_manager_t *gsm,
    void (* const *input_states)(void *, sfEvent),
    void (* const *update_states)(void *),
    void (* const *draw_states)(sfRenderWindow *, void *))
{
    if (!gsm)
        return;
    for (int k = 0; input_states && k < gsm->gamestate_count; k++)
        gsm->input_states[k] = input_states[k];
    for (int k = 0; update_states && k < gsm->gamestate_count; k++)
        gsm->update_states[k] = update_states[k];
    for (int k = 0; draw_states && k < gsm->gamestate_count; k++)
        gsm->draw_states[k] = draw_states[k];
}