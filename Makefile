##
## EPITECH PROJECT, 2021
## B-PSU-101-REN-1-1-minishell1
## File description:
## Minishell 1 makefile
##

## Sources of the prog

SRC	=	sources/main_ishell.c 		\
		sources/system_cmd.c		\
		sources/prompt_fct.c 		\
		sources/recup_arg.c 		\
		sources/str_utils.c 		\
		sources/excve.c				\
		sources/gen_env.c 			\
		sources/setenv.c 			\
		sources/redirections.c
		
OBJ = $(SRC:.c=.o)

NAME =	mysh

LIB = -L lib/ -lmy

INCLUDE = -I include/

## Compilation flags (auto pick-up)
CFLAGS = -Wall -W $(INCLUDE)

## Make commande
all:	mylib $(OBJ) clean
	gcc -g -o $(NAME) $(SRC) $(INCLUDE) $(LIB)

mylib:
	make -C lib/my/

## clean commande : rm files object
clean:
	rm -f $(OBJ)
	make clean -C lib/my/


## fclean commande : rm binary
fclean:
	rm -f $(NAME)
	make clean
	make fclean -C lib/my/

## re commande : remake after cleaning
re:
	make fclean
	make all

.PHONY: clean, fclean, re, all
