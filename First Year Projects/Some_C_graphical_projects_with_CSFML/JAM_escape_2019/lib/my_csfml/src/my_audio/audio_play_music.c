/*
** EPITECH PROJECT, 2019
** AUDIO_PLAY_MUSIC
** File description:
** Audio_play_music function
*/

#include <stdlib.h>
#include <stddef.h>
#include <SFML/Config.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Music.h>
#include "my_audio.h"

void audio_play_music(audio_t *audio, int music_id)
{
    if (audio->musics[music_id]) {
        sfMusic_setLoop(audio->musics[music_id], sfFalse);
        sfMusic_play(audio->musics[music_id]);
    }
}

void audio_play_loop_music(audio_t *audio, int music_id)
{
    if (audio->musics[music_id]) {
        sfMusic_setLoop(audio->musics[music_id], sfTrue);
        sfMusic_play(audio->musics[music_id]);
    }
}

void audio_stop_music(audio_t *audio, int music_id)
{
    if (audio->musics[music_id])
        sfMusic_stop(audio->musics[music_id]);
}

void audio_stop_musics(audio_t *audio)
{
    for (int music_id = 0; music_id < audio->nbr_musics; music_id++)
        if (audio->musics[music_id])
            sfMusic_stop(audio->musics[music_id]);
}