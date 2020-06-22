/*
** EPITECH PROJECT, 2019
** MY_AUDIO
** File description:
** My_audio header
*/

#ifndef MY_AUDIO_H_
#define MY_AUDIO_H_

//////////////////////// VAR ////////////////////////

// const

// def struct
typedef struct sfMusic sfMusic;
typedef struct sfSound sfSound;
typedef struct sfSoundBuffer sfSoundBuffer;
typedef struct audio_s audio_t;

// struct
struct audio_s
{
    int nbr_musics;
    sfMusic **musics;
    int nbr_sounds;
    sfSound **sounds;
    sfSoundBuffer **buffers;
};

///////////////////// PROTOTYPE /////////////////////

// lib


// init
audio_t *audio_create(int nbr_musics, int nbr_sounds);
void *audio_destroy(audio_t *audio);
void audio_add_music(audio_t **audio, char const *path);
void audio_add_sound(audio_t **audio, char const *path);

// music
void audio_play_music(audio_t *audio, int music_id);
void audio_play_loop_music(audio_t *audio, int music_id);
void audio_stop_music(audio_t *audio, int music_id);
void audio_stop_musics(audio_t *audio);

// sound
void audio_play_sound(audio_t *audio, int sound_id);
void audio_play_loop_sound(audio_t *audio, int sound_id);
void audio_stop_sound(audio_t *audio, int sound_id);
void audio_stop_sounds(audio_t *audio);

#endif /* !MY_AUDIO_H_ */