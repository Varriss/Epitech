/*
** EPITECH PROJECT, 2019
** AMINATION_CREATE
** File description:
** Animation_create function
*/

#include <SFML/Graphics/Texture.h>
#include <stddef.h>
#include <stdlib.h>
#include "my_animation.h"

int load_texture(animation_t *animation, char const *texture_path,
    int texture_x)
{
    int size = animation->size;
    sfIntRect area = {0, 0, animation->width, animation->height};
    int x;
    int y;

    animation->textures = malloc(sizeof(sfTexture *) * (size + 1));
    if (!animation->textures)
        return (1);
    for (int k = 0; k < size + 1; k++)
        animation->textures[k] = NULL;
    for (int id = 0; id < size; id++) {
        x = id % texture_x;
        y = id / texture_x;
        area.left = x * animation->width;
        area.top = y * animation->height;
        animation->textures[id] = sfTexture_createFromFile(texture_path, &area);
        if (!animation->textures[id])
            return (1);
    }
    return (0);
}

int init_animation(animation_t *animation, int nbr_anim)
{
    animation->last_time_update = -1;
    animation->anim_delay = 0;
    animation->anim_id = -1;
    animation->anim_seq_id = -1;
    animation->nbr_anim = nbr_anim;
    animation->animation_sequences = malloc(sizeof(int *) * (nbr_anim + 1));
    if (!animation->animation_sequences)
        return (1);
    for (int anim = 0; anim < nbr_anim + 1; anim++)
        animation->animation_sequences[anim] = NULL;
    return (0);
}

animation_t *animation_create(char const *texture_path,
    int texture_x, int texture_y, int nbr_anim)
{
    int size = texture_x * texture_y;
    animation_t *animation;
    sfTexture *texture;

    if (texture_x <= 0 || texture_y <= 0)
        return (NULL);
    animation = malloc(sizeof(animation_t));
    if (!animation)
        return (NULL);
    texture = sfTexture_createFromFile(texture_path, NULL);
    animation->size = size;
    animation->width = sfTexture_getSize(texture).x / texture_x;
    animation->height = sfTexture_getSize(texture).y / texture_y;
    sfTexture_destroy(texture);
    animation->textures = NULL;
    if (init_animation(animation, nbr_anim))
        return (animation_destroy(animation));
    if (load_texture(animation, texture_path, texture_x))
        return (animation_destroy(animation));
    return (animation);
}

int animation_add_animation(animation_t *animation, int *sequence)
{
    if (!animation)
        return (1);
    for (int k = 0; k < animation->nbr_anim; k++)
        if (!animation->animation_sequences[k]) {
            animation->animation_sequences[k] = sequence;
            return (0);
        }
    return (1);
}

void animation_set_anim_delay(animation_t *animation, int anim_delay)
{
    if (!animation)
        return;
    if (anim_delay < 1)
        return;
    animation->anim_delay = anim_delay;
}