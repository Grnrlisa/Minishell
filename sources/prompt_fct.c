/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** prompt
*/

#include "../include/my.h"
#include "../include/minishell.h"

void my_promp(void)
{
    char cwd[4096];
    getcwd(cwd, 4096);
    my_putstr("\e[0;35m << \e[0m");
    my_putstr("\e[1;31m");
    my_putstr(cwd);
    my_putstr("\e[0m");
    my_putstr("\e[0;35m >> \e[0m");
}

void test_sig(int i)
{
    if (i == 2) {
        my_putstr("\n");
        my_promp();
    }
}

int check_spaces(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\n'; i++) {
        if (str[i] != ' ' && str[i] != '\t')
            count++;
    }
    if (count == 0)
        return (1);
    return (0);
}

int gest_void_in_cmd(char *buffer)
{
    if (buffer[0] == '\n') {
        my_promp();
        return (1);
    }
    if (check_spaces(buffer) == 1) {
        my_promp();
        return (1);
    }
    return (0);
}
