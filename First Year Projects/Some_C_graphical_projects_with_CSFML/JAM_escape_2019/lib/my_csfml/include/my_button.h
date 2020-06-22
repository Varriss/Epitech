/*
** EPITECH PROJECT, 2020
** MY_BUTTON
** File description:
** My_button header
*/

#ifndef MY_BUTTON_H_
#define MY_BUTTON_H_

//////////////////////// VAR ////////////////////////

// const
static const sfInt64 MIN_ANIM_TIME = 100;

// def struct
typedef struct button_s button_t;
typedef struct clock_s my_clock_t;
typedef struct sfRenderWindow sfRenderWindow;

// struct
struct button_s
{
    my_clock_t *clock;
    sfInt64 pressed_at;
    int is_passed;
    int is_clicked;
    int is_pressed;
    int is_released;
    void (*callback)();
    char *text;
    sfIntRect *bounds;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f normal_scale;
    sfVector2f passed_scale;
    sfVector2f pressed_scale;
};

///////////////////// PROTOTYPE /////////////////////

// constructor destructor
button_t *button_create_from_texture(sfIntRect bounds, sfTexture *texture);
button_t *button_create_from_path(sfIntRect bounds, char const *bg_path);
void button_init_null(button_t *button);
void button_init_bounds(button_t *button, sfIntRect bounds);
void *button_destroy(button_t *button);

// update
void button_handle_events(button_t *button, sfEvent event);
void button_update(button_t *button);
void button_draw(sfRenderWindow *window, button_t *button);

int button_is_click(button_t *button);

// force
void button_force_press(button_t *button);
void button_force_release(button_t *button);
void button_force_reset(button_t *button);

sfTexture *button_get_black_texture(void);

#endif /* !MY_BUTTON_H_ */