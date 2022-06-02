/*
** EPITECH PROJECT, 2021
** my_strlowcase
** File description:
** Task08 CPool Day06
*/

#include "my.h"

char *my_strlowcase (char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        i++;
    }
    return (str);
}
