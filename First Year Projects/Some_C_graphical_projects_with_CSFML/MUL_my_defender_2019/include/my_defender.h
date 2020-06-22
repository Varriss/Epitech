/*
** EPITECH PROJECT, 2020
** Model
** File description:
** proj
*/

#ifndef MY_DEFENDER_H_
#define MY_DEFENDER_H_

////////////////////////////////////////////////////////////////////////////////
//                              INCLUDES                                      //
////////////////////////////////////////////////////////////////////////////////

#include "../lib/my/my.h"
#include "../lib/lists/lists.h"

////////////////////////////////////////////////////////////////////////////////
//                               DEFINES                                      //
////////////////////////////////////////////////////////////////////////////////
#define WINDOW_HEIGHT 900
#define WINDOW_WIDTH 1600
#define WINDOW_STYLE sfClose
#define WINDOW_TITLE "My Defender"
#define WINDOW_BYTES 64
#define FRAMERATE 60
#define MENU_MUSIC "Ressources/MenuMusic.ogg"

#define TURRET_ONE "Ressources/turrets/Tower1.png"
#define TURRET_ONE_PRICE "Ressources/turrets/Tower1price.png"
#define TURRET_TWO "Ressources/turrets/Tower2.png"
#define TURRET_TWO_PRICE "Ressources/turrets/Tower2price.png"
#define TURRET_THREE "Ressources/turrets/Tower3.png"
#define TURRET_THREE_PRICE "Ressources/turrets/Tower3price.png"
#define TURRET_FOUR "Ressources/turrets/Tower4.png"
#define TURRET_FOUR_PRICE "Ressources/turrets/Tower4price.png"

#define MENU_ICON_WIDTH 200
#define MENU_ICON_HEIGHT 50

#define NB_SCENES 5

#define NB_EVT_FUNCTIONS 3

#define READ_SIZE 1

#define SUCCESS_CODE 0
#define FAILURE_CODE 84


#define MAP_WIDTH 16
#define MAP_HEIGHT 7
#define TILE_HEIGHT 100
#define TILE_WIDTH 100

#define SPAWN_X -150
#define SPAWN_Y 250
#define SPAWN_OFFSET 100

#define ENEMY_SIZE 100
#define ENEMY_SPEED 2.0f

#define FIRST_TILE_X 50
#define FIRST_TILE_Y 250

#define END_X 1550
#define END_Y 350

//
// FUNCTIONS
//
int my_defender(void);

// Tools
list_t *find_object(list_t *go_list, g_o_type_t type);
char *int_to_str_conv(int nb, char *result);

// Scenes
list_t **init_scenes(void);

// Tiles
g_tile_t *create_g_tile(sfVector2f *pos, char *path);

void manage_waves(prog_stat_t *prog_stat, struct button *button,
list_t *game_scene, sfEvent *eve);

// Inits
void init_menu_background(list_t *menu_scene);
void init_menu_buttons(list_t *menu_scene);
void init_menu_music(list_t *menu_scene);
sfText *init_text(sfColor *color, int size, sfVector2f *pos);
void initialize_hud(list_t *game);
list_data_t *init_sell_hud(void);
list_data_t *init_quit_hud(void);
list_data_t *init_start_hud(void);
list_data_t *init_tower_one_hud(void);
list_data_t *init_tower_two_hud(void);
list_data_t *init_tower_three_hud(void);
list_data_t *init_tower_four_hud(void);
int initialize_map(list_t *go_list);
void init_level(list_t *g_o_list);
list_data_t *init_tower(int tower, int x, int y);
void t_one(prog_stat_t *prog_stat, button_t *button,
list_t *game_scene, sfEvent *eve);
void t_two(prog_stat_t *prog_stat, button_t *button,
list_t *game_scene, sfEvent *eve);
void t_three(prog_stat_t *prog_stat, button_t *button,
list_t *game_scene, sfEvent *eve);
void t_four(prog_stat_t *prog_stat, button_t *button,
list_t *game_scene, sfEvent *eve);
void add_enemy(list_t *g_o_list, enemy_info_t enemy_info);
void add_enemies(prog_stat_t *prog_stat, button_t *button,
list_t *game_scene, sfEvent *eve);
void init_pause_scene_buttons(list_t *pause_scene);
list_t *init_defeat_scene(void);
list_data_t *init_main_menu_button(void);
void init_control_scene_background(list_t *list);
void init_pause_scene_background(list_t *pause_scene);

// Events
void close_window(sfEvent *event, prog_stat_t *prog_stat, list_t *g_o_list);
void analyse_events(prog_stat_t *prog_stat, list_t *scene);
int get_event_type(sfEventType srctype);
void manage_inputs(sfEvent *event, prog_stat_t *prog_stat, list_t *scene);
void button_clicked(sfEvent *event, prog_stat_t *prog_stat, list_t *g_o_list);
void get_controls(prog_stat_t *prog_stat, button_t *button, list_t *scene,
sfEvent *eve);
void main_menu(prog_stat_t *prog_stat, button_t *button, list_t *scene
, sfEvent *eve);
void quit_game(prog_stat_t *prog_stat, button_t *button, list_t *scene,
sfEvent *eve);
void start_game(prog_stat_t *prog_stat, button_t *button, list_t *scene,
sfEvent *eve);
void up_tower(prog_stat_t *prog_stat, struct button *button,
list_t *game_scene, sfEvent *eve);
void key_pressed(sfEvent *event, prog_stat_t *prog_stat, list_t *g_o_list);

// Updates
void music_menu_update(prog_stat_t *prog_stat, music_t *music,
    list_t *game_scene);
void update_enemy(prog_stat_t *prog_stat, struct enemy *enemy, \
    list_t *game_scene);
void move_enemy(enemy_t *enemy, char **map);
int check_enemy_state(enemy_t *enemy, list_t *game_scene,
prog_stat_t *prog_stat);

// Rendering
void render_scene(prog_stat_t *prog_stat, list_t *scene);
void render_button(prog_stat_t *prog_stat, button_t *button);
void render_background(prog_stat_t *prog_stat, backgr_t *backgr);
void render_scores(prog_stat_t *prog_stat, score_t *scores);
void render_tilemap(prog_stat_t *prog_stat, tile_map_t *tilemap);
void render_enemy(prog_stat_t *prog_stat, struct enemy *enemy);

// Destroy
void menu_back_destroy(prog_stat_t *prog_stat, backgr_t *background);
void button_destroy(prog_stat_t *prog_stat, button_t *button);
void destroy_tilemap(prog_stat_t *prog_stat, tile_map_t *tilemap);
void destroy_enemy(prog_stat_t *prog_stat, struct enemy *enemy);
void destroy_level(prog_stat_t *prog_stat, struct level *level);

#endif /* !MY_DEFENDER_H_ */