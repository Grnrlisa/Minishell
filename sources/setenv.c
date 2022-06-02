/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** fct for cmd
*/

#include "../include/my.h"
#include "../include/minishell.h"

int check_setenv(struct_mnshl *mnshl, char **arg)
{
    for (int i = 0; i != my_strlen(arg[1]); i++) {
        if (isa(arg[1][i]) == 0 && isnum(arg[1][i]) == 0) {
            my_putstr( "setenv: Variable name must contain alphanumeric "
            "characters.\n");
            return (1);
        } else
            return (1);
    }
    return (0);
}

int print_env(char **env)
{
    for (int i = 0; env[i]; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
    return (1);
}

int my_setenv(char *buffer, char **arg, char **env, struct_mnshl *mnshl)
{
    if (compare_strings("setenv", arg[0]) == 0) {
        if (arg[1] != NULL) {
            if (check_setenv(mnshl, arg) == 1)
                return (1);
        } else
            return (print_env(env));
    }
    return (0);
}
