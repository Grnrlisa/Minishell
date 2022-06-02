/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** Task02 CPool Day06
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
