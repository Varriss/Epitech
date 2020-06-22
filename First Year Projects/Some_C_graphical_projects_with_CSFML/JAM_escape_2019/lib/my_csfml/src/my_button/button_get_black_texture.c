/*
** EPITECH PROJECT, 2020
** BUTTON_GET_BLACK_TEXTURE
** File description:
** Button_get_black_texture function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>

sfTexture *button_get_black_texture(void)
{
    sfImage *black_image = sfImage_createFromColor(1, 1, sfBlack);
    sfTexture *texture;

    if (!black_image)
        return (NULL);
    texture = sfTexture_createFromImage(black_image, NULL);
    sfImage_destroy(black_image);
    return (texture);
}