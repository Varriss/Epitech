/*
** EPITECH PROJECT, 2020
** STRINGS
** File description:
** Strings header
*/

#ifndef STRINGS_H
#define STRINGS_H

//////////////////////// VAR ////////////////////////

static char const HELP[500] = "Jam escape game created with CSFML\n" \
    ".USAGE\n" \
    "    ./jam [OPTION]\n" \
    "\n" \
    "OPTIONS\n" \
    "    -h                print the usage and quit\n" \
    "\n" \
    "USER INTERACTIONS\n" \
    "    Z_KEY / UP_ARROW_KEY       move up\n" \
    "    Q_KEY / LEFT_ARROW_KEY     move to the left\n" \
    "    S_KEY / DOWN_ARROW_KEY     move down\n" \
    "    D_KEY / RIGHT_ARROW_KEY    move to the right\n" \
    "    M_KEY                      mute /unmute game\n" \
    "    ESC_KEY                    pause / back\n";

static char const MISS_DISPLAY_ENV[53] = "./jam : can't run " \
    "(miss display environment)\n";

#endif