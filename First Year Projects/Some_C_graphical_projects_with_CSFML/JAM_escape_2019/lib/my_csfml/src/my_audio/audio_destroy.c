/*
** EPITECH PROJECT, 2020
** AUDIO_DESTROY
** File description:
** Audio_destroy function
*/

#include <stdlib.h>
#include <stddef.h>
#include <SFML/Graphics.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Types.h>
#include "my_audio.h"

void audio_musics_destroy(audio_t *audio)
{
    for (int id = 0; audio->musics && id < audio->nbr_musics; id++)
        if (audio->musics[id]) {
            sfMusic_stop(audio->musics[id]);
            sfMusic_destroy(audio->musics[id]);
        }
    if (audio->musics)
        free(audio->musics);
}

void audio_sounds_destroy(audio_t *audio)
{
    for (int id = 0; audio->sounds && id < audio->nbr_sounds; id++)
        if (audio->sounds[id]) {
            sfSound_stop(audio->sounds[id]);
            sfSound_destroy(audio->sounds[id]);
            sfSoundBuffer_destroy(audio->buffers[id]);
        }
    if (audio->sounds)
        free(audio->sounds);
    if (audio->buffers)
        free(audio->buffers);
}

void *audio_destroy(audio_t *audio)
{
    if (!audio)
        return (NULL);
    audio_musics_destroy(audio);
    audio_sounds_destroy(audio);
    free(audio);
    return (NULL);
}