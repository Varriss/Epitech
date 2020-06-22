/*
** EPITECH PROJECT, 2019
** MY_ANIMATION
** File description:
** My_animation header
*/

#ifndef MY_ANIMATION_H_
#define MY_ANIMATION_H_

//////////////////////// VAR ////////////////////////

// const

// def struct
typedef struct sfTexture sfTexture;
typedef struct clock_s my_clock_t;
typedef struct animation_s animation_t;

// struct
struct animation_s
{
    int size;
    int width;
    int height;
    int last_time_update;
    int anim_delay;
    int anim_id;
    int anim_seq_id;
    int nbr_anim;
    int **animation_sequences;
    sfTexture **textures;
};

///////////////////// PROTOTYPE /////////////////////

// create
animation_t *animation_create(char const *texture_path,
    int texture_x, int texture_y, int nbr_anim);
int animation_add_animation(animation_t *animation, int *sequence);
void animation_set_anim_delay(animation_t *animation, int anim_delay);

// update
void amination_update(animation_t *animation, my_clock_t *clock);
void amination_safe_set_anim_seq(animation_t *animation, int anim_seq_id);
void amination_set_anim_seq(animation_t *animation, int anim_seq_id);
int animation_get_anim_seq(animation_t *animation);

// draw
sfTexture *animation_get_animation(animation_t *animation);

// destroy
void *animation_destroy(animation_t *animation);

#endif /* !MY_ANIMATION_H_ */