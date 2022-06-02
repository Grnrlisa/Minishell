/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** recup arg
*/

#include "../include/my.h"
#include "../include/minishell.h"

char *recup_arg(struct_mnshl *mnshl, char *str)
{
    int i = 0;
    int j = 0;

    if (mnshl->buffer[0] == ' ' || mnshl->buffer[0] == '\t') {
        for (; mnshl->buffer[i] == ' ' || mnshl->buffer[i] == '\t'; i++)
            str = malloc(sizeof(char) * (my_strlen(mnshl->buffer) - i + 1));
        for (; mnshl->buffer[i] != '\0'; i++, j++)
            str[j] = mnshl->buffer[i];
        str[j] = '\0';
    } else {
        str = malloc(sizeof(char) * (my_strlen(mnshl->buffer) + 1));
        for (; mnshl->buffer[i] != '\0'; i++)
            str[i] = mnshl->buffer[i];
        str[i] = '\0';
    }
    return (str);
}
