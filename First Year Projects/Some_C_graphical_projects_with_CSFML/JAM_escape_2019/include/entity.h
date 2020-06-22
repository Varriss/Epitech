/*
** EPITECH PROJECT, 2020
** ENTITY
** File description:
** Entity header
*/

#ifndef ENTITY_H_
#define ENTITY_H_

//////////////////////// VAR ////////////////////////

// const
static float const VEL_ACC = 25;
static float const VEL_MAX = 15;

static char const SPRITESHEET_PATH[100] = "assets/player/spritesheet.png";
static int const TEXTURE_X = 20;
static int const TEXTURE_Y = 1;
static int const ANIM_COUNT = 1;
static int const ANIM_IDLE_ID = 0;
static int const ANIM_IDLE_ANIM[21] = {0, 1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1, -1};

// defstruct
typedef struct player_s player_t;
typedef struct tilemap_s tilemap_t;
typedef struct animation_s animation_t;

// struct
struct player_s
{
    my_clock_t *clock;
    sfInt64 last_time_update;
    tilemap_t *tilemap;
    float x;
    float x_vel;
    float y;
    float y_vel;
    int width;
    int height;
    int horizontal_move;
    int vertical_move;
    sfSprite *sprite;
    animation_t *animation;
};
///////////////////// PROTOTYPE /////////////////////

player_t *player_create(my_clock_t *clock, tilemap_t *tilemap);
void player_update(player_t *player);
void player_handle_events(player_t *player, sfEvent event);
void player_draw(sfRenderWindow *window, player_t *player);
void *player_destroy(player_t *player);

#endif /* !ENTITY_H_ */