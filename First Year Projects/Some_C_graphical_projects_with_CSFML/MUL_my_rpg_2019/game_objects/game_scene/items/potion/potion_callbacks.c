/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** potion_callbacks
*/

#include <stdlib.h>
#include "my_rpg.h"

void update_potion_text(potion_t *potion)
{
    char *to_display = NULL;

    to_display = my_strcat(my_strdup("x"), int_to_str(potion->player_has));
    to_display = my_strcat(to_display, my_strdup("\n\n       1"));
    sfText_setString(potion->text, to_display);
    sfText_setPosition(potion->text, potion->pos);
    free(to_display);
}

void update_potion(prog_stat_t *prog_stat, potion_t *potion,
list_t *scene)
{
    list_t *player_c = find_object(scene, player_cursor_type);
    sfVector2f actual_pos = {10, 800};

    potion->can_use = (potion->player_has > 0 ? sfTrue : sfFalse);
    if (player_c && prog_stat) {
        potion->pos.x = player_c->data->player_c->sprite_pos.x
        - (WINDOW_WIDTH / 2) + actual_pos.x;
        potion->pos.y = player_c->data->player_c->sprite_pos.y
        - (WINDOW_HEIGHT / 2) + actual_pos.y;
    } else {
        potion->pos.x = actual_pos.x;
        potion->pos.y = actual_pos.y;
    }
    update_potion_text(potion);
    sfSprite_setPosition(potion->sprite, potion->pos);
}

void render_potion(prog_stat_t *prog_stat, potion_t *potion,
list_t *scene)
{
    if (potion->display == sfTrue && prog_stat && scene) {
        sfRenderWindow_drawSprite(prog_stat->window, potion->sprite, NULL);
        sfRenderWindow_drawText(prog_stat->window, potion->text, NULL);
    }
}

void destroy_potion(prog_stat_t *prog_stat, potion_t *potion,
list_t *scene)
{
    if (prog_stat && scene)
        sfTexture_destroy(potion->texture);
    sfSprite_destroy(potion->sprite);
    sfText_destroy(potion->text);
    free(potion);
    potion = NULL;
}