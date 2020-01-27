##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## General makefile for compilation
##

################
# Source Files #
################

SRC	=	...

OSRC	=	$(SRC:.c=.o)

SRC_TESTS	=	tests/tests.c	\
	tests/tests_errors_handling.c

OSRC_T	=	$(SRC_TESTS:.c=.o)

#########
# Mains #
#########

SRC_MAIN	=	main.c

OSRC_M	=	$(SRC_MAIN:.c=.o)

################
# Binary names #
################

NAME	=	...

NAME_TESTS	=	tests_run

#########
# Tools #
#########

RUN_TESTS	=	./$(NAME_TESTS)

COVERAGE	=	gcovr --exclude tests/

COVERAGE_B	=	gcovr --exclude tests/ -b

MAKE_LIB	=	make re -C lib/my/

#########
# Flags #
#########

CFLAGS += -W -Wall -Wextra -pedantic

TFLAGS += --coverage -lcriterion -g3

LFLAGS += -I./include/ -L./lib/my -lmy

############
# Commands #
############

all:
	$(MAKE_LIB)
	gcc -o $(NAME) $(OSRC) $(OSRC_M) $(CFLAGS) $(LFLAGS)

tests_run:	clean
	gcc -o $(NAME_TESTS) $(OSRC_T) $(OSRC) $(TFLAGS) $(LFLAGS) $(CFLAGS)
	$(RUN_TESTS)

coverage:
	$(COVERAGE)
	$(COVERAGE_B)

clean:
	find -type f -name "*~" -delete
	find -type f -name "#*#" -delete
	find -type f -name "*.o" -delete

fclean: clean
	rm -f $(NAME) $(NAME_TESTS)
	find -type f -name "a.out" -delete
	find -type f -name "*.a" -delete
	find -type f -name "*.gcno" -delete
	find -type f -name "*.gcda" -delete
	find -type f -name ".vgcore.*" -delete
	rm -f ./include/my.h

re:	fclean, all

.PHONY: all, tests_run, coverage, clean, fclean, re