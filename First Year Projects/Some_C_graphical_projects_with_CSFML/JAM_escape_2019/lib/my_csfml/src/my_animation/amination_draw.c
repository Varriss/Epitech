/*
** EPITECH PROJECT, 2019
** AMINATION_DRAW
** File description:
** Animation_draw function
*/

#include <SFML/Graphics/Texture.h>
#include <stddef.h>
#include "my_animation.h"

sfTexture *animation_get_animation(animation_t *animation)
{
    int *anim_sequence;
    int texture_id;

    if (!animation)
        return (NULL);
    if (animation->anim_id == -1)
        return (NULL);
    if (animation->anim_seq_id == -1)
        return (NULL);
    anim_sequence = animation->animation_sequences[animation->anim_seq_id];
    texture_id = anim_sequence[animation->anim_id];
    return (animation->textures[texture_id]);
}