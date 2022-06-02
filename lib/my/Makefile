##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Task 01 CPool Day10
##

SRC	 =	my_putchar.c \
		my_putstr.c \
		my_isneg.c \
		my_swap.c \
		my_strlen.c \
		my_putstr.c \
		my_compute_power_rec.c \
		my_getnbr.c \
		my_put_nbr.c \
		my_strcpy.c \
		my_strncmp.c \
		my_strncpy.c \
		my_str_to_word_array.c \
		my_strupcase.c \
		my_strlowcase.c \
		my_revstr.c \
		my_strcat.c \
		my_conv_bases.c \
		my_unsigned.c \
		my_itoa.c \
		my_atoi.c \

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(NAME) clean

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f ../../include/my.h

re: fclean all
