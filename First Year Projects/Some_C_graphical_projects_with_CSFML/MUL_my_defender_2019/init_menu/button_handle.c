/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019_2
** File description:
** button_handle
*/

#include "stdlib.h"
#include "my_defender.h"

static void clikked(sfEvent *event, prog_stat_t *prog_stat, list_t *cursor,
list_t *scene)
{
    int rect_x = 0;
    int rect_y = 0;
    int x = event->mouseButton.x;
    int y = event->mouseButton.y;

    if (y < (WINDOW_HEIGHT - 200) && prog_stat->scene_index == 1
    && cursor->data->button->type == tile_map_type) {
        cursor->data->button->onclick(prog_stat, cursor->data->button,
        scene, event);
    } else {
        rect_x = cursor->data->button->pos.x;
        rect_y = cursor->data->button->pos.y;
        if ((y < rect_y + MENU_ICON_HEIGHT) && (y > rect_y))
            if ((x < rect_x + MENU_ICON_WIDTH) && (x > rect_x))
                cursor->data->button->onclick(prog_stat, cursor->data->button,
                scene, event);
    }
}

void button_destroy(prog_stat_t *prog_stat, button_t *button)
{
    sfTexture_destroy(button->textu);
    sfSprite_destroy(button->sprite);
    free(button);
}

void render_button(prog_stat_t *prog_stat, button_t *button) {
    sfRenderWindow_drawSprite(prog_stat->window, button->sprite, NULL);
}

void menu_buttons_manage(sfEvent *event, prog_stat_t *prog_stat
, list_t *g_o_list)
{
    list_t *cursor = g_o_list->next;

    for (; cursor != g_o_list; cursor = cursor->next) {
        if (((cursor->data->button->type == tile_map_type)
        || (cursor->data->button->type == button_type))
        && (cursor->data->button->onclick != NULL))
            clikked(event, prog_stat, cursor, g_o_list);
    }
}

void button_clicked(sfEvent *event, prog_stat_t *prog_stat, list_t *g_o_list)
{
    menu_buttons_manage(event, prog_stat, g_o_list);
}