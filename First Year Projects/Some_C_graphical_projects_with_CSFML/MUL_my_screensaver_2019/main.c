/*
** EPITECH PROJECT, 2019
** MUL
** File description:
** main
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stddef.h>
#include "include/my.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

static func_tab d_f_t_[] = {
    {0, &disp_usage},
    {1, &screen1},
    {2, &screen2},
    {3, &screen3}
};

void disp_list(void)
{
    write(1, "1:  Disp a logarithmic and psychedelic hallway then erase it."
    , 61);
    write(1, "\n", 1);
    write(1, "2:  Disp a growing ball that spawn randomly and bounce.", 55);
    write(1, "\n", 1);
    write(1, 
    "3:  Disp a bloody(#JustRed) and chaotic(#WithDifferentDirections) rain."
    , 71);
    write(1, " Plus an EMPTY circle.", 22);
    write(1, "\n", 1);
}

void disp_usage(void)
{
    write(1, "\nUSAGE\n", 7);
    write(1, "  ./my_screensaver [OPTIONS] animation_idanimation_id\n", 54);
    write(1, "  ID of the animation to process (between 1 and 20).\n\n", 54);
    write(1, "OPTIONS\n", 8);
    write(1, "  -d                ", 20);
    write(1, "print the description of all the animations and quit.\n", 54);
    write(1, "  -h                print the usage and quit.\n\n", 47);
    write(1, "USER INTERACTIONS\n", 18);
    write(1, "  ANY_KEYBOARD_PRESSED        quit the prog.\n", 45);
}

int main(int ac, char **argv)
{
    char *a = NULL;

    if (ac != 2) {
        disp_usage();
        return (84);
    }
    a = argv[1];
    if ((a[0] == '-' && (a[1] == 'h')) ^ (a[0] == '-' && (a[1] == 'd'))) {
        if (a[0] == '-' && (a[1] == 'h'))
            disp_usage();
        if (a[0] == '-' && (a[1] == 'd'))
            disp_list();
    } else if ((my_getnbr(a) <= 20) && (my_getnbr(a) > 0))
        d_f_t_[my_getnbr(a)].foo();
    else {
        disp_usage();
        return (84);
    }
    return (0);
}