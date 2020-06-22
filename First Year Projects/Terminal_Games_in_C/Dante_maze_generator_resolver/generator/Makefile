##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## General makefile for compilation
##

################
# Source Files #
################

CC = gcc

LIB	=	lists my

SRC	=	perfect_maze.c	\
		handling_tools/char_dbl_stars_handle.c	\
		handling_tools/node_choose.c	\
		handling_tools/special_prim_tools.c

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

NAME	=	generator

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

IFLAGS += -I./include

TMPFLAGS += $(addsuffix .a, $(addprefix ../solver/lib/lib, $(LIB)))
LFLAGS = $(addprefix -L. , $(TMPFLAGS))

############
# Commands #
############

all: $(OSRC) $(OSRC_M) lib
	$(CC) -o $(NAME) $(OSRC) $(OSRC_M) $(LFLAGS)

lib:
ifeq ($(MAKECMDGOALS), re)
	@for i in $(LIB); do \
		(cd ../solver/lib/$$i/ && make re) ; \
		done;
else
	@for i in $(LIB); do \
		(cd ../solver/lib/$$i/ && make); \
		done;
endif

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

tests_run:	clean $(OSRC) $(OSRC_T) lib
	$(CC) -o $(NAME_TESTS) $(OSRC_T) $(OSRC) $(TFLAGS) $(LFLAGS)
	$(RUN_TESTS)

debug: fclean lib
	$(CC) $(IFLAGS) -o $(NAME) $(SRC) $(SRC_MAIN) $(LFLAGS) -g3

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

.PHONY: all, tests_run, coverage, clean, fclean, re, debug, lib