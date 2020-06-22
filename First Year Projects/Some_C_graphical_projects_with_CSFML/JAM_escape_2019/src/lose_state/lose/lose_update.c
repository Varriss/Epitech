/*
** EPITECH PROJECT, 2020
** LOSE_UPDATE
** File description:
** Lose_update function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Sound.h>
#include "my_audio.h"
#include "my_gamestate_manager.h"
#include "my_button.h"
#include "jam.h"
#include "audio.h"

void lose_update(lose_t *lose)
{
    button_update(lose->menu_button);
    if (button_is_click(lose->menu_button)) {
        gamestate_manager_set_state(lose->gsm, MENU_STATE, 1);
        return;
    }
    if (is_game_mute())
        sfSound_setVolume(lose->audio->sounds[L_WASTED_SOUND], 0);
    else
        sfSound_setVolume(lose->audio->sounds[L_WASTED_SOUND], 100);
}