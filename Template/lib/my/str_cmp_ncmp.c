/*
** EPITECH PROJECT, 2020
** Model
** File description:
** str_cmp_ncmp
*/

// return 1 if one equal two

int str_cmp(char *one, char *two)
{
    if ((!one) || (!two))
        return (84);
    for (int i = 0; (one[i] == two[i]); i++) {
        if (one[i] == '\0')
            return (1);
    }
    return (0);
}

// return 1 if one equal two, n → nbr of char to check

int str_ncmp(char *one, char *two, int n)
{
    n--;
    if ((!one) || (!two))
        return (84);
    for (int i = 0; (one[i] == two[i]); i++) {
        if ((one[i] == '\0') || (i == n))
            return (1);
    }
    return (0);
}