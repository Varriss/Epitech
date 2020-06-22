##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## General makefile for compilation
##

################
# Source Files #
################

SRC	=	tetris_check.c

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

NAME	=	tetris

NAME_TESTS	=	tests_run

#########
# Tools #
#########

RUN_TESTS	=	./$(NAME_TESTS)

COVERAGE	=	gcovr --exclude tests/

COVERAGE_B	=	gcovr --exclude tests/ -b

#########
# Flags #
#########

CFLAGS += -W -Wall -Wextra -pedantic

TFLAGS += --coverage -lcriterion -g3

LFLAGS += -I./include/ -L./lib/my/ -lmy

############
# Commands #
############

all: $(OSRC) $(OSRC_M)
ifeq ($(MAKECMDGOALS), re)
	make re -C lib/my/
else
	make -C lib/my/
endif
	gcc -o $(NAME) $(OSRC) $(OSRC_M) $(LFLAGS)

tests_run:	clean $(OSRC) $(OSRC_T)
	make re -C lib/my/
	gcc -o $(NAME_TESTS) $(OSRC_T) $(OSRC) $(TFLAGS) $(LFLAGS)
	$(RUN_TESTS)

debug: fclean
	make re -C lib/my/
	gcc -o $(NAME) $(OSRC) $(OSRC_M) $(LFLAGS) -g3

coverage:
	$(COVERAGE)
	$(COVERAGE_B)

clean:
	find -type f -name "*~" -delete
	find -type f -name "#*#" -delete
	find -type f -name "*.o" -delete

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_TESTS)
	find -type f -name "a.out" -delete
	find -type f -name "*.a" -delete
	find -type f -name "*.gcno" -delete
	find -type f -name "*.gcda" -delete
	find -type f -name "vgcore.*" -delete

re:	fclean all

.PHONY: all, tests_run, coverage, clean, fclean, re, debug