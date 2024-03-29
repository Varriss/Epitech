##
## EPITECH PROJECT, 2021
## General makefile
## File description:
## Such a good Makefile
##

CC	=	g++ #or gcc

ECHO	=	echo

################
#    Colors    #
################

DEFAULT	=	"\e[39m"

RED	=	"\e[31m"

GREEN	=	"\e[32m"

YELLOW	=	"\e[33m"

################
# Source Files #
################

# Files of $NAME0 executable #
SRC0	=	.cpp	\
			main0.cpp

OSRC0	=	$(SRC0:.cpp=.o)# .c or.cpp

# Files of $NAME1 executable #
SRC1	=	

OSRC1	=	$(SRC1:.cpp=.o)

################
# Tests  Files #
################

# SRC tested by tests files #
SRC = $(SRC0) $(SRC1)

OSRC = $(SRC:.c=.o)

SRC_TESTS	=	tests/tests.c

OSRC_T	=	$(SRC_TESTS:.c=.o)

############
# Lib Dirs #
############

LIB = #my, lists, etc that belong to personnal libraries src directories

################
# Binary names #
################

NAME0	=	t0

NAME1	=	t1

NAME_TESTS	=	tests_run

# For Fclean commands #
NAMES	=	$(NAME0)	\
			$(NAME1)	\
			$(NAME_TESTS)

#########
# Tools #
#########

RUN_TESTS	=	./$(NAME_TESTS)

COVERAGE	=	gcovr --exclude tests/

COVERAGE_B	=	gcovr --exclude tests/ -b

#########
# Flags #
#########

CFLAGS += -W -Wall -Wextra -pedantic -Werror

TFLAGS += --coverage -lcriterion -g3

IFLAGS += -I./include

IMPORT_LIB	=	# -lm or other imported lib

TMPFLAGS += $(addsuffix .a, $(addprefix lib/lib, $(LIB)))
LFLAGS = $(addprefix -L. , $(TMPFLAGS)) $(IMPORT_LIB)

############
# Commands #
############

all: run0 run1

# General compile command #
run%:	lib
	@$(MAKE) -s $(OSRC$*)
	@$(CC) $(IFLAGS) -o $(NAME$*) $(OSRC$*) $(LFLAGS) &&	\
	$(ECHO) $(GREEN) "Compilation Done [" $(NAME$*) "]" $(DEFAULT) ||	\
	$(ECHO) $(RED) "Compilation Fail [" $(NAME$*) "]" $(DEFAULT)

# Lib{Dir} Makefile Calling #
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

# Files precompilation #
%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@ &&	\
	$(ECHO) $(GREEN) "OK " $(DEFAULT) $(basename $(@F)) "-------> "	\
	$(GREEN) $@ $(DEFAULT) || $(ECHO) $(RED) "ERROR " $< $(DEFAULT)

%.o: %.cpp
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@ &&	\
	$(ECHO) $(GREEN) "OK " $(DEFAULT) $(basename $(@F)) "-------> "	\
	$(GREEN) $@ $(DEFAULT) || $(ECHO) $(RED) "ERROR " $< $(DEFAULT)

# Compile ONE src without .o#
debug%: fclean lib
	@$(CC) $(IFLAGS) -o $(NAME$*) $(SRC$*) $(LFLAGS) -g3 && \
	$(ECHO) $(GREEN) "Debug Compilation Done" $(DEFAULT) ||	\
	$(ECHO) $(RED) "Debug Compilation Fail" $(DEFAULT)

# Unitary tests compilation #
tests_run: clean $(OSRC) $(OSRC_T) lib
	$(CC) -o $(NAME_TESTS) $(OSRC_T) $(OSRC) $(IFLAGS) $(TFLAGS) $(LFLAGS)
	$(RUN_TESTS)

# Tests coverage display commands #
coverage:
	$(COVERAGE)
	$(COVERAGE_B)

# MR.Clean commands #
clean:
	@find -type f -name "*~" -delete &&	\
	find -type f -name "#*#" -delete &&	\
	find -type f -name "*.o" -delete&&	\
	$(ECHO) $(YELLOW) "Clean Done" $(DEFAULT)

fclean: clean
	@rm -rf $(NAMES) &&	\
	find -type f -name "a.out" -delete &&	\
	find -type f -name "*.a" -delete &&	\
	find -type f -name "*.gcno" -delete &&	\
	find -type f -name "*.gcda" -delete &&	\
	find -type f -name "vgcore.*" -delete &&	\
	$(ECHO) $(YELLOW) "Force Clean Done" $(DEFAULT)

# The ONE #
re:	fclean all

.PHONY: all, tests_run, coverage, clean, fclean, re, debug, lib
