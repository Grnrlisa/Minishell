/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** str man
*/

#include "../include/my.h"
#include "../include/minishell.h"

int compare_strings(char const *str1, char const *str2)
{
    int i = 0;

    while ((str1[i] != '\0') && (str2[i] != '\0')) {
        if (str1[i] < str2[i])
            return (-1);
        if (str1[i] > str2[i])
            return (1);
        i++;
    }
    if ((str1[i] == '\0') && (str2[i] == '\0'))
        return (0);
    else if (str1[i] == '\0')
        return (-1);
    else
        return (1);
}

int isa(char c)
{
    return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z');
}

int isnum(char c)
{
    return (c >= '0' && c <= '9');
}
