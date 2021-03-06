##
## EPITECH PROJECT, 2020
## MUL_my_rpg_2019
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

RENDER_SRCS	=	render/simple_render.c	\
				render/render_particles.c

DESTROY_SRCS	=	destroy/simple_destroy.c

EVENT_SRCS	=	events/analyse_event.c	\
				events/event_callbacks.c	\
				events/player_event_callbacks.c	\
				events/item_consumption.c

SHOP_FOLD	=	game_objects/shop_scene
SHOP_FILES	=	$(SHOP_FOLD)/shop_init.c

PARTICLES_FOLD	=	game_objects/particles
PARTICLES_FILES	=	$(PARTICLES_FOLD)/particles.c	\
					$(PARTICLES_FOLD)/heal_effect.c	\
					$(PARTICLES_FOLD)/update_for_explode_bounce.c

GAME_FOLD	=	game_objects/game_scene
GAME_FILES	=	$(GAME_FOLD)/game_scene_init.c	\
				$(GAME_FOLD)/init_map.c	\
				$(GAME_FOLD)/map_creation.c	\
				$(GAME_FOLD)/tile_map_prepare.c	\
				$(GAME_FOLD)/reload_map.c

FIGHT_FOLD	=	game_objects/fight_scene
FIGHT_FILES =	$(FIGHT_FOLD)/init_fight_scene.c	\
				$(FIGHT_FOLD)/life_handling.c	\
				$(FIGHT_FOLD)/init_player.c	\
				$(FIGHT_FOLD)/init_enemy.c	\
				$(FIGHT_FOLD)/game_over.c	\
				$(FIGHT_FOLD)/victory.c	\
				$(FIGHT_FOLD)/enemy_attack.c	\
				$(FIGHT_FOLD)/multiple_enemy.c

BOSS_FOLD =		game_objects/boss_scene
BOSS_FILES = 	$(BOSS_FOLD)/boss_attack.c	\
				$(BOSS_FOLD)/init_boss_scene.c	\
				$(BOSS_FOLD)/init_boss.c


GEN_FOLD	=	$(GAME_FOLD)/generator/
MAZE_FILES	=	$(GEN_FOLD)perfect_maze.c	\
				$(GEN_FOLD)handling_tools/char_dbl_stars_handle.c	\
				$(GEN_FOLD)handling_tools/node_choose.c	\
				$(GEN_FOLD)handling_tools/special_prim_tools.c

CLOCK_FILES	=	$(GAME_FOLD)/my_clock/clock_get.c	\
				$(GAME_FOLD)/my_clock/clock.c	\
				$(GAME_FOLD)/my_clock/clock_speed.c	\
				$(GAME_FOLD)/my_clock/clock_pause.c	\
				$(GAME_FOLD)/my_clock/clock_callbacks.c

MENU_FOLD	=	game_objects/menu_scene
MENU_FILES	=	$(MENU_FOLD)/menu_callbacks.c	\
				$(MENU_FOLD)/menu_scene_init.c

HOW_TO_FOLD	=	game_objects/how_to
HOW_TO_FILES=	$(HOW_TO_FOLD)/how_to.c	\
				$(HOW_TO_FOLD)/how_too.c

SOUND_FOLD	=	game_objects/music_and_sounds
SOUND_FILES	=	$(SOUND_FOLD)/music_utilities.c	\
				$(SOUND_FOLD)/sound_buffer_utilities.c	\
				$(SOUND_FOLD)/sound_utilities.c

PLAYER_FOLD	=	game_objects/game_scene/player
PLAYER_FILES	=	$(PLAYER_FOLD)/player_cursor.c	\
					$(PLAYER_FOLD)/player_cursor_callbacks.c	\
					$(PLAYER_FOLD)/tilemap_actions.c

INVENTORY_FOLD	=	game_objects/game_scene/inventory
INVENTORY_FILES	=	$(INVENTORY_FOLD)/inventory.c	\
					$(INVENTORY_FOLD)/inventory_callbacks.c	\
					$(INVENTORY_FOLD)/gold_counter.c	\
					$(INVENTORY_FOLD)/gold_counter_callbacks.c

ITEM_FOLD		=	game_objects/game_scene/items
ITEM_FILES		=	$(ITEM_FOLD)/potion/potion.c	\
					$(ITEM_FOLD)/potion/potion_callbacks.c	\
					$(ITEM_FOLD)/blade/blade.c	\
					$(ITEM_FOLD)/blade/blade_rend_and_destroy.c	\
					$(ITEM_FOLD)/potion/use_potion.c	\
					$(ITEM_FOLD)/shield/shield.c	\
					$(ITEM_FOLD)/shield/shield_callbacks.c

CHEST_FOLD		=	game_objects/game_scene/chest
CHEST_FILES		=	$(CHEST_FOLD)/chest_loot.c

PAUSE_SCENE_FOLD	=	game_objects/pause_scene
PAUSE_SCENE_FILES	=	$(PAUSE_SCENE_FOLD)/pause_scene.c	\
						$(PAUSE_SCENE_FOLD)/pause_buttons.c	\
						$(PAUSE_SCENE_FOLD)/pause_background.c

GAME_OBJECTS	=	game_objects/find_object.c	\
					$(MENU_FILES)	\
					$(GAME_FILES)	\
					$(MAZE_FILES)	\
					$(SOUND_FILES)	\
					$(FIGHT_FILES)	\
					$(CLOCK_FILES)	\
					$(PLAYER_FILES)	\
					$(INVENTORY_FILES)	\
					$(ITEM_FILES)	\
					$(SHOP_FILES)	\
					$(PARTICLES_FILES)	\
					$(CHEST_FILES)	\
					$(HOW_TO_FILES)\
					$(BOSS_FILES)

SRC	=	my_rpg.c	\
		init_scenes.c	\
		$(RENDER_SRCS)	\
		$(DESTROY_SRCS)	\
		$(EVENT_SRCS)	\
		$(GAME_OBJECTS)	\
		$(PAUSE_SCENE_FILES)

OSRC	=	$(SRC:.c=.o)

SRC_TESTS	=	tests/tests.c

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

NAME	=	my_rpg

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
LFLAGS = $(addprefix -L. , $(TMPFLAGS)) -l csfml-graphics -l csfml-system -l csfml-audio -lm

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