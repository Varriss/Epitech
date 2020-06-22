/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** datatypes
*/

#ifndef DATATYPES_H_
#define DATATYPES_H_

////////////////////////////////////////////////////////////////////////////////
//                              Previous Declarations                         //
////////////////////////////////////////////////////////////////////////////////
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
typedef struct list list_t;
typedef struct musics_and_sounds musics_and_sounds_t;
typedef struct life_bar life_bar_t;

typedef struct program_status
{
    sfRenderWindow *window;
    int running;
    int scene_index;
    musics_and_sounds_t *musics_sounds;
    sfTexture *last_window;
    int prev_index;
} prog_stat_t;

////////////////////////////////////////////////////////////////////////////////
//                              Gameobject structures                         //
////////////////////////////////////////////////////////////////////////////////

typedef enum g_o_type
{
    button_type,
    background_type,
    music_list_type,
    sound_buffers_type,
    sound_type,
    tile_map_type,
    clock_type,
    enemy_type,
    player_cursor_type,
    player_type,
    customer_type
} g_o_type_t;

typedef enum audio_id
{
    button_click,
    menu_background_music,
    heartbeat,
    dragon_roar,
    dragon_pain,
    male_pain,
    sword_sound,
    walk,
    encounter
} audio_id_t;

typedef struct musics_and_sounds
{
    list_t *musics_list;
    list_t *sounds_buffer_list;
    list_t *sounds_list;
} musics_and_sounds_t;

typedef struct button
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct button *button,
    list_t *own_scene);
    void (*render)(prog_stat_t *prog_stat, struct button *button);
    void (*destroy)(prog_stat_t *prog_stat, struct button *button);
    void (*onclick)(prog_stat_t *prog_stat, struct button *button,
    list_t *game_scene, sfEvent *eve);
    sfVector2f pos;
    sfIntRect rect;
    int offset;
    sfTexture *textu;
    sfSprite *sprite;
    int id;
} button_t;

typedef struct background
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct background *backgr,
    list_t *own_scene);
    void (*render)(prog_stat_t *prog_stat, struct background *backgr);
    void (*destroy)(prog_stat_t *prog_stat, struct background *backgr);
    sfVector2f pos;
    sfTexture *textu;
    sfSprite *sprite;
} backgr_t;

typedef struct enemy
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct enemy *enemy,
    list_t *own_scene);
    void (*render)(prog_stat_t *prog_stat, struct enemy *enemy);
    void (*destroy)(prog_stat_t *prog_stat, struct enemy *enemy);
    sfVector2f pos;
    sfIntRect rect;
    sfTexture *textu;
    sfSprite *sprite;
    int life;
    int animated;
    int turn;
    sfClock *clock;
    life_bar_t *life_bar;
} enemy_t;

// ITEMS
typedef enum item_type
{
    potion_type,
    blade_type,
    shield_type,
    item_number
} item_type_t;

typedef struct potion
{
    item_type_t type;
    void (*update)(prog_stat_t *, struct potion *, list_t *);
    void (*render)(prog_stat_t *, struct potion *, list_t *);
    void (*destroy)(prog_stat_t *, struct potion *, list_t *);
    void (*onhover)(prog_stat_t *, struct potion *, list_t *);
    void (*onuse)(prog_stat_t *, struct potion *, list_t *);
    sfBool can_use;
    sfBool can_hover;
    sfBool display;
    sfBool used;
    sfTexture *texture;
    sfSprite *sprite;
    sfText *text;
    sfVector2f pos;
    int player_has;
    int price;
    int heal_value;
} potion_t;

typedef struct blade
{
    item_type_t type;
    void (*update)(prog_stat_t *, struct blade *, list_t *);
    void (*render)(prog_stat_t *, struct blade *, list_t *);
    void (*destroy)(prog_stat_t *, struct blade *, list_t *);
    void (*onhover)(prog_stat_t *, struct blade *, list_t *);
    void (*onuse)(prog_stat_t *, struct blade *, list_t *);
    sfBool can_use;
    sfBool can_hover;
    sfBool display;
    sfBool used;
    sfTexture **texture;
    sfSprite *sprite;
    sfVector2f pos;
    int player_has;
    int lvl;
    int quest;
    int quest_completion;
} blade_t;

typedef struct shield
{
    item_type_t type;
    void (*update)(prog_stat_t *, struct shield *, list_t *);
    void (*render)(prog_stat_t *, struct shield *, list_t *);
    void (*destroy)(prog_stat_t *, struct shield *, list_t *);
    void (*onhover)(prog_stat_t *, struct shield *, list_t *);
    void (*onuse)(prog_stat_t *, struct shield *, list_t *);
    sfBool can_use;
    sfBool can_hover;
    sfBool display;
    sfBool used;
    sfTexture **texture;
    sfSprite *sprite;
    sfVector2f pos;
    int player_has;
    int lvl;
    int quest;
    int quest_completion;
} shield_t;

typedef union item
{
    potion_t *potion;
    blade_t *blade;
    shield_t *shield;
} item_t;

typedef struct item_sorter
{
    item_type_t type;
    item_t *(*add_item)(void);
} item_sorter_t;

typedef struct gold_counter
{
    void (*update)(prog_stat_t *, struct gold_counter *, list_t *);
    void (*render)(prog_stat_t *, struct gold_counter *, list_t *);
    void (*destroy)(prog_stat_t *, struct gold_counter *, list_t *);
    int golds;
    sfText *gold_text;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    sfClock *clock;
} gold_counter_t;

