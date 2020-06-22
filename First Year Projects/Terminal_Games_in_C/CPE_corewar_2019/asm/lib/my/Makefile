##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## My lib makefile
##

# ========================= VAR ========================= #

NAME = my

SRC = my_math/swap.c \
	my_math/my_compute_factorial_it.c \
	my_math/my_compute_power_it.c \
	my_math/my_get_nbr.c \
	my_math/my_trigo.c \
	my_math/is_into.c \
	my_math/int_to_str.c \
	my_print/my_putstr_array.c \
	my_print/my_showstr.c \
	my_print/my_showmem.c \
	my_print/my_putchar.c \
	my_print/my_putstr.c \
	my_print/try_help.c \
	my_print/malloc_error.c \
	my_print/my_put_nbr.c \
	my_pos/pos_eq.c \
	my_str/my_str_count.c \
	my_str/my_strchr.c \
	my_str/my_strcmp.c \
	my_str/fill_of.c \
	my_str/my_str_contain.c \
	my_str/my_strlen.c \
	my_str/my_revstr.c \
	my_str/my_str_eq.c \
	my_str/my_strupcase.c \
	my_str/my_strncmp.c \
	my_str/my_strclone.c \
	my_str/my_strlowcase.c \
	my_str/my_strtok.c \
	my_str/my_strcat.c \
	my_str/my_2d_array.c \
	my_str/multi_free.c \
	my_str_is/my_str_isprintable.c \
	my_str_is/my_str_isint.c \
	my_str_is/my_str_islower.c \
	my_str_is/my_str_isupper.c \
	my_str_is/my_str_isnum.c \
	my_str_is/my_str_isalpha.c \
	my_file/read_file.c \
	my_file/write_file.c
$(eval SRC = $(addprefix src/, $(SRC)))

HNAME = my_math.h \
	my_print.h \
	my_str.h \
	my_str_is.h \
	my_macro.h \
	my_pos.h \
	my_file.h
$(eval HNAME = $(addprefix include/, $(HNAME)))

CFLAGS = -Wall -Wextra

IFLAGS = -I./include

OTHER_FLAGS =

# ======================================================= #

## echo
ECHO = echo -e

NO_COLOR = \x1b[0m
OK_COLOR = \x1b[32;01m
ERROR_COLOR = \x1b[31;01m
WARN_COLOR = \x1b[33;01m

OK_STRING = $(OK_COLOR)[✔]$(NO_COLOR)
ERROR_STRING = $(ERROR_COLOR)[X]$(NO_COLOR)
WARN_STRING = $(WARN_COLOR)[!]$(NO_COLOR)

## shell
CC = gcc -fdiagnostics-color=always
RM = rm -f

## lib vars
LIBNAME = lib$(NAME).a
LIB_DEST = ../$(LIBNAME)
H_DEST = ../../include/lib/$(NAME)/
HNAME_DEST = $(addprefix $(H_DEST), $(notdir $(HNAME)))

## obj
OBJ = $(SRC:.c=.o)

## build
BUILD_WARN_LOG = build_warn.log
BUILD_ERROR_LOG = build_error.log
LOGS = $(BUILD_WARN_LOG) $(BUILD_ERROR_LOG)

## rules
all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) $(OTHER_FLAGS) -c $< -o $@ 2> $(BUILD_WARN_LOG) || touch $(BUILD_ERROR_LOG)
	@$(MAKE) -s check_error

check_error:
	@if [ -e $(BUILD_ERROR_LOG) ] && [ -s $(BUILD_WARN_LOG) ]; then \
		$(ECHO) -n "$(ERROR_STRING) "; \
		cat $(BUILD_WARN_LOG); \
		$(RM) $(BUILD_ERROR_LOG); \
	elif [ -s $(BUILD_WARN_LOG) ]; then \
		$(ECHO) -n "$(WARN_STRING) "; \
		cat $(BUILD_WARN_LOG); \
	fi

put_libh:
	@mv $(LIBNAME) $(LIB_DEST)
	@mkdir -p $(H_DEST)
	@cp $(HNAME) $(H_DEST)

$(NAME): $(OBJ)
	@ar rc $(LIBNAME) $(OBJ) 2> $(BUILD_WARN_LOG) || touch $(BUILD_ERROR_LOG)
	@$(call print_build_status, $@)
	@$(MAKE) -s put_libh

clean:
	@$(RM) $(OBJ)
	@$(RM) $(LOGS)
	@$(ECHO) "$(OK_STRING) $(NAME) -> $@"

fclean:
	@$(MAKE) clean > /dev/null
	@$(RM) $(LIB_DEST) $(HNAME_DEST)
	@$(RM) -r $(H_DEST)
	@$(RM) $(NAME)
	@$(ECHO) "$(OK_STRING) $(NAME) -> $@"

re: fclean all

define print_build_status
	@if [ -e $(BUILD_ERROR_LOG) ] && [ -s $(BUILD_WARN_LOG) ]; then \
		$(ECHO) -n "$(ERROR_STRING) "; \
		cat $(BUILD_WARN_LOG); \
		$(ECHO) "$(ERROR_STRING) $(NAME) -> $1"; \
		$(RM) $(BUILD_ERROR_LOG); \
	elif [ -s $(BUILD_WARN_LOG) ]; then \
		$(ECHO) -n "$(WARN_STRING) "; \
		cat $(BUILD_WARN_LOG); \
		$(ECHO) "$(WARN_STRING) $(NAME) -> $1"; \
	else \
		$(ECHO) "$(OK_STRING) $(NAME) -> $1"; \
	fi
endef

.PHONY: $(NAME) all clean fclean re