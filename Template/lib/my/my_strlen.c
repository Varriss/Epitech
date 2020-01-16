/*
** EPITECH PROJECT, 2019
** MY_STRLEN
** File description:
** returns the length of an array, does not count the '\0'
*/

int my_strlen(char const *src)
{
    int length = 0;

    for (int i = 0; src[i] != '\0'; i++)
        length++;
    return (length);
}