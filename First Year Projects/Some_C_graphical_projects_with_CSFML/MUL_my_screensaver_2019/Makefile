##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## General makefile for compilation
##

################
# Source Files #
################

SRC			=	gen.c	\
				basic_sheets.c	\
				basic_sheets2.c	\
				basic_sheets3.c	\
				get_nbr.c	\
				screen1.c	\
				screen2.c	\
				screen3.c

##################
# Main functions #
##################

SRC_MAIN	=	main.c

################
# Binary names #
################

NAME		=		my_screensaver

##################
# Other commands #
##################

CFLAGS += -W -Wall -Wextra -pedantic

all:
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(SRC_MAIN) -I./include -l csfml-graphics -lm -g3

clean:
		find -type f -name "*~" -delete -or -name "#*#" -delete
		find -type f -name "*.gcno" -delete -or -name "*.gcda" -delete
		find -type f -name "*.o" -delete
		find -type f -name "vgcore.*" -delete

fclean: clean
		rm -f $(NAME) $(NAME_TESTS)
		find -type f -name "*.a" -delete
		find -type f -name "a.out" -delete

re: 	fclean all

.PHONY: all, clean, fclean, re