typedef struct inventory
{
    void (*update)(prog_stat_t *prog_stat, struct inventory *inventory,
    list_t *own_scene);
    void (*render)(prog_stat_t *prog_stat, struct inventory *inventory,
    list_t *own_scene);
    void (*destroy)(prog_stat_t *prog_stat, struct inventory *inventory,
    list_t *own_scene);
    int life;
    gold_counter_t *gold_counter;
    item_t **items;
} inventory_t;

typedef struct player
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct player *player,
    list_t *own_scene);
    void (*render)(prog_stat_t *prog_stat, struct player *player,
    list_t *scene);
    void (*destroy)(prog_stat_t *prog_stat, struct player *player,
    list_t *scene);
    sfVector2f pos;
    sfIntRect rect;
    sfTexture *textu;
    sfSprite *sprite;
    int defense;
    int turn;
    int animeted;
    inventory_t *inventory;
    sfClock *clock;
    life_bar_t *life_bar;
    sfView *view;
} player_t;

typedef struct life_bar
{
    sfVector2f pos;
    sfIntRect rect;
    sfTexture *textu;
    sfSprite *sprite;
} life_bar_t;

typedef struct customer_api
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct customer_api *customer,
    list_t *own_scene);
    void (*render)(prog_stat_t *prog_stat, struct customer_api *customer);
    void (*destroy)(prog_stat_t *prog_stat, struct customer_api *customer);
    inventory_t *inventory;
    inventory_t *shop_items;
    sfSprite **monolugus;
    sfVector2f monologus_pos;
} customer_t;

typedef struct music
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct music *music,
    list_t *own_scene);
    void (*render)(prog_stat_t *prog_stat, struct music *music);
    void (*destroy)(prog_stat_t *prog_stat, struct music *music);
    audio_id_t id;
    sfMusic *music;
    int running;
} music_t;

typedef struct sound
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct sound *sound,
    list_t *own_scene);
    void (*render)(prog_stat_t *prog_stat, struct sound *sound);
    void (*destroy)(prog_stat_t *prog_stat, struct sound *sound);
    sfSound *sound;
} sound_t;

typedef struct sound_buffer
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct sound_buffer *buffer,
    list_t *own_scene);
    void (*render)(prog_stat_t *prog_stat, struct sound_buffer *buffer);
    void (*destroy)(prog_stat_t *prog_stat, struct sound_buffer *buffer);
    audio_id_t id;
    sfSoundBuffer *buffer;
} sound_buffer_t;

typedef struct tile_s tile_t;

typedef struct player_cursor
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct player_cursor *player_c,
    list_t *own_scene);
    void (*render)(prog_stat_t *prog_stat, struct player_cursor *player_c,
    list_t *own_scene);
    void (*destroy)(prog_stat_t *prog_stat, struct player_cursor *player_c,
    list_t *own_scene);
    char *current_tile;
    tile_t *tile_ptr;
    inventory_t *inventory;
    sfVector2f pos;
    sfVector2f sprite_pos;
    sfIntRect *rect;
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
    sfView *view;
} player_cursor_t;

typedef struct particle
{
    sfVector2f traj;
    sfVector2f pos;
} particle_t;

typedef struct explosion
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct explosion *explode,
    list_t *own_scene);
    void (*render)(prog_stat_t *prog_stat, struct explosion *explode,
    list_t *own_scene);
    void (*destroy)(prog_stat_t *prog_stat, struct explosion *explod,
    list_t *own_scene);
    sfVector2f origin;
    list_t *particles;
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
    int life_time;
} explosion_t;

////////////////////////////////////////////////////////////////////////////////
//                              Tilemap structures                         //
////////////////////////////////////////////////////////////////////////////////
typedef struct active_list_s
{
    int type;
    int x;
    int y;
} active_list_t;

typedef struct tile_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
} tile_t;

typedef struct tile_map
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct tile_map *tilemap,
    list_t *game_scene);
    void (*render)(prog_stat_t *prog_stat, struct tile_map *tilemap);
    void (*destroy)(prog_stat_t *prog_stat, struct tile_map *tilemap);
    int map_height;
    int map_width;
    char **map;
    tile_t **tiles;
} tile_map_t;

typedef struct tilemap_scene
{
    char tile_id;
    void (*tile_action)(prog_stat_t *prog_stat, struct player_cursor *player_c,
    list_t *own_scene);
    int scene_id;
} tmap_scene_t;

typedef struct clock_s
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct clock_s *clock,
    list_t *game_scene);
    void (*render)(prog_stat_t *prog_stat, struct clock_s *clock);
    void (*destroy)(prog_stat_t *prog_stat, struct clock_s *clock);
    sfClock *clock;
    int is_paused;
    sfInt64 paused_at;
    sfInt64 to_add;
    sfInt64 speed_at;
    sfVector2f pos;
    sfText *text;
    float speed;
    float pause_speed;
} my_clock_t;
////////////////////////////////////////////////////////////////////////////////
//                         Linked list Datastructure                          //
////////////////////////////////////////////////////////////////////////////////

typedef union list_data
{
    button_t *button;
    backgr_t *background;
    music_t *music;
    sound_buffer_t *buffer;
    sound_t *sound;
    tile_map_t *tile_map;
    active_list_t *active;
    my_clock_t *clock;
    enemy_t *enemy;
    player_t *player;
    player_cursor_t *player_c;
    item_t *item;
    customer_t *customer_api;
    explosion_t *explode;
    particle_t *particle;
} list_data_t;

#endif /* !DATATYPES_H_ */