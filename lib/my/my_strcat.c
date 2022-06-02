/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** Task02 CPool Day07
*/

#include "my.h"

char *my_strcat(char *dest, char *arg)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(arg) + 1));

    for (; dest[i] != '\0'; i++)
        str[i] = dest[i];
    for (; arg[j] != '\0'; j++, i++)
        str[i] = arg[j];
    str[i] = '\0';
    return (str);
}
