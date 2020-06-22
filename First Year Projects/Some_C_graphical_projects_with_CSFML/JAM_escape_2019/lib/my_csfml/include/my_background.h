/*
** EPITECH PROJECT, 2019
** MY_BACKGROUND
** File description:
** My_background header
*/

#ifndef MY_BACKGROUND_H_
#define MY_BACKGROUND_H_

//////////////////////// VAR ////////////////////////

// const

// def struct
typedef struct background_s background_t;
typedef struct clock_s my_clock_t;
typedef struct sfSprite sfSprite;
typedef struct sfTexture sfTexture;
typedef struct sfRenderWindow sfRenderWindow;

// struct
struct background_s
{
    int nb_layer;
    float *vx;
    int frame_width;
    int frame_height;
    sfTexture **textures;
    sfSprite **sprites;
};

///////////////////// PROTOTYPE /////////////////////

// background
background_t *background_create(int nb_layer,
    int frame_width, int frame_height);
void background_add(background_t **background, int height, float vx,
    char const *path);
void *background_destroy(background_t *background);

// background_draw
void background_draw(sfRenderWindow *window,
    background_t *background, int frame);
void background_draw_clock(sfRenderWindow *window,
    background_t *background, my_clock_t *clock);

// background_destroy
void *background_destroy(background_t *background);

#endif /* !MY_BACKGROUND_H_ */