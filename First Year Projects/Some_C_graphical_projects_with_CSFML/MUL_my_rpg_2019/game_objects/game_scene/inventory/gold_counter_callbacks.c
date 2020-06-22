/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** gold_counter_callbacks
*/


#include <stdlib.h>
#include "my_rpg.h"

void animate_counter(gold_counter_t *counter)
{
    int seconds = sfClock_getElapsedTime(counter->clock).microseconds * 1000000;

    if (seconds > 1) {
        if (counter->rect.left < (120 * 7))
            counter->rect.left += 120;
        else
            counter->rect.left = 0;
        sfClock_restart(counter->clock);
    }
    sfSprite_setTextureRect(counter->sprite, counter->rect);
}

void update_counter_text(gold_counter_t *counter)
{
    char *to_display = NULL;

    to_display = my_strcat(my_strdup(": "), int_to_str(counter->golds));
    sfText_setString(counter->gold_text, to_display);
    free(to_display);
}

void update_g_counter(prog_stat_t *prog_stat, gold_counter_t *counter,
list_t *scene)
{
    list_t *player_c = find_object(scene, player_cursor_type);
    sfVector2f actual_pos = (sfVector2f){10, 10};
    if (prog_stat)
        counter->pos.x = actual_pos.x;
    counter->pos.y = actual_pos.y;
    if (player_c) {
        counter->pos.x = player_c->data->player_c->sprite_pos.x
        - (WINDOW_WIDTH / 2) + actual_pos.x;
        counter->pos.y = player_c->data->player_c->sprite_pos.y
        - (WINDOW_HEIGHT / 2) + actual_pos.y;
    }
    sfSprite_setPosition(counter->sprite, counter->pos);
    animate_counter(counter);
    counter->pos.x += 50;
    counter->pos.y += 3;
    update_counter_text(counter);
    sfText_setPosition(counter->gold_text, counter->pos);
}

void render_g_counter(prog_stat_t *prog_stat, gold_counter_t *counter,
list_t *scene)
{
    if (scene)
        sfRenderWindow_drawSprite(prog_stat->window, counter->sprite, NULL);
    sfRenderWindow_drawText(prog_stat->window, counter->gold_text, NULL);
}

void destroy_g_counter(prog_stat_t *prog_stat, gold_counter_t *counter,
list_t *scene)
{
    if (prog_stat || scene)
        sfText_destroy(counter->gold_text);
    sfTexture_destroy(counter->texture);
    sfSprite_destroy(counter->sprite);
    sfClock_destroy(counter->clock);
}