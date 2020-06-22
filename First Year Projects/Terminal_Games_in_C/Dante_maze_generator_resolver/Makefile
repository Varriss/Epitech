##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## General makefile for compilation
##

############
# Commands #
############

all:
	make -C ./generator/
	make -C ./solver/

tests_run:
	make tests_run -C ./generator/
	make tests_run -C ./solver/

debug:
	make debug -C ./generator/
	make debug -C ./solver/

coverage:
	make coverage -C ./generator/
	make coverage -C ./solver/

clean:
	make clean -C ./generator/
	make clean -C ./solver/

fclean:
	make fclean -C ./generator/
	make fclean -C ./solver/

re:	fclean all

.PHONY: all, tests_run, coverage, clean, fclean, re, debug