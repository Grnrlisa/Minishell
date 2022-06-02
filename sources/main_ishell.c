/*
** EPITECH PROJECT, 2021
** minishell 1
** File description:
** main_ishell
*/

#include "../include/my.h"
#include "../include/minishell.h"

int minishell_head(char **env, struct_mnshl *mnshl)
{
    mnshl->buffer = NULL;
    size_t b_size = 0;
    char *buffer_bis = NULL;

    while (1) {
        if (getline(&mnshl->buffer, &b_size, stdin) == -1)
            exit(84);
        if (gest_void_in_cmd(mnshl->buffer) == 1)
            minishell_head(env, mnshl);
        buffer_bis = recup_arg(mnshl, buffer_bis);
        mnshl->arg = my_str_to_word_array(32, buffer_bis);
        if (system_cmd(buffer_bis, mnshl, env) == 0)
            exec_prog(env, mnshl);
        my_promp();
    }
    return (0);
}

static int start_mnshl(struct_mnshl *mnshl, char **env)
{
    my_promp();
    signal(SIGINT, test_sig);
    mnshl->new_env = gen_env(env);

    if (mnshl->new_env == NULL)
        return (84);
    return (minishell_head(env, mnshl));
}

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    struct_mnshl mnshl;

    return (start_mnshl(&mnshl, env));
}
