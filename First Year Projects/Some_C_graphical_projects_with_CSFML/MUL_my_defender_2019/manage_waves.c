/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** manage_waves
*/

#include "my_defender.h"

static enemy_info_t enemy_info[ENEMY_TYPES] = {
    {
        80,
        10,
        "Ressources/enemies/enemy1.png",
        2.0f,
        {SPAWN_X, SPAWN_Y},
        {0.85, 0.85},
    },
    {
        100,
        15,
        "Ressources/enemies/enemy2.png",
        2.0f,
        {SPAWN_X, SPAWN_Y},
        {1, 1},
    },
    {
        50,
        10,
        "Ressources/enemies/enemy3.png",
        4.0f,
        {SPAWN_X, SPAWN_Y},
        {0.5, 0.5}
    }
};

static int wave_increase(int wave_nb, int type)
{
    int res = 0;

    if (type == 0)
        res = (wave_nb * 2) + (wave_nb % 2) * 2;
    else if (type = 1)
        res = (wave_nb % 2) * 3;
    else
        res = (wave_nb) + (wave_nb % 2) * 2;
    return (res);
}

void manage_waves(prog_stat_t *prog_stat, struct button *button,
list_t *game_scene, sfEvent *eve)
{
    static int wave_count = 0;
    level_t *level_cursor = find_object(game_scene, level_type)->data->level;
    int to_spawn = 0;


    if (find_object(game_scene, enemy_type) == NULL) {
        for (int i = 0; i < ENEMY_TYPES; i++) {
            to_spawn = level_cursor->l_info->enemies_to_spawn[i]
            + wave_increase(wave_count++, i);
            for (int j = 0; j < to_spawn; j++) {
                add_enemy(game_scene, enemy_info[i]);
                for (int k = 0; k < ENEMY_TYPES; k++)
                    enemy_info[k].spawn_pos.x -= SPAWN_OFFSET;
            }
        }
        for (int k = 0; k < ENEMY_TYPES; k++)
            enemy_info[k].spawn_pos.x = SPAWN_X;
    }
}