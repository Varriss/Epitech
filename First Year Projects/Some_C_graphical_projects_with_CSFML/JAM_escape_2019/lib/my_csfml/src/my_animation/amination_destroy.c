/*
** EPITECH PROJECT, 2019
** AMINATION_DESTROY
** File description:
** Animation_destroy function
*/

#include <SFML/Graphics/Texture.h>
#include <stddef.h>
#include <stdlib.h>
#include "my_animation.h"

void animation_destroy_textures(animation_t *animation)
{
    for (int k = 0; k < animation->size; k++)
        if (animation->textures[k])
            sfTexture_destroy(animation->textures[k]);
    free(animation->textures);
}

void *animation_destroy(animation_t *animation)
{
    if (!animation)
        return (NULL);
    if (animation->textures)
        animation_destroy_textures(animation);
    if (animation->animation_sequences)
        free(animation->animation_sequences);
    free(animation);
    return (NULL);
}