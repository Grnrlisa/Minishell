/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** main fct / env gen
*/

#include "../include/my.h"
#include "../include/minishell.h"

static char *stock_filled(int i, char *stock, char **old_env)
{
    int j = 0;
    int bis = 0;

    for (; old_env[i][j] != '/'; j++);
    for (; old_env[i][j] != '\0'; j++, bis++)
        stock[bis] = old_env[i][j];
    stock[bis] = '\0';
    return (stock);
}

char **gen_env(char **old_env)
{
    char **new_env = NULL;
    char *stock = NULL;

    for (int i = 0; old_env[i] != NULL; i++) {
        if (old_env[i][0] == 'P' && old_env[i][1] == 'A') {
            stock = malloc(sizeof(char) * my_strlen((old_env[i]) + 1));
            stock = stock_filled(i, stock, old_env);
            new_env = my_str_to_word_array(':', stock);
        }
    }
    return (new_env);
}
