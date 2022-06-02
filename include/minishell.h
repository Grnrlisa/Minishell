/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** minishell
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_

    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <signal.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <dirent.h>
    #include <string.h>
    #include <errno.h>

typedef struct bsminishell {
    char *program_name;
    int nb_arg;
    pid_t PID;
    char *status;
    char *buffer;
    char **new_env;
    char **arg;
    int fd;
    int end;
} struct_mnshl;

int minishell_head(char **env, struct_mnshl *mnshl);
int system_cmd(char *buffer, struct_mnshl *mnshl, char **env);
char **gen_env(char **old_env);
void my_promp(void);
void test_sig(int i);
int gest_void_in_cmd(char *buffer);
char *recup_arg(struct_mnshl *mnshl, char *str);
char *is_it_in_str(char *str, char const *to_find);
int compare_strings(char const *s1, char const *s2);
int exec_prog(char **env, struct_mnshl *mnshl);
char **recup_path(char **env);
int my_setenv(char *buffer, char **arg, char **env, struct_mnshl *mnshl);
int isnum(char c);
int isa(char c);
int check_redirections(struct_mnshl *mnshl);

#endif/* !MINISHELL_H_ */
