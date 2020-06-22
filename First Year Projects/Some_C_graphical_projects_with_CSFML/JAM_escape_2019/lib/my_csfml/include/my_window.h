/*
** EPITECH PROJECT, 2020
** MY_WINDOW
** File description:
** My_window header
*/

#ifndef MY_WINDOW_H_
#define MY_WINDOW_H_

//////////////////////// VAR ////////////////////////

// def struct
typedef struct sfRenderWindow sfRenderWindow;
typedef struct sfSprite sfSprite;
typedef struct sfTexture sfTexture;

///////////////////// PROTOTYPE /////////////////////

// window
sfRenderWindow *win_create(int width, int height,
    char const *name, int const framerate_limit);
int win_is_open(sfRenderWindow *window);
void *win_destroy(sfRenderWindow *window);
void win_handle_events(sfRenderWindow *window, sfEvent event);


// window_display
void win_clear(sfRenderWindow *window, sfColor color);
void win_draw_sprite(sfRenderWindow *window, sfSprite *sprite);
void win_display(sfRenderWindow *window);

#endif /* !MY_WINDOW_H_ */