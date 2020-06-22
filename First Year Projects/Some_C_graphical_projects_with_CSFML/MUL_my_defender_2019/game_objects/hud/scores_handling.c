/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** scores_handling
*/

#include "my_defender.h"

void render_scores(prog_stat_t *prog_stat, score_t *scores)
{
    sfRenderWindow_drawSprite(prog_stat->window, scores->sprite, NULL);
    sfText_setString(scores->money, "Cash :");
    sfText_setString(scores->score, "Score :");
    sfText_setString(scores->hp, "Life :");
    sfRenderWindow_drawText(prog_stat->window, scores->money, NULL);
    sfRenderWindow_drawText(prog_stat->window, scores->score, NULL);
    sfRenderWindow_drawText(prog_stat->window, scores->hp, NULL);
    sfRenderWindow_drawText(prog_stat->window, scores->money_value, NULL);
    sfRenderWindow_drawText(prog_stat->window, scores->score_value, NULL);
    sfRenderWindow_drawText(prog_stat->window, scores->hp_value, NULL);
}

sfText *init_text(sfColor *color, int size, sfVector2f *pos)
{
    sfText *text = sfText_create();
    static sfFont *font = NULL;

    if (font == NULL)
        font = sfFont_createFromFile("Ressources/HUD/Font.ttf");
    sfText_setColor(text, *color);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, *pos);
    return (text);
}