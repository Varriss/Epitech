##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## My makefile
##

all:
	@(cd asm && make -s)
	@(cd corewar && make -s)

clean:
	@(cd asm && make clean -s)
	@(cd corewar && make clean -s)

fclean:
	@(cd asm && make fclean -s)
	@(cd corewar && make fclean -s)

re:
	@(cd asm && make re -s)
	@(cd corewar && make re -s)

tests_run:
	@(cd asm && make tests_run -s)
	@(cd corewar && make tests_run -s)

coverage:
	@(cd asm && make coverage -s)
	@(cd corewar && make coverage -s)
	gcovr --exclude asm/tests/ --exclude corewar/tests/

debug:
	@(cd asm && make debug -s)
	@(cd corewar && make debug -s)

.PHONY: $(NAME) all clean fclean re tests_run coverage debug