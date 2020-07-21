/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** life_handling
*/

#include <stdlib.h>
#include "my_rpg.h"

void handle_defense(prog_stat_t *prog_stat, list_t *scene, sfEvent *eve,
player_t *player)
{
    list_t *enemy = find_object(scene, enemy_type);

    if ((player->animeted == 0) && (player->turn == 1) && prog_stat && eve
    && (player->defense == 1)) {
        player->inventory->items[shield_type]->shield->quest_completion++;
        player->turn = 2;
        sfClock_restart(enemy->data->enemy->clock);
    }
}

void attack_attack(prog_stat_t *prog_stat, list_t *scene,
sfEvent *eve)
{
    list_t *player = find_object(scene, player_type);
    list_t *enemy = find_object(scene, enemy_type);
    blade_t *blade = player->data->player->inventory->items[blade_type]->blade;

    if (player && enemy && prog_stat && scene && eve) {
        if ((player->data->player->animeted == 0)
        && (player->data->player->turn == 1)
        && (player->data->player->defense == 0)) {
            player->data->player->animeted = 1;
            enemy->data->enemy->life -= (blade->lvl == 0 ? 1 : 3 * blade->lvl);
            blade->quest_completion++;
            player->data->player->turn = 2;
            sfClock_restart(enemy->data->enemy->clock);
            play_sound(sword_sound, prog_stat);
            play_sound(dragon_pain, prog_stat);
        }
        handle_defense(prog_stat, scene, eve, player->data->player);
    }
}

void render_lifebar(prog_stat_t *prog_stat, button_t *button)
{
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfRenderWindow_drawSprite(prog_stat->window, button->sprite, NULL);
}

void init_barlife_enemy(enemy_t *enemy, int count)
{
    life_bar_t *life_bar = malloc(sizeof(life_bar_t));

    enemy->life_bar = life_bar;
    enemy->life_bar->pos.x = enemy->pos.x + 100 + (count * 50);
    enemy->life_bar->pos.y = enemy->pos.y + (count * 30) - 100;
    enemy->life_bar->rect.top = 0;
    enemy->life_bar->rect.left = 0;
    enemy->life_bar->rect.width = 300;
    enemy->life_bar->rect.height = 45;
    enemy->life_bar->textu = sfTexture_createFromFile(LIFE_BAR, NULL);
    enemy->life_bar->sprite = sfSprite_create();
    sfSprite_setTexture(enemy->life_bar->sprite, enemy->life_bar->textu
    , sfTrue);
    sfSprite_setPosition(enemy->life_bar->sprite, enemy->life_bar->pos);
}

/* list_data_t *init_barlife(list_t *fight_scene)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    button->pos.y = 100;
    button->rect.top = 0;
    button->rect.left = 0;
    button->rect.width = 300;
    button->rect.height = 45;
    button->update = NULL;
    button->destroy = &button_destroy;
    button->render = &render_lifebar;
    button->textu = sfTexture_createFromFile(LIFE_BAR, NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    add_to_front(fight_scene, data);
    return (data);
} */
