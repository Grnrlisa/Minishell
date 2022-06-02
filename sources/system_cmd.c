/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** fct for cmd
*/

#include "../include/my.h"
#include "../include/minishell.h"

char **recup_path(char **env)
{
    char **path_array;
    char *stock;
    int i = 0;
    int j = 0;

    while (env[i] != NULL) {
        stock = malloc(sizeof(char) * my_strlen((env[i]) + 1));
        for (; env[i][j] != '/'; j++);
        for (int bis = 0; env[i][j] != '\0'; j++, bis++)
            stock[bis] = env[i][j];
        path_array = my_str_to_word_array(':', stock);
        i++;
    }
    return (path_array);
}

static int no_such_file_or_directory(char **arg)
{
    if (compare_strings("cd", arg[0]) == 0) {
        if (chdir(arg[1]) == -1) {
            my_putstr(arg[1]);
            my_putstr(": No such file or directory.\n");
        }
        my_promp();
        return (1);
    }
    return (0);
}

char *get_from_env(struct_mnshl *mnshl, char *str)
{
    char *dest = NULL;
    int i = 0;

    if (!mnshl->new_env[i])
        return (NULL);
    dest = malloc(sizeof(char) * (my_strlen(mnshl->new_env[0]) + 1));
    dest = my_strcpy(dest, mnshl->new_env[0]);
    return (dest);
}

int my_cd(char *buffer, char **arg, char **env, struct_mnshl *mnshl)
{
    char **path;

    if (compare_strings("cd\n", buffer) == 0) {
        if (arg[1] == NULL || compare_strings(arg[1], "~") == 0) {
            if (chdir(get_from_env(mnshl, "home")) == -1) {
                my_putstr("cd: No HOME in env.\n");
                return (0);
            }
        } else if (arg[1] != NULL) {
            path = recup_path(env);
            chdir(path[0]);
            return (0);
        }
    }
    if (no_such_file_or_directory(arg) == 1)
        return (1);
    return (0);
}

int system_cmd(char *buffer, struct_mnshl *mnshl, char **env)
{
    int num = 0;

    if (compare_strings("exit", mnshl->arg[0]) == 0) {
        if (mnshl->arg[1] != NULL)
            num = my_getnbr(mnshl->arg[1]);
        my_putstr("exit\n");
        exit(num);
    }
    if (my_setenv(buffer, mnshl->arg, env, mnshl) == 1) {
        return (minishell_head(env, mnshl));
    }
    if (my_cd(buffer, mnshl->arg, env, mnshl) == 1)
        return (minishell_head(env, mnshl));
    if (check_redirections(mnshl) == 1)
        return (minishell_head(env, mnshl));
    return (0);
}
