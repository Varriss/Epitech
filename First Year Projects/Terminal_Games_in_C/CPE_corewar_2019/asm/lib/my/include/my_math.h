/*
** EPITECH PROJECT, 2019
** MY_MATH
** File description:
** My_math header
*/

#ifndef MY_MATH_H
#define MY_MATH_H

//////////////////////// VAR ////////////////////////

// const
static const float PI = 3.141592;

#define STR_INT_MAX "2147483647"
#define STR_INT_MIN "-2147483648"
#define STR_LLINT_MAX "9223372036854775807"
#define STR_LLINT_MIN "−9223372036854775808"

// macro
#define ABS(x) (((x) < 0) ? -(x) : (x))

///////////////////// PROTOTYPE /////////////////////

int my_get_nbr(char const *str);
long long int my_get_llint(char const *str);
char *int_to_str(int nb);

// trigo
int my_cos(int degrees);
int my_sin(int degrees);

// is_into
int int_is_into(int x, int a, int b);
int float_is_into(float x, float a, float b);

void swap_int(int *a, int *b);

#endif