/*
** EPITECH PROJECT, 2020
** BUTTON_CREATE
** File description:
** Button_create function
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_clock.h"
#include "my_button.h"

void button_fix_scale(button_t *button)
{
    button->passed_scale = (sfVector2f){button->normal_scale.x * .98f,
        button->normal_scale.y * .98f};
    button->pressed_scale = (sfVector2f){button->normal_scale.x * .95f,
        button->normal_scale.y * .95f};
}

int button_init_sprite(button_t *button, char const *bg_path)
{
    sfVector2f pos = {button->bounds->left + button->bounds->width / 2,
        button->bounds->top + button->bounds->height / 2};

    if (!button->texture)
        button->texture = bg_path ? sfTexture_createFromFile(bg_path,
            NULL) : button_get_black_texture();
    if (!button->texture)
        return (0);
    sfTexture_setSmooth(button->texture, sfTrue);
    sfSprite_setPosition(button->sprite, pos);
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    button->normal_scale.x /= sfTexture_getSize(button->texture).x;
    button->normal_scale.y /= sfTexture_getSize(button->texture).y;
    sfSprite_setScale(button->sprite, button->normal_scale);
    sfSprite_setOrigin(button->sprite, (sfVector2f){sfTexture_getSize(
        button->texture).x / (float)2,
        sfTexture_getSize(button->texture).y / (float)2});
    button_fix_scale(button);
    return (1);
}

button_t *button_create_from_texture(sfIntRect bounds, sfTexture *texture)
{
    button_t *button = malloc(sizeof(button_t));

    if (!button)
        return (NULL);
    button_init_null(button);
    button->bounds = malloc(sizeof(sfIntRect));
    button->clock = clock_create();
    button->sprite = sfSprite_create();
    if (!button->bounds || !button->clock || !button->sprite)
        return (button_destroy(button));
    if (texture) {
        button->texture = sfTexture_copy(texture);
        if (!button->texture)
            return (button_destroy(button));
    }
    button_init_bounds(button, bounds);
    if (!button_init_sprite(button, NULL))
        return (button_destroy(button));
    return (button);
}

button_t *button_create_from_path(sfIntRect bounds, char const *bg_path)
{
    button_t *button = malloc(sizeof(button_t));

    if (!button)
        return (NULL);
    button_init_null(button);
    button->bounds = malloc(sizeof(sfIntRect));
    button->clock = clock_create();
    button->sprite = sfSprite_create();
    if (!button->bounds || !button->clock || !button->sprite)
        return (button_destroy(button));
    button_init_bounds(button, bounds);
    if (!button_init_sprite(button, bg_path))
        return (button_destroy(button));
    return (button);
}