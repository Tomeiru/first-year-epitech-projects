##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME = do_it

ASM = $(MAKE)	-s	-C	asm/

COR = $(MAKE)	-s	-C	corewar/

$(NAME):
		$(ASM)
		$(COR)

all:	$(NAME)

debug:
		@$(ASM)	debug
		@$(COR)	debug

clean:
		@$(ASM)	clean
		@$(COR)	clean

fclean:	clean
		@$(ASM)	fclean
		@$(COR)	fclean

re:	fclean all
