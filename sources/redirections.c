/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** fct for cmd
*/

#include "../include/my.h"
#include "../include/minishell.h"

static int write_on_file(char *fname, char *str)
{
    int fd = open(fname, O_WRONLY | O_TRUNC);

    if (fd == -1)
        return (84);
    write(fd, str, my_strlen(str));
    fd = close(fd);
    return (0);
}

int redirect(struct_mnshl *mnshl, char *file, int i)
{
    int fd = 0;

    fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 00664);
    if (fd == -1) {
        my_putstr(strerror(errno));
        return (1);
    }
    if (!file)
        return (1);
    if (write_on_file(mnshl->arg[i + 1], "bla") == 84)
        return (84);
    return (1);
}

int check_redirections(struct_mnshl *mnshl)
{
    int i = 0;

    for (; mnshl->arg[i]; i++);
    for (i -= 1; i >= 0; i--) {
        if (compare_strings(mnshl->arg[i], ">") == 0)
            return (redirect(mnshl, mnshl->arg[i + 1], i));
        if (compare_strings(mnshl->arg[i], "<") == 0)
            return (redirect(mnshl, mnshl->arg[i + 1], i));
    }
    return (0);
}
