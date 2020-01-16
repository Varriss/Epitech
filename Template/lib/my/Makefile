##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## Library compil
##

SRC 	=	my_printf.c	\
	my_printf_box_one.c	\
	my_printf_box_two.c	\
	my_chain_funcs.c	\
	my_chain_funcs_two.c\
	my_compute_power_rec.c	\
	my_getnbr.c	\
	my_initialize_str.c	\
	my_show_word_array.c\
	my_strcat.c	\
	my_strcpy.c	\
	my_strdup.c	\
	my_str_isnum.c	\
	my_strlen.c	\
	my_strncat.c\
	my_strncpy.c\
	my_str_to_word_array.c

HEADERS	=	my.h

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc ./$(NAME) $(OBJ)
	cp ./$(NAME) ../
	cp ./$(HEADERS) ../../include/

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f ../../include/my.h

re:	fclean all

.PHONY:	all, clean, fclean, re