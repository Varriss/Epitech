/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_rpg
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

////////////////////////////////////////////////////////////////////////////////
//                              INCLUDES                                      //
////////////////////////////////////////////////////////////////////////////////

#include "../lib/my/my.h"
#include "../lib/lists/lists.h"

#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
//                               DEFINES                                      //
////////////////////////////////////////////////////////////////////////////////
#define SUCCESS_CODE 0
#define FAILURE_CODE 84

#define WINDOW_HEIGHT 900
#define WINDOW_WIDTH 1600
#define WINDOW_STYLE sfClose
#define WINDOW_TITLE "My RPG"
#define WINDOW_BYTES 64
#define FRAMERATE 60

#define PARTICLE "ressources/particles/particle.png"
#define HEAL_PARTICLE "ressources/particles/particle_heal.png"
#define MAX_PARTICLES 300

/////// MENU /////
#define MENU_BACKGROUND "ressources/menu/background.png"
#define MENU_ICON_WIDTH 200
#define MENU_ICON_HEIGHT 50
#define MENU_START_BUTTON "ressources/menu/start.png"
#define MENU_QUIT_BUTTON "ressources/menu/quit.png"
#define MENU_HOW_TO_BUTTON "ressources/menu/how_to_button.png"
#define MENU_PAUSED "ressources/menu/game_paused.png"
#define MENU_RESUME_BUTTON "ressources/menu/resume.png"
#define MENU_MENU_BETTON "ressources/menu/main_menu.png"
/////// HOW_TO /////
#define HOW_TO_BACKGROUND "ressources/menu/how_to.png"

////// SHOP ///////
#define SHOP_BACKGROUND "ressources/shop/background.png"

////// FIGHT ///////
#define PATH_FIGHT "ressources/fight/path_fight_background.png"
#define BOSS_SPRITE "ressources/fight/boss.png"
#define BOSS_BACKGROUND "ressources/fight/fontp2.png"
#define FIGHT_BACKGROUND "ressources/fight/fonp.png"
#define FIGHT_ATTACK_BUTTON "ressources/fight/fight.png"
#define PLAYER_SPRITE "ressources/fight/player.png"
#define LIFE_BAR "ressources/fight/vie.png"
#define PLAYER_MAX_HP 6
#define VICTORY "ressources/fight/win.png"
#define GAME_OVER "ressources/fight/game_over.png"
#define BACK_TOGAME_BUTTON "ressources/fight/back.png"
#define TRYAGAIN "ressources/fight/tryagain.png"
#define BOSS_DAMAGE 2
#define ENEMY_DAMAGE 1

////// ITEMS //////
#define MAX_BLADE_LVL 2
#define POTION_SPRITE "ressources/items/lesser_healing_potion.png"
#define POTION_PRICE 5
#define POTION_HEAL 2
#define GOLD_PIECE_SPRITE "ressources/items/01coin.png"
#define STARTING_GOLD 100
////// MAP //////
#define TOTAL_TIME 360
#define FONT_STYLE_ONE "ressources/solvic_font.ttf"
#define MAP_WIDTH 40
#define MAP_HEIGHT 20
#define TILE_HEIGHT 40
#define TILE_WIDTH 40

////////  SOUNDS ///////
#define CLICK_SOUND "ressources/sound/button_click.ogg"
#define GAME_HEARTBEAT "ressources/music/heartbeat.ogg"
#define DRAKE_ATTACK "ressources/sound/dragon_attack.ogg"
#define DRAKE_PAIN "ressources/sound/dragon_pain.ogg"
#define MALE_PAIN "ressources/sound/male_pain.ogg"
#define SWORD_ATTACK "ressources/sound/sword_swoosh.ogg"
#define WALK_SOUND "ressources/sound/walk.ogg"
#define ENCOUNTER_SOUND "ressources/sound/monster_encounter/ogg"

/////// MUSICS ///////
#define MENU_MUSIC "ressources/music/menu_music.ogg"

/////// NUMBERS //////
#define SHOPS_NBR 3
#define BOSS_NBR 2
#define TRAPS_NBR 20
#define CHESTS_NBR 4

#define NB_SCENES 9
typedef enum scenes_index
{
    menu_scene,
    game_scene,
    fight_scene,
    shop_scene,
    victory_scene,
    game_over_scene,
    how_to_play_scene,
    boss_scene,
    pause_scene,
    nb_scenes
} scenes_index_t;

#define MAX_SOUNDS_AT_ONCE 5
#define NB_EVT_FUNCTIONS 3

#define READ_SIZE 1

// PLAYER INFO

#define PLAYER_CURSOR_SPRITE "ressources/player/player_cursor1.png"

