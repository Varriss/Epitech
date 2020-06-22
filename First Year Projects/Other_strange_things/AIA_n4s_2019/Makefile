##
## EPITECH PROJECT, 2020
## AIA_n4s_2019
## File description:
## Makefile
##

################
# Source Files #
################

CC	=	gcc

##### COLORS #######

ECHO	=	echo -e

DEFAULT	=	"\e[39m"

RED	=	"\e[31m"

GREEN	=	"\e[32m"

YELLOW	=	"\e[33m"

####################

PARSER_ONE_FOLD	=	parsers/parser_one
PARSER_ONE_FILES	=	$(PARSER_ONE_FOLD)/parser_one.c

PARSER_TWO_FOLD	=	parsers/parser_two
PARSER_TWO_FILES	=	$(PARSER_TWO_FOLD)/parser_two.c

PARSER_THREE_FOLD	=	parsers/parser_three
PARSER_THREE_FILES	=	$(PARSER_THREE_FOLD)/parser_three.c

PARSER_FOUR_FOLD	=	parsers/parser_four
PARSER_FOUR_FILES	=	$(PARSER_FOUR_FOLD)/parser_four.c

PARSER_FOLD	=	parsers
PARSER_FILES	=	$(PARSER_ONE_FILES)	\
					$(PARSER_TWO_FILES)	\
					$(PARSER_THREE_FILES)	\
					$(PARSER_FOUR_FILES)	\
					$(PARSER_FOLD)/parser.c	\
					$(PARSER_FOLD)/destroy_response.c	\
					$(PARSER_FOLD)/get_next_line.c

SENDER_FOLD	=	sender
SENDER_FILES	=	$(SENDER_FOLD)/send.c	\
					$(SENDER_FOLD)/create_command.c


RECEIVER_FOLD	=	receiver
RECEIVER_FILES	=	$(RECEIVER_FOLD)/receive.c

SRC	=	$(PARSER_FILES)	\
		$(SENDER_FILES)	\
		$(RECEIVER_FILES)	\
		ai.c

OSRC	=	$(SRC:.c=.o)

SRC_TESTS	=	tests/test_parsers.c

OSRC_T	=	$(SRC_TESTS:.c=.o)

LIB = lists my

#########
# Mains #
#########

SRC_MAIN	=	main.c

OSRC_M	=	$(SRC_MAIN:.c=.o)

################
# Binary names #
################

NAME	=	ai

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

TMPFLAGS += $(addsuffix .a, $(addprefix lib/lib, $(LIB)))
LFLAGS = $(addprefix -L. , $(TMPFLAGS))

############
# Commands #
############

all: $(OSRC) $(OSRC_M) lib
	@$(CC) $(IFLAGS) -o $(NAME) $(OSRC) $(OSRC_M) $(LFLAGS) &&	\
	$(ECHO) $(GREEN) "Compilation Done" $(DEFAULT) ||	\
	$(ECHO) $(RED) "Compilation Fail" $(DEFAULT)

lib:
ifeq ($(MAKECMDGOALS), re)
	@for i in $(LIB); do \
		(cd ./lib/$$i/ && make re -s);\
		done;
else
	@for i in $(LIB); do \
		(cd ./lib/$$i/ && make -s); \
		done;
endif

%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@ &&	\
	$(ECHO) $(GREEN) "OK " $(DEFAULT) $(basename $(@F)) "-------> "	\
	$(GREEN) $@ $(DEFAULT) || $(ECHO) $(RED) "ERROR " $< $(DEFAULT)

tests_run:	clean $(OSRC) $(OSRC_T) lib
	$(CC) -o $(NAME_TESTS) $(OSRC_T) $(OSRC) $(IFLAGS) $(TFLAGS) $(LFLAGS)
	$(RUN_TESTS)

debug: fclean lib
	@$(CC) $(IFLAGS) -o $(NAME) $(SRC) $(SRC_MAIN)  $(LFLAGS) -g3 && \
	$(ECHO) $(GREEN) "Debug Compilation Done" $(DEFAULT) ||	\
	$(ECHO) $(RED) "Debug Compilation Fail" $(DEFAULT)

coverage:
	$(COVERAGE)
	$(COVERAGE_B)

clean:
	@find -type f -name "*~" -delete &&	\
	find -type f -name "#*#" -delete &&	\
	find -type f -name "*.o" -delete&&	\
	$(ECHO) $(YELLOW) "Clean Done" $(DEFAULT)

fclean: clean
	@rm -rf $(NAME) &&	\
	rm -rf $(NAME_TESTS) &&	\
	find -type f -name "a.out" -delete &&	\
	find -type f -name "*.a" -delete &&	\
	find -type f -name "*.gcno" -delete &&	\
	find -type f -name "*.gcda" -delete &&	\
	find -type f -name "vgcore.*" -delete &&	\
	$(ECHO) $(YELLOW) "Force Clean Done" $(DEFAULT)

re:	fclean all

.PHONY: all, tests_run, coverage, clean, fclean, re, debug, lib