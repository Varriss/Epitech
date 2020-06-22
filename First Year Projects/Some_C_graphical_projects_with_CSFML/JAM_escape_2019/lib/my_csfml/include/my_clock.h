/*
** EPITECH PROJECT, 2019
** MY_CLOCK
** File description:
** My_clock header
*/

#ifndef MY_CLOCK_H_
#define MY_CLOCK_H_

//////////////////////// VAR ////////////////////////

// const

// def struct
typedef struct clock_s my_clock_t;

// struct
struct clock_s
{
    sfClock *clock;
    int is_paused;
    sfInt64 paused_at;
    sfInt64 to_add;
    sfInt64 speed_at;
    float speed;
    float pause_speed;
};

///////////////////// PROTOTYPE /////////////////////

// clock
my_clock_t *clock_create(void);
void *clock_destroy(my_clock_t *clock);

// get
sfInt64 clock_get_s(my_clock_t *clock);
sfInt64 clock_get_ms(my_clock_t *clock);
sfInt64 clock_get_mcs(my_clock_t *clock);

// pause
void clock_pause(my_clock_t *clock);
void clock_unpause(my_clock_t *clock);

// speed
void clock_set_speed(my_clock_t *clock, float speed);
float clock_get_speed(my_clock_t *clock);

//display
sfText *init_text(void);
#endif /* !MY_CLOCK_H_ */