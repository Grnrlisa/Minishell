/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** main fct / main
*/

#include "../include/my.h"
#include "../include/minishell.h"

static void my_exec_annex(struct_mnshl *mnshl, char **env, char *str)
{
    if (mnshl->PID == 0)
        execve(str, mnshl->arg, env);
}

static int my_exec(char *new_env, char *str, char **env, struct_mnshl *mnshl)
{
    DIR *directory = opendir(new_env);
    struct dirent *read = NULL;
    int checker = 0;

    if (directory == NULL)
        return (84);
    while ((read = readdir(directory)) != NULL) {
        if (compare_strings(read->d_name, mnshl->arg[0]) == 0) {
            checker++;
            str = my_strcat(str, mnshl->arg[0]);
            mnshl->PID = fork();
            my_exec_annex(mnshl, env, str);
            wait(NULL);
        }
    }
    return (checker);
}

int exec_prog(char **env, struct_mnshl *mnshl)
{
    int checker = 0;

    for (int i = 0; mnshl->new_env[i]; i++) {
        char *str = my_strcat(mnshl->new_env[i], "/");
        if (access(mnshl->new_env[i], F_OK) == 0 &&
        access(mnshl->new_env[i], R_OK) == 0 &&
        access(mnshl->new_env[i], X_OK) == 0)
            checker = my_exec(mnshl->new_env[i], str, env, mnshl);
        if (checker != 0)
            return (0);
    }
    my_putstr(mnshl->arg[0]);
    my_putstr(": Command not found.\n");
    return (0);
}
