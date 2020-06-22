/*
** EPITECH PROJECT, 2020
** Model main
** File description:
** main
*/

#include "my_defender.h"

static int display_usage(void)
{
    my_putstr("Mange tes morts:\n\t.\n");
    return (SUCCESS_CODE);
}

int main(int argc, char *const *argv)
{
    if ((argc > 2) || ((argc == 2) && (!my_streq(argv[1], "-h"))))
        return (my_write(FAILURE_CODE, "Invalid arguments, see -h\n", 2));
    else if ((argc == 2) && (my_streq(argv[1], "-h")))
        return (display_usage());
    return (my_defender());
}