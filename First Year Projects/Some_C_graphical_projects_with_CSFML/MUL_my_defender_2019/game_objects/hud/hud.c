/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** hud
*/

#include <stdlib.h>
#include "my_defender.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Text.h>

void init_back_hud(list_t *game)
{
    backgr_t *backgr = malloc(sizeof(backgr_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    backgr->pos.x = 0;
    backgr->pos.y = 900 - 200;
    backgr->textu = sfTexture_createFromFile("Ressources/HUD/Hub_back.png"
    , NULL);
    backgr->type = background_type;
    backgr->sprite = sfSprite_create();
    sfSprite_setTexture(backgr->sprite, backgr->textu, sfTrue);
    sfSprite_setPosition(backgr->sprite, backgr->pos);
    backgr->destroy = &menu_back_destroy;
    backgr->render = &render_background;
    backgr->update = NULL;
    data->background = backgr;
    add_to_front(game, data);
}

static void score_up(score_t *backgr)
{
    backgr->pos.x += 12;
    backgr->pos.y += 10;
    backgr->money = init_text(&sfYellow, 25, &backgr->pos);
    backgr->pos.y += 40;
    backgr->pos.x += 2;
    backgr->score = init_text(&sfWhite, 25, &backgr->pos);
    backgr->pos.y += 40;
    backgr->hp = init_text(&sfRed, 25, &backgr->pos);
    backgr->pos.x += 100;
    backgr->hp_value = init_text(&sfRed, 20, &backgr->pos);
    backgr->pos.y -= 40;
    backgr->score_value = init_text(&sfWhite, 20, &backgr->pos);
    backgr->pos.y -= 40;
    backgr->money_value = init_text(&sfYellow, 20, &backgr->pos);
}

void update_texts(prog_stat_t *prog_stat, struct score *backgr,
list_t *game_scene)
{
    player_info_t *player = find_object(game_scene
    , level_type)->data->level->p_info;

    sfText_setString(backgr->hp_value, int_to_str_conv(player->life, NULL));
    sfText_setString(backgr->score_value, int_to_str_conv(player->score, NULL));
    sfText_setString(backgr->money_value, int_to_str_conv(player->money, NULL));
}

void init_texts_screen(list_t *game)
{
    score_t *backgr = malloc(sizeof(score_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    backgr->pos.x = 1600 - (175 * 2.8);
    backgr->pos.y = 900 - 175;
    backgr->textu = sfTexture_createFromFile("Ressources/HUD/Score.png"
    , NULL);
    backgr->type = background_type;
    backgr->sprite = sfSprite_create();
    sfSprite_setTexture(backgr->sprite, backgr->textu, sfTrue);
    sfSprite_setPosition(backgr->sprite, backgr->pos);
    backgr->destroy = &menu_back_destroy;
    backgr->render = &render_scores;
    backgr->update = &update_texts;
    score_up(backgr);
    data->background = backgr;
    add_to_front(game, data);
}

void initialize_hud(list_t *game)
{
    add_to_front(game, init_tower_four_hud());
    add_to_front(game, init_tower_three_hud());
    add_to_front(game, init_tower_two_hud());
    add_to_front(game, init_tower_one_hud());
    add_to_front(game, init_quit_hud());
    add_to_front(game, init_start_hud());
    init_texts_screen(game);
    init_back_hud(game);
}