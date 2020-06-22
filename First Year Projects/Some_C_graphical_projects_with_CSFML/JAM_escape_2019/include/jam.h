/*
** EPITECH PROJECT, 2020
** JAM
** File description:
** My_defender header
*/

#ifndef JAM_H_
#define JAM_H_

//////////////////////// VAR ////////////////////////

// const
static int const GAMESTATE_COUNT = 5;
static int const MENU_STATE = 0;
static int const GAME_STATE = 1;
static int const PAUSE_STATE = 2;
static int const VICTORY_STATE = 3;
static int const LOSE_STATE = 4;
static int const START_STATE = MENU_STATE;

// init
static int const INIT_MONEY = 200;
static int const INIT_SCORE = 0;
static int const INIT_LIFE = 20;
static int const INIT_WAVE = 0;

// window
static int const WIDTH = 1600;
static int const HEIGHT = 900;
static char const NAME[28] = "Escape jam";
static int const FRAME_RATE = 60;

static char const GAME_FONT[33] = "assets/solvic_font.ttf";
static char const GAME_BUTTONS[27] = "assets/buttons/buttons.png";

// menu
static char const TITLE_PATH[40] = "assets/menu/title.png";
static int const TITLE_WIDTH = 1000;
static int const TITLE_HEIGHT = 500;
static char const PLAY_BUTTON_PATH[40] = "assets/menu/play_button.png";
static int const PLAY_BUTTON_WIDTH = 500;
static int const PLAY_BUTTON_HEIGHT = 210;
static int const SIDE_BUTTON_WIDTH = 500;
static int const SIDE_BUTTON_HEIGHT = 210;
static char const QUIT_PATH[40] = "assets/menu/quit_button.png";
static int const TO_BUTTON_SIZE = 510;

static float const TITLE_SCALE = 0.5;
static sfIntRect const RECT_TITLE = {
    (WIDTH - TITLE_WIDTH * TITLE_SCALE) / 2,
    50,
    TITLE_WIDTH * TITLE_SCALE, PLAY_BUTTON_HEIGHT * TITLE_SCALE};
static int const TO_SIZE = TO_BUTTON_SIZE / 4;
static int const Y_BUTTON = HEIGHT * 0.60;
static float const SCALE_BUT = 0.7;
static sfIntRect const RECT_PLAY_BUT = {
    WIDTH / 3 - PLAY_BUTTON_WIDTH * SCALE_BUT,
    Y_BUTTON - PLAY_BUTTON_HEIGHT * SCALE_BUT,
    PLAY_BUTTON_WIDTH * SCALE_BUT, PLAY_BUTTON_HEIGHT * SCALE_BUT};
static sfIntRect const RECT_QUIT_BUT = {
    WIDTH / 3 * 2,
    Y_BUTTON - PLAY_BUTTON_HEIGHT * SCALE_BUT,
    SIDE_BUTTON_WIDTH * SCALE_BUT, SIDE_BUTTON_HEIGHT * SCALE_BUT};

// help
static sfIntRect const RECT_HELP_CLOSE = {1405, 70, 120, 120};

// game
static int const SPEED_SIZE = 80;
static sfIntRect const RECT_PAUSE = {
    WIDTH - SPEED_SIZE - 10, HEIGHT - SPEED_SIZE - 10,
    SPEED_SIZE, SPEED_SIZE
};
static sfIntRect const RECT_SPEED = {
    WIDTH - (SPEED_SIZE + 10) * 2, HEIGHT - SPEED_SIZE - 10,
    SPEED_SIZE, SPEED_SIZE
};
static float const GAME_SPEED[3] = {1, 2, 3};

static char const BACKGROUND_PATH[100] = "assets/background/background.jpg";
static char const BLUR_FOREGROUND_PATH[100] =
    "assets/background/blur_foreground.png";

// pause
static char const P_RESUME_PATH[30] = "assets/pause/pause_resume.png";
static char const P_REPLAY_PATH[30] = "assets/pause/pause_replay.png";
static char const P_MENU_PATH[30] = "assets/pause/pause_menu.png";
static char const P_QUIT_PATH[30] = "assets/pause/pause_quit.png";
static int const P_RECT_WIDTH = 560;
static int const P_RECT_HEIGHT = 135;
static int const P_RECT_Y = HEIGHT / 2;
static int const P_RECT_INTER = 20;
static sfIntRect const P_RECT_RESUME = {
    (WIDTH - P_RECT_WIDTH) / 2, P_RECT_Y - P_RECT_INTER * 3 - P_RECT_HEIGHT * 2,
    P_RECT_WIDTH, P_RECT_HEIGHT,
};
static sfIntRect const P_RECT_RESTART = {
    (WIDTH - P_RECT_WIDTH) / 2, P_RECT_Y - P_RECT_INTER - P_RECT_HEIGHT,
    P_RECT_WIDTH, P_RECT_HEIGHT
};
static sfIntRect const P_RECT_MENU = {
    (WIDTH - P_RECT_WIDTH) / 2, P_RECT_Y + P_RECT_INTER,
    P_RECT_WIDTH, P_RECT_HEIGHT
};
static sfIntRect const P_RECT_QUIT = {
    (WIDTH - P_RECT_WIDTH) / 2, P_RECT_Y + P_RECT_INTER * 3 + P_RECT_HEIGHT,
    P_RECT_WIDTH, P_RECT_HEIGHT
};