// test to remove function
list_data_t *init_fight_button(void);
////////////////////////////////////////////////////////////////////////////////
//                               FUNCTIONS                                    //
////////////////////////////////////////////////////////////////////////////////
int role_play_game(void);

////////////////////////
//   INITIALISATION   //
////////////////////////
list_t **init_scenes(void);
list_t *init_menu_scene(void);
list_t *init_game_scene(void);
list_t *init_boss_scene(list_t *game_scene);
list_t *init_fight_scene(list_t *game_scene);
list_t *init_shop_scene(list_t *game_scene);
list_t * game_over_scene_init(void);
list_t *victory_init(void);
list_t *init_how_to_scene(void);

void create_heal_effect(list_t *scene, sfVector2f origin);
void create_explosion(list_t *scene, sfVector2f origin);

void create_particles(explosion_t *explode);
void init_barlife_enemy(enemy_t *enemy, int count);
list_data_t *init_how_to_button(void);
void init_enemy(list_t *fight_scene);
void init_boss(list_t *boss_scene);
void init_player(list_t *fight_scene, list_t *game_scene);
list_t *victory(list_t *fight_scene);
list_t *game_over(list_t *fight_scene);
sfText *init_text(sfVector2f pos, int size);
my_clock_t *clock_create(void);
list_t *sound_buffers_create(void);
list_t *music_create(void);
list_t *empty_sounds_create(void);
void init_player_c(list_t *game_scene);
void init_buttons_game(list_t *game);
int initialize_map(list_t *go_list);
tile_map_t *create_map(char **map_str);
tile_t *convert_tile(sfVector2f *current_pos, char tile_type);
void fill_map(char **map);
void fill_tile_dimensions(sfIntRect *rect, sfVector2f *pos);
tile_t *create_tile(sfVector2f *pos, char *path);
tile_t **fill_tilemap(char **map_str, tile_map_t *dest);
void fill_with_map(char **map, int elem_nbr, char area, char id);
void load_next_level(prog_stat_t *prog_stat, player_cursor_t *player_c,
list_t *go_list);
item_t *create_blade_item(void);
item_t *create_shield_item(void);

gold_counter_t *init_gold_counter(void);
inventory_t *init_inventory(void);
item_t *create_potion_item(void);
list_t *init_pause_scene(void);
void init_pause_scene_background(list_t *pause_scene);
void init_pause_scene_buttons(list_t *pause_scene);
////////////////////////
//  EVENTS_HANDLING   //
////////////////////////
void analyse_events(prog_stat_t *, list_t *scene);
void button_clicked(sfEvent *event, prog_stat_t *prog_stat, list_t *g_o_list);
void close_window(sfEvent *, prog_stat_t *, list_t *scene);
void start_game(prog_stat_t *, button_t *, list_t *scene, sfEvent *);
void quit_game(prog_stat_t *, button_t *, list_t *scene, sfEvent *);
void main_menu(prog_stat_t *prog_stat, button_t *button, list_t *scene,
sfEvent *eve);
void direction_pressed(sfEvent *event, prog_stat_t *prog_stat,
list_t *g_o_list);
void back_to_game(prog_stat_t *prog_stat, struct button *button,
list_t *game_scene, sfEvent *eve);
void check_item_consumption(sfEvent *event, prog_stat_t *prog_stat,
list_t *scene);
void use_potion(prog_stat_t *prog_stat, potion_t *potion, list_t *scene);
////////////////////////
//     UPDATING       //
////////////////////////
void clock_set_speed(my_clock_t *clock, float speed);
float clock_get_speed(my_clock_t *clock);
void clock_pause(my_clock_t *clock);
void clock_unpause(my_clock_t *clock);
void update_player_cursor(prog_stat_t *prog_stat
, struct player_cursor *player_c, list_t *own_scene);
void manage_tilemap_actions(prog_stat_t *prog_stat, player_cursor_t *player_c,
list_t *go_list);
void update_potion(prog_stat_t *prog_stat, potion_t *potion,
list_t *scene);
void update_inventory(prog_stat_t *prog_stat, inventory_t *inventory,
list_t *scene);
void update_g_counter(prog_stat_t *prog_stat, gold_counter_t *counter,
list_t *scene);
void update_particle_pos(prog_stat_t *prog_stat, explosion_t *explode,
list_t *own_scene);
void update_shield(prog_stat_t *prog_stat, shield_t *potion,
list_t *scene);
void update_my_clock(prog_stat_t *prog_stat, my_clock_t *clock, list_t *scene);
////////////////////////
//     RENDERING      //
////////////////////////
void render_button(prog_stat_t *prog_stat, button_t *button);
void render_background(prog_stat_t *prog_stat, backgr_t *backgr);
void render_tilemap(prog_stat_t *prog_stat, tile_map_t *tilemap);
void win_draw_time(prog_stat_t *prog_stat, my_clock_t *clock);
void render_enemy(prog_stat_t *prog_stat, enemy_t *enemy);
void render_player(prog_stat_t *prog_stat, player_t *player, list_t *scene);
void play_sound(audio_id_t id, prog_stat_t *prog_stat);
void render_player_cursor(prog_stat_t *prog_stat
, struct player_cursor *player_c, list_t *own_scene);
void render_potion(prog_stat_t *prog_stat, potion_t *potion,
list_t *scene);
void render_inventory(prog_stat_t *prog_stat, inventory_t *inventory,
list_t *scene);
void render_default_background(prog_stat_t *prog_stat, backgr_t *backgr);
void render_explode(prog_stat_t *prog_stat, explosion_t *explode,
list_t *own_scene);
void render_g_counter(prog_stat_t *prog_stat, gold_counter_t *counter,
list_t *scene);
void create_explosion(list_t *scene, sfVector2f origin);
void render_blade(prog_stat_t *prog_stat, blade_t *potion,
list_t *scene);
void render_shield(prog_stat_t *prog_stat, shield_t *potion,
list_t *scene);

