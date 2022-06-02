/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** Task03 CPool Day06
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int count = 0;
    int c = 0;

    while (str[count] != '\0') {
        count++;
    }
    count--;
    while (i < count) {
        c = str[i];
        str[i] = str[count];
        str[count] = c;
        i++;
        count--;
    }
    return (str);
}
