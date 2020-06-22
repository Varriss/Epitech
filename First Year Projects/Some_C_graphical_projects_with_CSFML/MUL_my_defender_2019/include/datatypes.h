/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019_2
** File description:
** datatypes
*/

#ifndef DATATYPES_H_
#define DATATYPES_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct list list_t;
#define ENEMY_TYPES 3

///////////////////////////////////////////////////////////////////////////////
//                              Gameobject structures                        //
///////////////////////////////////////////////////////////////////////////////

typedef enum g_o_type
{
    enemy_type,
    button_type,
    background_type,
    music_type,
    tile_map_type,
    level_type,
    tower_type
} g_o_type_t;

typedef struct program_status
{
    sfRenderWindow *window;
    sfTexture *last_window;
    int running;
    int scene_index;
} prog_stat_t;

typedef struct player_info
{
    int score;
    int life;
    int money;
} player_info_t;

typedef struct level_info
{
    char **map;
    int enemies_to_spawn[ENEMY_TYPES];
    int enemies_left;
} level_info_t;

typedef struct level
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct level *level, \
    list_t *game_scene);
    void (*render)(prog_stat_t *prog_stat, struct level *level);
    void (*destroy)(prog_stat_t *prog_stat, struct level *level);
    player_info_t *p_info;
    level_info_t *l_info;
    int selected_tower;
    int last_selected_tower;
} level_t;


typedef struct enemy
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct enemy *enemy,
    list_t *game_scene);
    void (*render)(prog_stat_t *prog_stat, struct enemy *enemy);
    void (*destroy)(prog_stat_t *prog_stat, struct enemy *enemy);
    int life;
    int state;
    int bounty;
    float speed;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect *rect;
    sfVector2f prev_pos;
    sfVector2f pos;
    sfVector2f next_pos;
    sfClock *clock;
} enemy_t;

typedef struct tower
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct tower *enemy,
    list_t *game_scene);
    void (*render)(prog_stat_t *prog_stat, struct tower *enemy);
    void (*destroy)(prog_stat_t *prog_stat, struct tower *enemy);
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfClock *clock;
    float range;
    float damage;
    float ats;
} tower_t;

typedef struct enemy_info
{
    int life_val;
    int bounty;
    char *sprite_path;
    float speed;
    sfVector2f spawn_pos;
    sfVector2f scale;
} enemy_info_t;

typedef struct button
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct button *button,
    list_t *game_scene);
    void (*render)(prog_stat_t *prog_stat, struct button *button);
    void (*destroy)(prog_stat_t *prog_stat, struct button *button);
    void (*onclick)(prog_stat_t *prog_stat, struct button *button,
    list_t *game_scene, sfEvent *eve);
    sfVector2f pos;
    sfTexture *textu;
    sfSprite *sprite;
    int id;
} button_t;

typedef struct music
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct music *music,
    list_t *game_scene);
    void (*render)(prog_stat_t *prog_stat, struct music *music);
    void (*destroy)(prog_stat_t *prog_stat, struct music *music);
    sfMusic *music;
    int running;
    int scene_own;
} music_t;

typedef struct background
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct background *backgr,
    list_t *game_scene);
    void (*render)(prog_stat_t *prog_stat, struct background *backgr);
    void (*destroy)(prog_stat_t *prog_stat, struct background *backgr);
    sfVector2f pos;
    sfTexture *textu;
    sfSprite *sprite;
} backgr_t;

typedef struct score
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct score *backgr,
    list_t *game_scene);
    void (*render)(prog_stat_t *prog_stat, struct score *backgr);
    void (*destroy)(prog_stat_t *prog_stat, struct score *backgr);
    sfVector2f pos;
    sfTexture *textu;
    sfSprite *sprite;
    sfText *score_value;
    sfText *money_value;
    sfText *hp_value;
    sfText *score;
    sfText *money;
    sfText *hp;
} score_t;

///////////////////////////////////////////////////////////////////////////////
//                              Tilemap structures                           //
///////////////////////////////////////////////////////////////////////////////

typedef enum tile_type
{
    ground_type,
    path_type,
} tile_type;

typedef struct ground_tile
{
    tile_type type;
    void (*update)(struct ground_tile *);
    void (*render)(struct ground_tile *, sfRenderWindow *window);
    void (*destroy)(struct ground_tile *);
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
} g_tile_t;

typedef union tile
{
    g_tile_t *ground_tile;
} tile_t;

typedef struct tile_map
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct tile_map *tilemap,
    list_t *game_scene);
    void (*render)(prog_stat_t *prog_stat, struct tile_map *tilemap);
    void (*destroy)(prog_stat_t *prog_stat, struct tile_map *tilemap);
    void (*onclick)(prog_stat_t *prog_stat, struct button *button,
    list_t *game_scene, sfEvent *eve);
    int map_height;
    int map_width;
    char **map;
    tile_t **tiles;
} tile_map_t;

///////////////////////////////////////////////////////////////////////////////
//                         Linked list Datastructure                         //
///////////////////////////////////////////////////////////////////////////////

typedef union list_data
{
    enemy_t *enemy;
    button_t *button;
    backgr_t *background;
    music_t *music;
    tile_map_t *tile_map;
    score_t *scores;
    level_t *level;
    tower_t *tower;
} list_data_t;

#endif /* !DATATYPES_H_ */