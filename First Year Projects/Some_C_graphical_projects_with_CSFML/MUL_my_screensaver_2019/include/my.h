/*
** EPITECH PROJECT, 2019
** MUL
** File description:
** my
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>

#ifndef MY_H_
#define MY_H_

typedef struct tab_of_function_pointer
{
    int ind;
    void (*foo)();
} func_tab;
typedef struct s_framebuffer
{
    unsigned char *pixels;
    unsigned int width;
    unsigned int height;
} t_framebuffer;
typedef struct s_pos
{
    float x;
    float y;
} t_pos;
typedef struct accel
{
    float x;
    float y;
} accel;
typedef struct circle_move
{
    t_pos ori;
    accel acc;
    sfColor change;
} circl_mov;
typedef struct fade_of
{
    t_pos preori;
    sfColor fadecol;
} fade;
typedef struct fading_ball
{
    circl_mov cir;
    fade cir_fade;
} balfade;

sfRenderWindow *open_win(int width, int height
, int bytes, sfRenderWindow *window);
t_framebuffer *frambuffer_gen(int width, int height, t_framebuffer *fb);
void framebuffer_kill(t_framebuffer *fb);
void my_put_pixel(t_framebuffer *fb, unsigned int x, unsigned int y
, sfColor color);
void line_print(t_framebuffer *fb);
void draw_square(t_framebuffer *fb, int size, sfColor color, t_pos p);
void draw_line(t_framebuffer *fb, t_pos ori, t_pos des, sfColor color
, int size);
void erase_screen(t_framebuffer *fb, sfTexture *texture
, sfSprite *sprite, sfRenderWindow *window);
sfColor get_colorfade_of(sfColor changing);
sfColor color_incr(sfColor changing);
void disp_refresh(sfRenderWindow *window, t_framebuffer *fb
, sfTexture *texture, sfSprite *sprite);
void logar_color_disp(sfRenderWindow *window, t_framebuffer *fb
, sfTexture *texture, sfSprite *sprite);
void init_coord(t_pos *des, t_pos *ori);
void screen1(void);
void screen2(void);
void screen3(void);
void disp_usage(void);
void disp_list(void);
int my_getnbr(char const *str);
void do_things1(sfRenderWindow *window, t_framebuffer *fb
, sfTexture *texture, sfSprite *sprite);
t_framebuffer *do_things2(sfRenderWindow *window, t_framebuffer *fb
, sfTexture *texture, sfSprite *sprite);
void draw_circle(t_framebuffer *fb, t_pos ori, sfColor color, int size);
void ball_fade(t_framebuffer *fb
, sfTexture *texture, sfSprite *sprite, sfRenderWindow *window);
void draw_empty_circle(t_framebuffer *fb, t_pos ori, sfColor color, int size);
void get_fade_ball(t_framebuffer *fb, t_pos ori, sfColor color, accel acc);

#endif /* !MY_H_ */