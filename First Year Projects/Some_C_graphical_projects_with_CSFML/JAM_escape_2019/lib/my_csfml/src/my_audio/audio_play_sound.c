/*
** EPITECH PROJECT, 2019
** AUDIO_PLAY_SOUND
** File description:
** Audio_play_sound function
*/

#include <stdlib.h>
#include <stddef.h>
#include <SFML/Config.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Sound.h>
#include "my_audio.h"

void audio_play_sound(audio_t *audio, int sound_id)
{
    if (audio->sounds[sound_id]) {
        sfSound_setLoop(audio->sounds[sound_id], sfFalse);
        sfSound_play(audio->sounds[sound_id]);
    }
}

void audio_play_loop_sound(audio_t *audio, int sound_id)
{
    if (audio->sounds[sound_id]) {
        sfSound_setLoop(audio->sounds[sound_id], sfTrue);
        sfSound_play(audio->sounds[sound_id]);
    }
}

void audio_stop_sound(audio_t *audio, int sound_id)
{
    if (audio->sounds[sound_id])
        sfSound_stop(audio->sounds[sound_id]);
}

void audio_stop_sounds(audio_t *audio)
{
    for (int sound_id = 0; sound_id < audio->nbr_musics; sound_id++)
        if (audio->sounds[sound_id])
            sfSound_stop(audio->sounds[sound_id]);
}