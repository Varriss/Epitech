/*
** EPITECH PROJECT, 2019
** BACKGROUND_CREATE
** File description:
** Background_create function
*/

#include <SFML/Graphics.h>
#include <stddef.h>
#include <stdlib.h>
#include "my_background.h"

background_t *background_create(int nb_layer,
    int frame_width, int frame_height)
{
    background_t *background = malloc(sizeof(background_t));

    if (!background)
        return (NULL);
    background->nb_layer = nb_layer;
    background->frame_width = frame_width;
    background->frame_height = frame_height;
    background->vx = malloc(sizeof(float) * (nb_layer + 1));
    for (int layer = 0; background->vx && layer < nb_layer + 1; layer++)
        background->vx[layer] = 0;
    background->textures = malloc(sizeof(sfTexture *) * (nb_layer + 1));
    for (int layer = 0; background->textures && layer < nb_layer + 1; layer++)
        background->textures[layer] = NULL;
    background->sprites = malloc(sizeof(sfSprite *) * (nb_layer + 1));
    for (int layer = 0; background->sprites && layer < nb_layer + 1; layer++)
        background->sprites[layer] = NULL;
    if (!background->vx || !background->textures || !background->sprites)
        return (background_destroy(background));
    return (background);
}

void background_scale(sfSprite *sprite, sfTexture *texture, int height)
{
    sfVector2f scale;

    scale.x = height / (float)sfTexture_getSize(texture).y;
    scale.y = height / (float)sfTexture_getSize(texture).y;
    sfSprite_setScale(sprite, scale);
}

void background_add(background_t **background, int height, float vx,
    char const *path)
{
    sfTexture *texture = NULL;
    sfSprite *sprite = NULL;

    if (!background[0] || !path)
        return;
    texture = sfTexture_createFromFile(path, NULL);
    sprite = sfSprite_create();
    for (int id = 0; id < background[0]->nb_layer; id++)
        if (!background[0]->textures[id]) {
            background[0]->vx[id] = vx;
            background[0]->textures[id] = texture;
            background[0]->sprites[id] = sprite;
            break;
        }
    if (!texture || !sprite) {
        background[0] = background_destroy(background[0]);
        return;
    }
    sfSprite_setTexture(sprite, texture, sfFalse);
    background_scale(sprite, texture, height);
}