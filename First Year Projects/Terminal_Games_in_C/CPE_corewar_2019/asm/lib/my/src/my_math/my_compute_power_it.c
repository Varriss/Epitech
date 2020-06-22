/*
** EPITECH PROJECT, 2019
** MY_COMPUTE_POWER_IT
** File description:
** Returns the first argument raised to the power of the second argument
*/

#include "my_math.h"

int my_compute_power_it(int nb, int p)
{
    int result = nb;

    if (nb == 0 && p > 0)
        return 0;
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    for (int i = 1; i < p; i++) {
        if (ABS(result) > 2147483647 / ABS(nb)) return (0);
        result *= nb;
    }
    return (result);
}