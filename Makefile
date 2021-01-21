##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME = do_it

LIB = $(MAKE)	-s	-C	lib/my/

ANT = $(MAKE)	-s	-C	antman/

GIANT = $(MAKE)	-s	-C	giantman/

$(NAME):
		$(LIB)
		$(ANT)
		$(GIANT)

all:	$(NAME)

clean:
		@$(LIB)	clean
		@$(ANT)	clean
		@$(GIANT)	clean

fclean:	clean
		@$(LIB)	fclean
		@$(ANT)	fclean
		@$(GIANT)	fclean

re:	fclean all