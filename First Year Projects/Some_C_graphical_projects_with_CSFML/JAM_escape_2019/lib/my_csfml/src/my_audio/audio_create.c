/*
** EPITECH PROJECT, 2019
** AUDIO_CREATE
** File description:
** Audio_create function
*/

#include <stdlib.h>
#include <stddef.h>
#include <SFML/Graphics.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Types.h>
#include "my_audio.h"

audio_t *audio_create(int nbr_musics, int nbr_sounds)
{
    audio_t *audio = malloc(sizeof(audio_t));

    if (!audio)
        return (NULL);
    audio->musics = malloc(sizeof(sfMusic *) * (nbr_musics + 1));
    audio->sounds = malloc(sizeof(sfSound *) * (nbr_sounds + 1));
    audio->buffers = malloc(sizeof(sfSoundBuffer *) * (nbr_sounds + 1));
    if (!audio->musics || !audio->sounds || !audio->buffers)
        return (audio_destroy(audio));
    audio->nbr_musics = nbr_musics;
    audio->nbr_sounds = nbr_sounds;
    for (int music = 0; music < nbr_musics + 1; music++)
        audio->musics[music] = NULL;
    for (int sound = 0; sound < nbr_sounds + 1; sound++) {
        audio->sounds[sound] = NULL;
        audio->buffers[sound] = NULL;
    }
    return (audio);
}

void audio_add_music(audio_t **audio, char const *path)
{
    sfMusic *music = NULL;

    if (!audio[0] || !path)
        return;
    music = sfMusic_createFromFile(path);
    if (!music) {
        audio[0] = audio_destroy(audio[0]);
        return;
    }
    for (int id = 0; id < audio[0]->nbr_musics; id++)
        if (!audio[0]->musics[id]) {
            audio[0]->musics[id] = music;
            break;
        }
}

void audio_add_sound(audio_t **audio, char const *path)
{
    sfSound *sound = NULL;

    if (!audio[0] || !path)
        return;
    sound = sfSound_create();
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(path);
    sfSound_setBuffer(sound, buffer);
    if (!sound || !buffer) {
        audio[0] = audio_destroy(audio[0]);
        return;
    }
    for (int id = 0; id < audio[0]->nbr_sounds; id++)
        if (!audio[0]->sounds[id]) {
            audio[0]->sounds[id] = sound;
            audio[0]->buffers[id] = buffer;
            break;
        }
}