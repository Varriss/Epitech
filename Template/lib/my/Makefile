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
	my_str_to_word_array.c	\
	get_next_line.c	\
	get_next_line_tools.c	\
	my_prompt.c	\
	my_free.c	\
	str_cmp_ncmp.c	\
	str_to_tab.c

HEADERS	=	my.h

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc ./$(NAME) $(OBJ)

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all, clean, fclean, re