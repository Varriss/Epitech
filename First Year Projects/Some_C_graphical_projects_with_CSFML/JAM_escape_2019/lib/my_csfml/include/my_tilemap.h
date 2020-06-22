/*
** EPITECH PROJECT, 2019
** MY_TILEMAP
** File description:
** My_tilemap header
*/

#ifndef MY_TILEMAP_H_
#define MY_TILEMAP_H_

//////////////////////// VAR ////////////////////////

// const

// def struct
typedef struct sfRenderWindow sfRenderWindow;
typedef struct clock_s my_clock_t;
typedef struct sfTexture sfTexture;
typedef struct tileset_s tileset_t;
typedef struct tilemap_s tilemap_t;

// struct
struct tilemap_s
{
    sfInt64 last_time_update;
    int tilesize;
    tileset_t *tileset;
    float x;
    float y;
    int width;
    int height;
    int xmin;
    int xmax;
    int ymin;
    int ymax;
    float tween;
    int frame_width;
    int frame_height;
    int nb_maps;
    int ***maps;
};

///////////////////// PROTOTYPE /////////////////////

// tilemap_create
tilemap_t *tilemap_create(int tilesize, int frame_width, int frame_height);
void tilemap_update_bounds(tilemap_t *tilemap);
void tilemap_set_xymax(tilemap_t *tilemap, int width, int height);

// load
int tilemap_load_tiles(tilemap_t *tilemap, char const *tileset_path, int size);
int tilemap_load_map(tilemap_t *tilemap, char const *map_path, int nb_maps);
int tilemap_create_empty_maps(tilemap_t *tilemap, int nb_maps,
    int width, int height);

// tilemap_draw
void tilemap_draw_layer(sfRenderWindow *window, tilemap_t *tilemap, int layer);
void tilemap_draw_layer_scale(sfRenderWindow *window, tilemap_t *tilemap,
    int layer, float s);
void tilemap_draw(sfRenderWindow *window, tilemap_t *tilemap);

// tilemap_collision
int tilemap_rect_col(sfFloatRect a, sfFloatRect b);
int tilemap_can_collide(tilemap_t *tilemap, int map_id, sfFloatRect bounds);
int tilemap_map_collision(tilemap_t *tilemap, int map_id,
    sfFloatRect bounds, sfFloatRect *collision);
int update_row_col(tilemap_t *tilemap, int *row, int *col, int col_min);

// tilemap_destroy
int free_datas(char *map_data, char **map_datas, int rnt_value);
int **destroy_map(int **map);
void *tilemap_destroy(tilemap_t *tilemap);

// tilemap_update
void tilemap_force_pos(tilemap_t *tilemap, float x, float y);
void tilemap_set_pos(tilemap_t *tilemap, my_clock_t *clock, float x, float y);

#endif /* !MY_TILEMAP_H_ */