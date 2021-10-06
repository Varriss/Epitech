/*
** EPITECH PROJECT, 2021
** tmp_star
** File description:
** star
*/

void my_putchar(char c);
void make_default_star(void);

void putchar_c_x_times(char c, unsigned int x)
{
    for (unsigned int i = 0; i < x; i++)
        my_putchar(c);
}

void make_reversehat(unsigned int size)
{
    unsigned int offset = size * 2;
    unsigned int space = (size - 2) * 2 + 1;

    for (unsigned int i = 0; i <= size - 2; i++, space -= 2) {
        putchar_c_x_times(' ', offset + i);
        my_putchar('*');
        putchar_c_x_times(' ', space);
        my_putchar('*');
        my_putchar('\n');
    }
    putchar_c_x_times(' ', offset + size - 1);
    my_putchar('*');
    my_putchar('\n');
}

void make_body(unsigned int size, unsigned int spaces)
{
    unsigned int side = size * 2 + 1;
    unsigned int mid = (side * 2) + spaces - 4;

    putchar_c_x_times('*', side);
    putchar_c_x_times(' ', spaces);
    putchar_c_x_times('*', side);
    my_putchar('\n');
    for (unsigned int i = 1; i < size * 2; i++, mid -= (i <= size ? 2 : -2)) {
        putchar_c_x_times(' ', i <= size ? i : size + (size - i));
        my_putchar('*');
        putchar_c_x_times(' ', mid);
        my_putchar('*');
        my_putchar('\n');
    }
    putchar_c_x_times('*', side);
    putchar_c_x_times(' ', spaces);
    putchar_c_x_times('*', side);
    my_putchar('\n');
    make_reversehat(size);
}

void make_hat(unsigned int size)
{
    unsigned int offset = size * 2;

    putchar_c_x_times(' ', offset + size - 1);
    my_putchar('*');
    my_putchar('\n');
    for (int i = size - 2, space = 1; i >= 0; i--, space += 2) {
        putchar_c_x_times(' ', offset + i);
        my_putchar('*');
        putchar_c_x_times(' ', space);
        my_putchar('*');
        my_putchar('\n');
    }
    make_body(size ,(1 + (2 * (size - 2))));
}

void star(unsigned int size)
{
    if (size > 1)
        make_hat(size);
    else if (size == 1)
        make_default_star();
}