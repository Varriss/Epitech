/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** sound_buffer_utlities
*/

#include "my_rpg.h"
#include <SFML/Audio.h>

void play_sound(audio_id_t id, prog_stat_t *prog_stat)
{
    list_t *sound = get_next_sound_cell(prog_stat->musics_sounds->sounds_list);

    sfSound_setBuffer(sound->data->sound->sound, get_music_sound_cursor
    (prog_stat->musics_sounds->sounds_buffer_list
    , id)->data->buffer->buffer);
    sfSound_play(sound->data->sound->sound);
}

void buffer_destroy(prog_stat_t *prog_stat, sound_buffer_t *buffer)
{
    sfSoundBuffer_destroy(buffer->buffer);
    if (prog_stat)
        free(buffer);
}

list_data_t *add_sound_data(char *file, audio_id_t id)
{
    list_data_t *buffer_data = malloc(sizeof(list_data_t));
    sound_buffer_t *buffer = malloc(sizeof(sound_buffer_t));

    buffer->type = sound_buffers_type;
    buffer->id = id;
    buffer->buffer = sfSoundBuffer_createFromFile(file);
    buffer->update = NULL;
    buffer->render = NULL;
    buffer->destroy = &buffer_destroy;
    buffer_data->buffer = buffer;
    return (buffer_data);
}

list_t *sound_buffers_create(void)
{
    list_t *sound_buffers_list = create_list();

    add_to_front(sound_buffers_list, add_sound_data(CLICK_SOUND, button_click));
    add_to_front(sound_buffers_list, add_sound_data(MALE_PAIN, male_pain));
    add_to_front(sound_buffers_list, add_sound_data(DRAKE_PAIN, dragon_pain));
    add_to_front(sound_buffers_list, add_sound_data(SWORD_ATTACK, sword_sound));
    add_to_front(sound_buffers_list, add_sound_data(DRAKE_ATTACK, dragon_roar));
    add_to_front(sound_buffers_list, add_sound_data(WALK_SOUND, walk));
    return (sound_buffers_list);
}