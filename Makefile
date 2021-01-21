##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME = do_it

ANT = $(MAKE)	-s	-C	antman

GIANT = $(MAKE)	-s	-C	giantman

$(NAME):
		$(ANT)
		$(GIANT)

all:	$(NAME)

clean:
		@$(ANT)	clean
		@$(GIANT)	clean

fclean:	clean
		@$(ANT)	fclean
		@$(GIANT)	fclean

re:	fclean all