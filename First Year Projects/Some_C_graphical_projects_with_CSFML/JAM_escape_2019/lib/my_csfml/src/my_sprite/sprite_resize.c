/*
** EPITECH PROJECT, 2020
** SPRITE_RESIZE
** File description:
** Sprite_resize function
*/

#include <stdlib.h>
#include <SFML/Graphics.h>

void sprite_set_texture(sfSprite *sprite, sfTexture *texture,
    int width, int height)
{
    sfVector2u size;
    sfVector2f scale;

    if (!sprite || !texture)
        return;
    size = sfTexture_getSize(texture);
    scale = (sfVector2f){width / (float)size.x, height / (float)size.y};
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setScale(sprite, scale);
}