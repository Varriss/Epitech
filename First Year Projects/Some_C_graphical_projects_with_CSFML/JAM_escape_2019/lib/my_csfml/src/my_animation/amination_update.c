/*
** EPITECH PROJECT, 2020
** AMINATION_UPDATE
** File description:
** Amination_update function
*/

#include <SFML/System.h>
#include <SFML/Graphics/Texture.h>
#include <stddef.h>
#include <stdlib.h>
#include "my_clock.h"
#include "my_animation.h"

void amination_safe_set_anim_seq(animation_t *animation, int anim_seq_id)
{
    if (!animation)
        return;
    if (animation->anim_seq_id != anim_seq_id)
        amination_set_anim_seq(animation, anim_seq_id);
}

void amination_set_anim_seq(animation_t *animation, int anim_seq_id)
{
    if (!animation)
        return;
    if (anim_seq_id > animation->nbr_anim || anim_seq_id < 0) {
        animation->anim_seq_id = -1;
        return;
    }
    animation->anim_id = 0;
    animation->anim_seq_id = anim_seq_id;
}

int animation_get_anim_seq(animation_t *animation)
{
    if (!animation)
        return (-1);
    return (animation->anim_seq_id);
}

void anim_update_loop(animation_t *animation, my_clock_t *clock)
{
    sfInt64 tmp;
    int *animation_sequence;
    int seq_id;

    tmp = animation->last_time_update + animation->anim_delay;
    while (tmp < clock_get_ms(clock)) {
        animation->anim_id++;
        seq_id = animation->anim_seq_id;
        animation_sequence = animation->animation_sequences[seq_id];
        if (animation_sequence[animation->anim_id] == -1)
            animation->anim_id = 0;
        animation->last_time_update += animation->anim_delay;
        tmp = animation->last_time_update + animation->anim_delay;
    }
}

void amination_update(animation_t *animation, my_clock_t *clock)
{
    if (!animation)
        return;
    if (animation->last_time_update == -1)
        animation->last_time_update = clock_get_ms(clock);
    if (animation->anim_id == -1)
        return;
    if (animation->anim_seq_id == -1)
        return;
    anim_update_loop(animation, clock);
}