////////////////////////
//    DESTROYING      //
////////////////////////
void button_destroy(prog_stat_t *prog_stat, button_t *button);
void backgr_destroy(prog_stat_t *prog_stat, backgr_t *backgr);
void destroy_tilemap(prog_stat_t *prog_stat, tile_map_t *tilemap);
void clock_destroy(prog_stat_t *prog_stat, my_clock_t *clock);
void music_destroy(prog_stat_t *prog_stat, music_t *music);
void enemy_destroy(prog_stat_t *prog_stat, enemy_t *enemy);
void player_destroy(prog_stat_t *prog_stat, player_t *player, list_t *scene);
void destroy_player_cursor(prog_stat_t *prog_stat,
struct player_cursor *player_c, list_t *own_scene);
void destroy_potion(prog_stat_t *prog_stat, potion_t *potion,
list_t *scene);
void destroy_inventory(prog_stat_t *prog_stat, inventory_t *inventory,
list_t *scene);
void destroy_explode(prog_stat_t *prog_stat, explosion_t *explode,
list_t *own_scene);
void destroy_g_counter(prog_stat_t *prog_stat, gold_counter_t *counter,
list_t *scene);
void destroy_blade(prog_stat_t *prog_stat, blade_t *potion,
list_t *scene);
void destroy_shield(prog_stat_t *prog_stat, shield_t *potion,
list_t *scene);
////////////////////////
//      OTHERS        //
////////////////////////
sfInt64 clock_get_s(my_clock_t *clock);
sfInt64 clock_get_ms(my_clock_t *clock);
sfInt64 clock_get_mcs(my_clock_t *clock);
list_t * get_music_sound_cursor(list_t *root, audio_id_t id);
list_data_t *add_music_data(char *file, audio_id_t id);
list_t *get_next_sound_cell(list_t *sounds_list);
my_clock_t *get_my_clock(list_t *scene);
list_t *find_object(list_t *go_list, g_o_type_t type);
list_t *find_object_r(list_t *go_list, g_o_type_t type);
void reload_map(prog_stat_t *prog_stat, list_t *scene);
void set_next_turn(list_t *actual_player);
void engage_player(prog_stat_t *prog_stat, list_t *scene, enemy_t *me);
void attack_attack(prog_stat_t *prog_stat, list_t *scene,
sfEvent *eve);
void set_scale_and_color(enemy_t *enemy, int count);
list_t *find_me_in_list(list_t *list, enemy_t *me);
void boss_anim(enemy_t *enemy, float seconds);
void attack_anim(enemy_t *enemy, float seconds);
void destroy_trap(prog_stat_t *prog_stat, player_cursor_t *player_c,
list_t *go_list);
void chest_loot(prog_stat_t *prog_stat, player_cursor_t *player_c,
list_t *scene);
char *int_to_str(int nb);
sfVector2f place_enemy(int count, int mode);
int count_enemy(list_t *list);
list_t *find_particle_in_list(list_t *list, explosion_t *me);
void come_back_to_scene(prog_stat_t *prog_stat, struct button *button,
list_t *game_scene, sfEvent *eve);
void boss_load(prog_stat_t *prog_stat, player_cursor_t *player_c,
list_t *go_list);
void switch_tile_to_path(player_cursor_t *player_c);
#endif /* !MY_RPG_H_ */