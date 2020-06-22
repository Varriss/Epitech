/*
** EPITECH PROJECT, 2019
** MY_COMPUTE_FACTORIAL_IT
** File description:
** Return the factorial of the number given as a parameter
*/

int my_compute_factorial_it(int nb)
{
    int result = 1;

    if (nb < 0)
        return (0);
    if (nb == 0)
        return (1);
    for (int i = nb; i > 1; i--) {
        result *= i;
        if (result < 0)
            return 0;
    }
    return (result);
}