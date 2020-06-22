/*
** EPITECH PROJECT, 2019
** BACKGROUND_DESTROY
** File description:
** Background_destroy function
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_background.h"

void textures_destroy(sfTexture **textures, int nb)
{
    if (!textures)
        return;
    for (int texture = 0; texture < nb; texture++) {
        if (textures[texture]) {
            sfTexture_destroy(textures[texture]);
            textures[texture] = NULL;
        }
    }
}

void sprites_destroy(sfSprite **sprites, int nb)
{
    if (!sprites)
        return;
    for (int sprite = 0; sprite < nb; sprite++) {
        if (sprites[sprite]) {
            sfSprite_destroy(sprites[sprite]);
            sprites[sprite] = NULL;
        }
    }
}

void *background_destroy(background_t *background)
{
    if (!background)
        return (NULL);
    if (background->vx)
        free(background->vx);
    if (background->textures) {
        textures_destroy(background->textures, background->nb_layer);
        free(background->textures);
    }
    if (background->sprites) {
        sprites_destroy(background->sprites, background->nb_layer);
        free(background->sprites);
    }
    free(background);
    return (NULL);
}