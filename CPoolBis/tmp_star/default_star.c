/*
** EPITECH PROJECT, 2021
** tmp_star
** File description:
** default_star
*/

void my_putchar(char c);
void putchar_c_x_times(char c, unsigned int x);

void make_default_sides(void)
{
    putchar_c_x_times('*', 3);
    my_putchar(' ');
    putchar_c_x_times('*', 3);
    my_putchar('\n');
}

void make_default_star(void)
{
    putchar_c_x_times(' ', 3);
    my_putchar('*');
    my_putchar('\n');
    make_default_sides();
    my_putchar(' ');
    my_putchar('*');
    putchar_c_x_times(' ', 3);
    my_putchar('*');
    my_putchar('\n');
    make_default_sides();
    putchar_c_x_times(' ', 3);
    my_putchar('*');
    my_putchar('\n');
}