/*
** EPITECH PROJECT, 2020
** VICTORY_UPDATE
** File description:
** Victory_update function
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

void victory_update(victory_t *victory)
{
    button_update(victory->menu_button);
    if (button_is_click(victory->menu_button)) {
        gamestate_manager_set_state(victory->gsm, MENU_STATE, 1);
        return;
    }
    if (is_game_mute())
        sfSound_setVolume(victory->audio->sounds[L_WASTED_SOUND], 0);
    else
        sfSound_setVolume(victory->audio->sounds[L_WASTED_SOUND], 100);
}