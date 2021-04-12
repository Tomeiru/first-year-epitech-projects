##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME = do_it

GEN = $(MAKE)	-s	-C	generator/

SOL = $(MAKE)	-s	-C	solver/

$(NAME):
		$(GEN)
		$(SOL)

all:	$(NAME)

clean:
		@$(GEN)	clean
		@$(SOL)	clean

fclean:	clean
		@$(GEN)	fclean
		@$(SOL)	fclean

re:	fclean all