// victory
static char const VICTORY_PATH[30] = "assets/victory/victory.png";

// lose
static char const WASTED_PATH[30] = "assets/lose/wasted.png";

// dependance struct
typedef struct list_s list_t;
typedef struct clock_s my_clock_t;
typedef struct tilemap_s tilemap_t;
typedef struct button_s button_t;
typedef struct tileset_s tileset_t;
typedef struct sfRenderWindow sfRenderWindow;
typedef struct tower_renderer_s tower_renderer_t;
typedef struct gamestate_manager_s gamestate_manager_t;
typedef struct player_s player_t;
typedef struct audio_s audio_t;

// def struct
typedef struct menu_s menu_t;
typedef struct game_s game_t;
typedef struct game_data_s game_data_t;
typedef struct pause_s pause_t;
typedef struct victory_s victory_t;
typedef struct lose_s lose_t;
typedef struct bullet_manager_s bullet_manager_t;
typedef struct enemy_manager_s enemy_manager_t;
typedef struct explosion_manager_s explosion_manager_t;
typedef struct tower_manager_s tower_manager_t;
typedef struct bullet_s bullet_t;
typedef struct enemy_s enemy_t;
typedef struct explosion_s explosion_t;
typedef struct tower_s tower_t;
typedef struct text_s text_t;

// struct
struct menu_s
{
    my_clock_t *clock;
    sfInt64 last_update;
    gamestate_manager_t *gsm;
    sfTexture **preview_textures;
    sfSprite *preview_sprite;
    int current_map;
    float x_map;
    button_t *title;
    button_t *play_button;
    button_t *quit_button;
};
struct game_s
{
    gamestate_manager_t *gsm;
    my_clock_t *global_clock;
    audio_t *audio;
    tilemap_t *tilemap;
    tileset_t *button_textures;
    button_t *pause_buttons;
    sfTexture *bg_texture;
    sfSprite *bg_sprite;
    sfTexture *blur_fg_texture;
    sfSprite *blur_fg_sprite;
    player_t *player;
};
struct pause_s
{
    gamestate_manager_t *gsm;
    sfTexture *bg_texture;
    sfSprite *bg_sprite;
    button_t *resume_button;
    button_t *restart_button;
    button_t *menu_button;
    button_t *quit_button;
};
struct victory_s
{
    gamestate_manager_t *gsm;
    my_clock_t *clock;
    audio_t *audio;
    sfTexture *bg_texture;
    sfTexture *wasted_texture;
    sfSprite *bg_sprite;
    sfSprite *wasted_sprite;
    tileset_t *button_textures;
    button_t *menu_button;
};
struct lose_s
{
    gamestate_manager_t *gsm;
    my_clock_t *clock;
    audio_t *audio;
    sfTexture *bg_texture;
    sfTexture *wasted_texture;
    sfSprite *bg_sprite;
    sfSprite *wasted_sprite;
    tileset_t *button_textures;
    button_t *menu_button;
};
struct text_s
{
    tileset_t *button_textures;
    sfText *text;
    sfFont *style;
    sfSprite *sprite_money;
    sfSprite *sprite_life;
};

///////////////////// PROTOTYPE /////////////////////

// main
int jam(void);

// game_killer
void kill_game(void);
int is_game_kill(void);

// game_mute
int is_game_mute(void);
void set_game_mute(int new_state);

// clock
sfInt64 clock_get_ms(my_clock_t *clock);

// draw_sprite
void win_draw_sprite(sfRenderWindow *window, sfSprite *sprite);

// menu
menu_t *menu_create(gamestate_manager_t *gsm);
void menu_handle_events(menu_t *menu, sfEvent event);
void menu_update(menu_t *menu);
void menu_draw(sfRenderWindow *window, menu_t *menu);
void *menu_destroy(menu_t *menu);
void *menu_destroy_preview_textures(sfTexture **textures);

// game
game_t *game_create(gamestate_manager_t *gsm);
int game_init_managers(game_t *game);
int game_init_audio(game_t *game);
void game_handle_events(game_t *game, sfEvent event);
void game_update(game_t *game);
void game_draw(sfRenderWindow *window, game_t *game);
void *game_destroy(game_t *game);

// pause
pause_t *pause_create(gamestate_manager_t *gsm);
void pause_handle_events(pause_t *pause, sfEvent event);
void pause_update(pause_t *pause);
void pause_draw(sfRenderWindow *window, pause_t *pause);
void *pause_destroy(pause_t *pause);

// victory
victory_t *victory_create(gamestate_manager_t *gsm);
void victory_handle_events(victory_t *victory, sfEvent event);
void victory_update(victory_t *victory);
void victory_draw(sfRenderWindow *window, victory_t *victory);
void *victory_destroy(victory_t *victory);

// lose
lose_t *lose_create(gamestate_manager_t *gsm);
void lose_handle_events(lose_t *lose, sfEvent event);
void lose_update(lose_t *lose);
void lose_draw(sfRenderWindow *window, lose_t *lose);
void *lose_destroy(lose_t *lose);

#endif /* !JAM_H_ */