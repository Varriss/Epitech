##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## General makefile for compilation
##

################
# Source Files #
################

CC	=	gcc

SRC	=	parsing/get_next_line.c	\
		my_defender.c	\
		init_scenes.c	\
		find_object.c	\
		events/analyse_events.c	\
		events/event_functions.c	\
		rendering/render_scene.c	\
		game_objects/ground_tile/ground_tile.c	\
		game_objects/tilemap/tile_map_callbacks.c	\
		game_objects/tilemap/tile_map.c	\
		init_menu/menu_scene.c	\
		init_menu/menu_callbacks.c	\
		init_menu/menu_scene_buttons.c	\
		init_menu/button_handle.c	\
		game_objects/hud/hud.c	\
		game_objects/hud/scores_handling.c	\
		game_objects/hud/buttons.c	\
		game_objects/towers/tower_init.c	\
		game_objects/enemy/enemy.c	\
		game_objects/enemy/enemy_callbacks.c	\
		game_objects/enemy/enemy_pathfinding.c	\
		game_objects/enemy/check_enemy_state.c	\
		game_objects/level/level.c	\
		game_objects/level/level_callbacks.c	\
		game_objects/towers/real_tower_init.c	\
		game_objects/towers/tower_init_tool.c	\
		init_menu/pause_scene/button_game_menu.c	\
		defeat_scene.c	\
		manage_waves.c

OSRC	=	$(SRC:.c=.o)

SRC_TESTS	=	tests/tests.c	\
				tests/tests_errors_handling.c

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

NAME	=	my_defender

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
LFLAGS = $(addprefix -L. , $(TMPFLAGS)) -l csfml-graphics -l csfml-system -lm

############
# Commands #
############

all: $(OSRC) $(OSRC_M) lib
	$(CC) $(IFLAGS) -o $(NAME) $(OSRC) $(OSRC_M) $(LFLAGS)

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
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

tests_run:	clean $(OSRC) $(OSRC_T) lib
	$(CC) -o $(NAME_TESTS) $(OSRC_T) $(OSRC) $(IFLAGS) $(TFLAGS) $(LFLAGS)
	$(RUN_TESTS)

debug: fclean lib
	$(CC) $(IFLAGS) -o $(NAME) $(SRC) $(SRC_MAIN)  $(LFLAGS) -g3

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